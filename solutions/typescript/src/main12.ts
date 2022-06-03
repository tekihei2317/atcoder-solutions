import * as fs from 'fs'

const [a, b] = fs.readFileSync('/dev/stdin', 'utf-8').split(' ').map(Number)
console.log((a * b) % 2 === 0 ? 'Even' : 'Odd')
