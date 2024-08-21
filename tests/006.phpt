--TEST--
lz4compress() HC test
--EXTENSIONS--
lz4
--FILE--
<?php
var_dump(is_string(lz4compress('aaaaaaaaaaaaaaaaaaaaaaaaaaa', 9)));
?>
--EXPECT--
bool(true)
