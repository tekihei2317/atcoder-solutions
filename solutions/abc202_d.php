<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$A, $B, $K] = $integers();

$combination = makeCombination(60);
[$ng, $ok] = [0, (2 ** ($A + $B)) - 1];

while ($ok - $ng > 1) {
  $mid = intdiv($ok + $ng, 2);
  if (countLessThan($mid + 1, $A + $B, $B) >= $K) $ok = $mid;
  else $ng = $mid;
}

$answer = convertToString($ok, $A + $B);
$printn($answer);

function makeCombination($N)
{
  $comb = array_fill(0, $N + 1, []);
  $comb[0][0] = 1;
  for ($i = 1; $i <= $N; $i++) for ($j = 0; $j <= $i; $j++) {
    if ($j === 0 || $j === $i) $comb[$i][$j] = 1;
    else $comb[$i][$j] = $comb[$i - 1][$j - 1] + $comb[$i - 1][$j];
  }
  return $comb;
}

function countLessThan($num, $len, $bitCount)
{
  global $combination;

  $res = 0;
  $needBitCount = $bitCount;
  for ($i = $len - 1; $i >= 0; $i--) {
    if ($num >> $i & 1) {
      if ($needBitCount < 0 || $i < $needBitCount) break;
      $res += $combination[$i][$needBitCount];
      $needBitCount--;
    }
  }
  return $res;
}

function convertToString($num, $len)
{
  $str = '';
  for ($i = 0; $i < $len; $i++) {
    $str .= ($num >> $i & 1) ? 'b' : 'a';
  }
  return strrev($str);
}
