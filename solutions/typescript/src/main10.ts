import * as fs from 'fs'

const solve = (s: string) => {
  return s.match(/^(dream|dreamer|erase|eraser)*$/)
}

const s = fs.readFileSync('/dev/stdin', 'utf-8').trim()
console.log(solve(s) ? 'YES' : 'NO')
