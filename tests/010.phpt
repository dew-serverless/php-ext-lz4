--TEST--
lz4uncompress() empty string
--EXTENSIONS--
lz4
--FILE--
<?php
var_dump(lz4uncompress(''));
var_dump(lz4uncompress('', 0));
var_dump(lz4uncompress('', 1));
?>
--EXPECTF--
string(0) ""
string(0) ""
string(0) ""
