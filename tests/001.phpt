--TEST--
Check if lz4 is loaded
--EXTENSIONS--
lz4
--FILE--
<?php
echo 'The extension "lz4" is available';
?>
--EXPECT--
The extension "lz4" is available
