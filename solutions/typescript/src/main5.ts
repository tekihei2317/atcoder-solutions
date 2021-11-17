import * as fs from 'fs'

const [a, b, c, x] = fs.readFileSync('/dev/stdin', 'utf-8').split('\n').map(Number)

let answer = 0
for (let i = 0; i <= a; i++) {
  for (let j = 0; j <= b; j++) {
    for (let k = 0; k <= c; k++) {
      if (500 * i + 100 * j + 50 * k === x) {
        answer++
      }
    }
  }
}
console.log(answer)
