/* lz4 extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_lz4.h"
#include "lz4_arginfo.h"

#include <lz4.h>
#include <lz4hc.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

typedef int (*compress_func_t)(const char*, char*, int, int, int);

static char* lz4_compress(const char *in, const size_t in_len, int *out_len,
						const compress_func_t compress_func,
						const int level)
{
	const int out_max = LZ4_compressBound(in_len);
	if (out_max <= 0) {
		return NULL;
	}

	char *out = emalloc(out_max);
	*out_len = compress_func(in, out, (int)in_len, out_max, level);

	if (*out_len == 0) {
		efree(out);
		return NULL;
	}

	return out;
}

static char* lz4_compress_fast(const char *in, const size_t in_len,
							size_t *out_len_ptr)
{
	int out_len;

	char* out = lz4_compress(in, in_len, &out_len,
		(compress_func_t)LZ4_compress_default, 0);
	if (out != NULL) {
		*out_len_ptr = (size_t)out_len;
	}

	return out;
}

static char* lz4_compress_hc(const char *in, const size_t in_len,
							size_t *out_len_ptr, const int level)
{
	int out_len;

	char* out = lz4_compress(in, in_len, &out_len, LZ4_compress_HC, level);
	if (out != NULL) {
		*out_len_ptr = out_len;
	}

	return out;
}

static int lz4_uncompress(const char *in, const size_t in_len,
						char **out, size_t *out_len,
						const size_t max_len)
{
	*out = emalloc(max_len);
	if (*out == NULL) {
		php_error_docref(NULL, E_WARNING, "could not allocate memory");
		return FAILURE;
	}

	const int dst_len = LZ4_decompress_safe(in, *out, in_len, max_len);
	if (dst_len < 0) {
		efree(*out);
		php_error_docref(NULL, E_WARNING, "could not uncompress the data");
		return FAILURE;
	}

	*out_len = dst_len;
	return SUCCESS;
}

/* {{{ string|false lz4compress(string $data, [int $level]) */
PHP_FUNCTION(lz4compress)
{
	char *in, *out = NULL;
	size_t in_len, out_len;
	zend_long level = 0;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STRING(in, in_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();

	out = level == 0
		? lz4_compress_fast(in, in_len, &out_len)
		: lz4_compress_hc(in, in_len, &out_len, level);

	if (out_len == 0) {
		efree(out);
		php_error_docref(NULL, E_WARNING, "lz4 compression failed");
		RETURN_FALSE;
	}

	RETVAL_STRINGL(out, out_len);
	efree(out);
}
/* }}}*/

/* {{{ string|false lz4uncompress(string $data, int $maxLength) */
PHP_FUNCTION(lz4uncompress)
{
	char *in, *out = NULL;
	size_t in_len, out_len = 0;
	zend_long max_len = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(in, in_len)
		Z_PARAM_LONG(max_len)
	ZEND_PARSE_PARAMETERS_END();

	if (in_len == 0) {
		RETURN_EMPTY_STRING();
	}

	if (max_len < 0) {
		php_error_docref(NULL, E_WARNING, "max_length must be non-negative");
		RETURN_FALSE;
	}

	const int status = lz4_uncompress(in, in_len, &out, &out_len, max_len);

	if (status == FAILURE) {
		RETURN_FALSE;
	}

	RETVAL_STRINGL(out, out_len);
	efree(out);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(lz4)
{
#if defined(ZTS) && defined(COMPILE_DL_LZ4)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(lz4)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "lz4 support", "enabled");
	php_info_print_table_row(2, "lz4 version", LZ4_versionString());
	php_info_print_table_end();
}
/* }}} */

/* {{{ lz4_module_entry */
zend_module_entry lz4_module_entry = {
	STANDARD_MODULE_HEADER,
	"lz4",					/* Extension name */
	ext_functions,			/* zend_function_entry */
	NULL,					/* PHP_MINIT - Module initialization */
	NULL,					/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(lz4),			/* PHP_RINIT - Request initialization */
	NULL,					/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(lz4),			/* PHP_MINFO - Module info */
	PHP_LZ4_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LZ4
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(lz4)
#endif
