<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));

/**
 * 解法
 * 
 * ・Nの桁数をLとすると、条件を満たすものの前半部分の桁数は高々L/2
 * ・前半部分を全探索する。1~10^(L/2)までを調べればよい。
 * ・L<=12より、10^6回程度の計算なので間に合う
 */

$N = trim(fgets(STDIN));
$L = strlen($N);

$answer = 0;
for ($i = 1; $i < 10 ** ($L / 2); $i++) {
    $candidate = (string)$i . (string)$i;
    if ((int)$candidate <= (int)$N) $answer++;
}
echo $answer . "\n";
