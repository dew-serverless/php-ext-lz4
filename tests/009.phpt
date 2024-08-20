--TEST--
lz4uncompress() Error when max length is less than necessarily
--EXTENSIONS--
lz4
--FILE--
<?php
$data = 'aaaaaaaaaaaaaaaaaaaaaaaaaaa';
$length = strlen($data);
var_dump(lz4uncompress(lz4compress($data), $length - 1));
?>
--EXPECTF--
Warning: lz4uncompress(): could not uncompress the data in %a
bool(false)
