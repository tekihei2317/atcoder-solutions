import * as fs from 'fs'

const debug = (value: any) => {
  console.log(JSON.stringify(value))
}

const s = fs.readFileSync('/dev/stdin', 'utf-8')
const answer = s
  .trim()
  .split('')
  .filter((char: string) => char === '1').length
console.log(answer)
