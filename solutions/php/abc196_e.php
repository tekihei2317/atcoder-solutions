<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$N] = $integers();
const INF = 10 ** 18;
[$k, $l, $r] = [0, -INF, INF];

for ($i = 0; $i < $N; $i++) {
  [$a, $t] = $integers();
  if ($t === 1) {
    $k += $a;
    $l += $a;
    $r += $a;
  } else if ($t === 2) {
    $l = max($l, $a);
    $r = max($r, $a);
  } else {
    $r = min($r, $a);
    $l = min($l, $a);
  }
}

[$Q] = $integers();
$queries = $integers();
foreach ($queries as $value) {
  $result = min(max($value + $k, $l), $r);
  $printn($result);
}
