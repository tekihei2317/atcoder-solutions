<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

[$H, $W] = $integers();
$board = [];
for ($i = 0; $i < $H; $i++) {
  $board[] = trim(fgets(STDIN));
}

$dp = array_fill(0, $H, []);

function rec($i, $j)
{
  global $H, $W, $board, $dp;

  if (isset($dp[$i][$j])) return $dp[$i][$j];
  if ($i === $H - 1 && $j === $W - 1) return 0;

  $player = ($i + $j) % 2;
  $res = 0;
  if ($player === 0) {
    $res = -100000;
    if ($i + 1 < $H) $res = max($res, rec($i + 1, $j) + ($board[$i + 1][$j] === '+' ? 1 : -1));
    if ($j + 1 < $W) $res = max($res, rec($i, $j + 1) + ($board[$i][$j + 1] === '+' ? 1 : -1));
  } else {
    $res = 100000;
    if ($i + 1 < $H) $res = min($res, rec($i + 1, $j) + ($board[$i + 1][$j] === '+' ? -1 : 1));
    if ($j + 1 < $W) $res = min($res, rec($i, $j + 1) + ($board[$i][$j + 1] === '+' ? -1 : 1));
  }
  return $dp[$i][$j] = $res;
}

$score = rec(0, 0);
$answer = '';
if ($score > 0) $answer = 'Takahashi';
else if ($score < 0) $answer = 'Aoki';
else $answer = 'Draw';
$printn($answer);
