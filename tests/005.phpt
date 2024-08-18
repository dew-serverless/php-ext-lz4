--TEST--
lz4compress() Basic test
--EXTENSIONS--
lz4
--FILE--
<?php
var_dump(is_string(lz4compress('aaaaaaaaaaaaaaaaaaaaaaaaaaa')));
?>
--EXPECT--
bool(true)
