/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: c3c36bb8d703c74567fea30e200803694abf7e3d */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_lz4compress, 0, 1, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, level, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_lz4uncompress, 0, 1, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, max_length, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()


ZEND_FUNCTION(lz4compress);
ZEND_FUNCTION(lz4uncompress);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(lz4compress, arginfo_lz4compress)
	ZEND_FE(lz4uncompress, arginfo_lz4uncompress)
	ZEND_FE_END
};

static void register_lz4_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("LZ4_VERSION_NUMBER", LZ4_VERSION_NUMBER, CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("LZ4_VERSION_STRING", LZ4_VERSION_STRING, CONST_PERSISTENT);
}
