<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$N] = $integers();

const INF = 2 * 10 ** 9;
// balls[i]:=色がiのボールの座標の最小値と最大値
$balls = [];

$balls[0] = [0, 0];
for ($i = 0; $i < $N; $i++) {
  [$x, $c] = $integers();
  if (!isset($balls[$c])) $balls[$c] = [INF, -INF];
  $balls[$c][0] = min($balls[$c][0], $x);
  $balls[$c][1] = max($balls[$c][1], $x);
}
$balls[$N + 1] = [0, 0];

// 添字を振り直す
ksort($balls);
$balls = array_values($balls);

$size = count($balls);
const LINF = 10 ** 18;
$dp = array_fill(0, $size, [LINF, LINF]);
$dp[0] = [0, 0];

for ($i = 0; $i < $size - 1; $i++) for ($j = 0; $j < 2; $j++) {
  for ($k = 0; $k < 2; $k++) {
    $cost = calcCost($balls[$i][$j], $balls[$i + 1][$k ^ 1], $balls[$i + 1][$k]);
    $dp[$i + 1][$k] = min($dp[$i + 1][$k], $dp[$i][$j] + $cost);
  }
}
$printn($dp[$size - 1][0]);

function calcCost(int $x1, int $x2, int $x3)
{
  return abs($x1 - $x2) + abs($x2 - $x3);
}
