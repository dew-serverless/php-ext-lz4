/* lz4 extension for PHP */

#ifndef PHP_LZ4_H
#define PHP_LZ4_H

#include <lz4.h>
#include <lz4hc.h>

#define PHP_LZ4_VERSION "0.1.0"

#define PHP_LZ4_OK 0
#define PHP_LZ4_MEM_ERROR -1
#define PHP_LZ4_BUF_ERROR -2

# if defined(ZTS) && defined(COMPILE_DL_LZ4)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

extern zend_module_entry lz4_module_entry;
# define phpext_lz4_ptr &lz4_module_entry

#endif	/* PHP_LZ4_H */
