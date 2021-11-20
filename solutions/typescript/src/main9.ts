import * as fs from 'fs'

const input = fs.readFileSync('/dev/stdin', 'utf-8')
const [n, y] = input.trim().split(' ').map(Number)

const solve = (n: number, sum: number) => {
  for (let i = 0; i <= n; i++) {
    for (let j = 0; i + j <= n; j++) {
      const k = n - (i + j)

      if (10000 * i + 5000 * j + 1000 * k === sum) {
        return [i, j, k]
      }
    }
  }
  return [-1, -1, -1]
}

console.log(solve(n, y).join(' '))
