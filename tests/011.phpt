--TEST--
lz4uncompress() uncompressed string is empty string
--EXTENSIONS--
lz4
--FILE--
<?php
var_dump(lz4uncompress(lz4compress('')));
var_dump(lz4uncompress(lz4compress(''), 0));
var_dump(lz4uncompress(lz4compress(''), 1));
?>
--EXPECTF--
string(0) ""
string(0) ""
string(0) ""
