<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$N] = $integers();

$rec = function ($currentNum) use (&$rec, $N) {
  $res = 0;
  if (count(array_count_values(str_split((string)$currentNum))) === 3) $res++;

  foreach ([3, 5, 7] as $digit) {
    $nextNum = $currentNum * 10 + $digit;
    if ($nextNum <= $N) $res += $rec($nextNum);
  }
  return $res;
};

$printn($rec(0));
