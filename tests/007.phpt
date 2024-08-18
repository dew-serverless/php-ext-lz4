--TEST--
lz4uncompress() Uncompress the lz4compress() result
--EXTENSIONS--
lz4
--FILE--
<?php
$data = 'aaaaaaaaaaaaaaaaaaaaaaaaaaa';
var_dump(lz4uncompress(lz4compress($data)) === $data);
var_dump(lz4uncompress(lz4compress($data, 9)) === $data);
?>
--EXPECT--
bool(true)
bool(true)
