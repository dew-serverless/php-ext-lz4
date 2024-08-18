--TEST--
phpinfo() Lz4 information
--EXTENSIONS--
lz4
--FILE--
<?php
phpinfo(INFO_MODULES);
?>
--EXPECTF--
%a
lz4

lz4 support => enabled
lz4 version => %s
%a
