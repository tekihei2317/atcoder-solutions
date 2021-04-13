<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

/**
 * 解法
 * 
 * ・余りはK種類しかなく、周期的なので、K+1項目以降は見なくてよい
 */

$answer = -1;
$rem = 0;
for ($i = 0; $i < $K; $i++) {
    $rem = ($rem * 10 + 7) % $K;
    if ($rem === 0) {
        $answer = $i + 1;
        break;
    }
}
$printn($answer);
