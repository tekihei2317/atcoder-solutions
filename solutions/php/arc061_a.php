<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

$str = trim(fgets(STDIN));
$N = strlen($str);

$answer = 0;
for ($bit = 0; $bit < 2 ** ($N - 1); $bit++) {
  $current = 0;
  for ($i = 0; $i < $N - 1; $i++) {
    $current = $current * 10 + (int)$str[$i];
    if ($bit >> $i & 1) {
      $answer += $current;
      $current = 0;
    }
  }
  $current = $current * 10 + (int)$str[$N - 1];
  $answer += $current;
}
$printn($answer);
