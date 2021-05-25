<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

class Condition
{
  public $num_limit;
  public $cnt_limit;

  public function __construct(int $num, int $cnt)
  {
    $this->num_limit = $num;
    $this->cnt_limit = $cnt;
  }
}

[$N, $M] = $integers();
$conditions = array_fill(1, $N, []);

for ($i = 0; $i < $M; $i++) {
  [$idx, $num, $cnt] = $integers();
  // $conditions[$idx][] = new Condition($num, $cnt);
  $conditions[$idx][] = [$num, $cnt];
}

$dp = array_fill(0, 2 ** $N, 0);
$dp[0] = 1;

for ($bit = 0; $bit < 2 ** $N - 1; $bit++) {
  $i = gmp_popcount($bit);
  for ($j = 0; $j < $N; $j++) if (~$bit >> $j & 1) {
    $ok = true;
    foreach ($conditions[$i + 1] as $condition) $ok = $ok && check($bit | (1 << $j), $condition);
    if ($ok) $dp[$bit | (1 << $j)] += $dp[$bit];
  }
}

function check(int $bit, array $condition)
{
  $targetBits = $bit & ((1 << $condition[0]) - 1);
  $count = gmp_popcount($targetBits);
  return $count <= $condition[1];
}

// function popcount(int $num)
// {
//   $cnt = 0;
//   while ($num > 0) {
//     $cnt += $num & 1;
//     $num >>= 1;
//   }
//   return $cnt;
// }

$printn($dp[(1 << $N) - 1]);
