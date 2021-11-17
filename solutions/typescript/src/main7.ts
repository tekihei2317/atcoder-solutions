import * as fs from 'fs'

const inputs = fs.readFileSync('/dev/stdin', 'utf-8')
const a = inputs.split('\n')[1].split(' ').map(Number)

a.sort((l, r) => r - l)

let answer = a.reduce((sum, current, index) => {
  return sum + (index % 2 === 0 ? current : -current)
}, 0)
console.log(answer)
