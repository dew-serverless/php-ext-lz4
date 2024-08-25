--TEST--
register constants
--EXTENSIONS--
lz4
--FILE--
<?php
echo LZ4_VERSION_NUMBER.PHP_EOL;
echo LZ4_VERSION_STRING.PHP_EOL;
?>
--EXPECTF--
%d
%d.%d.%d
