<?php

declare(strict_types=1);

$integers = fn () => array_map('intval', explode(' ', fgets(STDIN)));
$printn = fn ($value) => print($value . "\n");

class Permutation
{
  private $permutations = [];
  private $used = [];

  public function __construct(int $n = 10, int $r)
  {
    $this->used = array_fill(0, 10, false);
    $this->make($n, $r, 0, []);
  }

  public function get()
  {
    return $this->permutations;
  }

  private function make(int $n, int $r, $index, $current)
  {
    if ($index === $r) {
      $this->permutations[] = $current;
      return;
    }

    for ($i = 0; $i < 10; $i++) if (!$this->used[$i]) {
      $this->used[$i] = true;
      $temp = $current;
      $temp[] = $i;
      $this->make($n, $r, $index + 1, $temp);
      $this->used[$i] = false;
    }
  }
}

$strs = [];
$chars = [];
for ($i = 0; $i < 3; $i++) {
  $strs[$i] = trim(fgets(STDIN));
  foreach (str_split($strs[$i]) as $c) $chars[] = $c;
}

# array_uniqueは非破壊的。最初の要素が残るので、インデックスが飛ぶこともある
$chars = array_unique($chars);
# sortすれば飛んだインデックスは戻る
sort($chars);

if (count($chars) > 10) {
  $printn("UNSOLVABLE");
  exit;
}

$permutations = (new Permutation(10, count($chars)))->get();
$answer = [];
foreach ($permutations as $perm) {
  $map = [];
  for ($i = 0; $i < count($chars); $i++) {
    $map[$chars[$i]] = $perm[$i];
  }

  // 先頭のゼロはNG
  if ($map[$strs[0][0]] === 0 || $map[$strs[1][0]] === 0 || $map[$strs[2][0]] === 0) continue;

  $numbers = [];
  foreach ($strs as $str) $numbers[] = convert($str, $map);
  // 足し算が一致しなければNG
  if ($numbers[0] + $numbers[1] !== $numbers[2]) continue;

  $answers = $numbers;
  break;
}

if (count($answers) === 0) {
  $printn("UNSOLVABLE");
} else {
  $printn(implode("\n", $answers));
}

function convert($str, $map)
{
  $number = 0;
  foreach (str_split($str) as $c) $number = $number * 10 + $map[$c];
  return $number;
}
