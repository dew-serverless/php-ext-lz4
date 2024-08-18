/* lz4 extension for PHP */

#ifndef PHP_LZ4_H
# define PHP_LZ4_H

extern zend_module_entry lz4_module_entry;
# define phpext_lz4_ptr &lz4_module_entry

# define PHP_LZ4_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_LZ4)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_LZ4_H */
