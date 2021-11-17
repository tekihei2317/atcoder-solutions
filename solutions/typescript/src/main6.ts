import * as fs from 'fs'

const [n, a, b] = fs.readFileSync('/dev/stdin', 'utf-8').split(' ').map(Number)

const check = (k: Number) => {
  const digitSum = k
    .toString()
    .split('')
    .map(Number)
    .reduce((sum, i) => sum + i)

  return a <= digitSum && digitSum <= b
}

let answer = 0
for (let i = 1; i <= n; i++) {
  if (check(i)) {
    answer += i
  }
}
console.log(answer)
