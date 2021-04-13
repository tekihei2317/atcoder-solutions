<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

/**
 * 解法
 * 
 * ・現在の項の余りは (前の項の余り*10+7) mod K で求まる
 * 　→周期的になるので、同じ値が出たらそれ以降は見なくてもよい
 * ・鳩の巣原理より、ループは高々K回しか実行されないので、計算量はO(K)
 */

[$K] = $integers();

$exists = array_fill(0, $K, false);
$rem = 0;
$answer = -1;
for ($i = 0;; $i++) {
    $rem = ($rem * 10 + 7) % $K;
    if ($exists[$rem]) break;

    if ($rem === 0) {
        $answer = $i + 1;
        break;
    }
    $exists[$rem] = true;
}
$printn($answer);
