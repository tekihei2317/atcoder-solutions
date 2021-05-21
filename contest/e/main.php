<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

$xorDepth = [];

[$N] = $integers();
$graph = array_fill(0, $N, []);

for ($i = 0; $i < $N - 1; $i++) {
  [$u, $v, $w] = $integers();
  $u--;
  $v--;
  $graph[$u][] = [$v, $w];
  $graph[$v][] = [$u, $w];
}

$xorDepth = array_fill(0, $N, 0);
dfs(0, -1);
// print_r($xorDepth);

function dfs($current, $parent)
{
  global $graph, $xorDepth;

  foreach ($graph[$current] as [$child, $weight]) {
    if ($child === $parent) continue;
    $xorDepth[$child] = $xorDepth[$current] ^ $weight;
    dfs($child, $current);
  }
}

// i番目のビットが立っている数の個数
$counts = array_fill(0, 60, 0);
$answer = 0;
const MOD = 1e9 + 7;
foreach ($xorDepth as $index => $value) {
  for ($i = 0; $i < 60; $i++) {
    $count = 0;
    if ($value >> $i & 1) {
      $count = $index - $counts[$i];
      $counts[$i]++;
    } else {
      $count = $counts[$i];
    }
    $answer += (1 << $i) % MOD * $count % MOD;
    $answer %= MOD;
  }
}
$printn($answer);
