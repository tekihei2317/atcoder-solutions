<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$N, $K] = $integers();

$dp = array_fill(0, 4, array_fill(0, 3 * $N + 2, 0));
$dp[0][0] = 1;
for ($i = 0; $i < 3; $i++) {
  for ($j = 0; $j <= $N * $i; $j++) {
    $dp[$i + 1][$j + 1] += $dp[$i][$j];
    $dp[$i + 1][$j + $N + 1] -= $dp[$i][$j];
  }
  for ($j = 0; $j <= $N * ($i + 1); $j++) {
    $dp[$i + 1][$j + 1] += $dp[$i + 1][$j];
  }
}

// 合計を求める
$sum = -1;
for ($i = 3; $i <= 3 * $N; $i++) {
  if ($K <= $dp[3][$i]) {
    $sum = $i;
    break;
  }
  $K -= $dp[3][$i];
}

// 最初の数を決め打つ
$a = $b = $c = -1;
for ($i = 1; $i <= $N; $i++) {
  if ($K <= $dp[2][$sum - $i]) {
    $a = $i;
    $minB = max(1, $sum - $a - $N);
    $b = $minB + $K - 1;
    $c = $sum - ($a + $b);
    break;
  }
  $K -= $dp[2][$sum - $i];
}

$printn(implode(" ", [$a, $b, $c]));
