import * as fs from 'fs'

const inputs = fs.readFileSync('/dev/stdin', 'utf-8')
const a = inputs
  .split('\n')[1]
  .trim()
  .split(' ')
  .map((i) => Number(i))

const answer = Math.min(
  ...a.map((i) => {
    let count = 0
    while (i % 2 === 0) {
      count++
      i /= 2
    }
    return count
  })
)
console.log(answer)
