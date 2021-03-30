<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));

/**
 * 解法
 * 
 * 隙間を区切るかどうかを全探索する
 */

[$N] = $integers();
$a = $integers();

$answer = 2 ** 30;
for ($set = 0; $set < (1 << ($N - 1)); $set++) {
    $separators = [0];
    for ($i = 0; $i < $N - 1; $i++) {
        if ($set >> $i & 1) {
            $separators[] = $i + 1;
        }
    }
    $separators[] = $N;

    $xor = 0;
    for ($i = 0; $i < count($separators) - 1; $i++) {
        $left = $separators[$i];
        $right = $separators[$i + 1];
        $or = 0;
        for ($j = $left; $j < $right; $j++) $or |= $a[$j];
        $xor ^= $or;
    }
    $answer = min($answer, $xor);
}
echo $answer . "\n";
