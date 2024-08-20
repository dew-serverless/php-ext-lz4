--TEST--
lz4uncompress() Uncompress with more than necessarily
--EXTENSIONS--
lz4
--FILE--
<?php
$data = 'aaaaaaaaaaaaaaaaaaaaaaaaaaa';
$length = strlen($data);
var_dump(lz4uncompress(lz4compress($data), $length + 1) === $data);
?>
--EXPECT--
bool(true)
