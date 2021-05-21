<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

$s = trim(fgets(STDIN));

$answer = 0;
for ($i = 0; $i < 10000; $i++) {
  $counts = array_fill(0, 10, 0);
  $num = $i;
  for ($j = 0; $j < 4; $j++) {
    $counts[$num % 10]++;
    $num = intdiv($num, 10);
  }

  $ok = true;
  for ($j = 0; $j < 10; $j++) {
    if ($s[$j] === 'o' && $counts[$j] === 0) $ok = false;
    if ($s[$j] === 'x' && $counts[$j] > 0) $ok = false;
  }
  if ($ok) $answer++;
}
$printn($answer);
