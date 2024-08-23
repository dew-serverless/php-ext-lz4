# LZ4 PHP

[![CI](https://github.com/dew-serverless/php-ext-lz4/actions/workflows/ci.yml/badge.svg)](https://github.com/dew-serverless/php-ext-lz4/actions/workflows/ci.yml)

The PHP lz4 binding enables you to transparently read and write lz4
compressed data.

## Installation

### Requirements

The extension uses the functions of [lz4](https://github.com/lz4/lz4)
by Yann Collet. You have to use a lz4 version >= 1.9.2 with this extension.

### Installation

To enable the lz4 extension, you will need to clone the repository and
configure the extension **[--with-lz4[=DIR]]**.

```shell
phpize
./configure
make
make install
```

## Predefined Constants

The constants below are defined by this extension, and will only be available
when the extension has been dynamically loaded at runtime.

<dl>
    <dt>LZ4_VERSION (string)</dt>
    <dd>lz4 version number as a string.</dd>
    <dt>LZ4_VERNUM (int)</dt>
    <dd>lz4 version number as an int.</dd>
</dl>

## Examples

### Example #1 Lz4 fast compression and uncompression

```php
<?php

$data = "Test, test, test, test, test, test, test, test!\n";

$size = strlen($data);

$compressed = lz4compress($data);

printf("Data after compression: %s%%\n", ceil(strlen($compressed) / $size * 100));

echo lz4uncompress($compressed, $size);
```

The example will output:

```
Data after compression: 36%
Test, test, test, test, test, test, test, test!
```

## Lz4 Functions

### lz4compress

Compress a string.

#### Description

```php
lz4compress(string $data, int $level = 0): string|false
```

This function compress the given string using fast compression algorithm
by default.

#### Parameters

<dl>
    <dt>data</dt>
    <dd>The data to compress.</dd>
    <dt>level</dt>
    <dd>The level of compression.</dd>
    <dd>Can be given as 0 for fast compression, or 1 to 12 for high compression.</dd>
    <dd>The default is fast compression. Any level above 12 is treated as the maximum compression level.</dd>
</dl>

#### Return Values

The compressed string or [false](https://www.php.net/manual/en/reserved.constants.php#constant.false)
if an error occurred.

### lz4uncompress

Uncompress a compressed string.

#### Description

```php
lz4uncompress(string $data, int $maxLength): string|false
```

This function uncompress a compressed string.

#### Parameters

<dl>
    <dt>data</dt>
    <dd>The data compressed by <a href="#lz4compress">lz4compress()</a>.</dd>
    <dt>maxLength</dt>
    <dd>The maximum length of data to decode.</dd>
</dl>

#### Return Values

The original uncompressed data or [false](https://www.php.net/manual/en/reserved.constants.php#constant.false)
on error.

The function will return an error if the uncompressed data is more than
the parameter _maxLength_.

## License

This extension is licensed under the terms of [MIT](LICENSE.md).
