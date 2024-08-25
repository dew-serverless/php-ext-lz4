<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

 /**
  * @var int
  * @cvalue LZ4_VERSION_NUMBER
  */
 const LZ4_VERSION_NUMBER = UNKNOWN;

/**
 * @var string
 * @cvalue LZ4_VERSION_STRING
 */
const LZ4_VERSION_STRING = UNKNOWN;

function lz4compress(string $data, int $level = 0): string|false {}

function lz4uncompress(string $data, int $max_length = 0): string|false {}
