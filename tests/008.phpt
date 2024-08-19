--TEST--
lz4uncompress() Uncompress with max length
--EXTENSIONS--
lz4
--FILE--
<?php
$data = 'aaaaaaaaaaaaaaaaaaaaaaaaaaa';
$length = strlen($data);
var_dump(lz4uncompress(lz4compress($data), $length) === $data);
?>
--EXPECT--
bool(true)
