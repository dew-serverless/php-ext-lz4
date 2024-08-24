--TEST--
lz4uncompress() uncompress without the original size
--EXTENSIONS--
lz4
--FILE--
<?php
var_dump(lz4uncompress(lz4compress('abc')));
?>
--EXPECT--
string(3) "abc"
