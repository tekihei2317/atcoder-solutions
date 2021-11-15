<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$K, $S] = $integers();
$answer = 0;
for ($x = 0; $x <= $K; $x++) for ($y = 0; $y <= $K; $y++) {
  $z = $S - ($x + $y);
  if (0 <= $z && $z <= $K) $answer++;
}
$printn($answer);
