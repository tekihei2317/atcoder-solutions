<?php

declare(strict_types=1);

class Combination
{
  private $comb;
  private $size;

  public function __construct(int $size = 64)
  {
    $this->size = $size;
    $this->comb = array_fill(0, $this->size + 1, []);
    for ($i = 0; $i <= $this->size; $i++) for ($j = 0; $j <= $i; $j++) {
      if ($j === 0 || $j === $i) $this->comb[$i][$j] = 1;
      else $this->comb[$i][$j] = $this->comb[$i - 1][$j - 1] + $this->comb[$i - 1][$j];
    }
  }

  public function get(int $n, int $k)
  {
    if ($k < 0 || $k > $n) return 0;
    return $this->comb[$n][$k];
  }
}
