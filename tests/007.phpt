--TEST--
lz4uncompress() Uncompress the lz4compress() result
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
