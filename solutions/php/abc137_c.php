<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$N] = $integers();

$counts = [];
$answer = 0;

for ($i = 0; $i < $N; $i++) {
  $str = trim(fgets(STDIN));
  $str = alphabet_sort($str);

  $answer += ($counts[$str] ?? 0);
  $counts[$str] = ($counts[$str] ?? 0) + 1;
}
$printn($answer);

function alphabet_sort($str)
{
  $chars = str_split($str);
  sort($chars);
  return implode('', $chars);
}
