import * as fs from 'fs'

const [_, ...d] = fs.readFileSync('/dev/stdin', 'utf-8').trim().split('\n').map(Number)
console.log(new Set(d).size)
