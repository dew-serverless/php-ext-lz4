--TEST--
lz4uncompress() error when max length is a negative number
--EXTENSIONS--
lz4
--FILE--
<?php
var_dump(lz4uncompress(lz4compress('abc'), -1));
?>
--EXPECTF--
Warning: lz4uncompress(): max_length must be non-negative %a
bool(false)
