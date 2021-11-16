import * as fs from 'fs'

const main = (args: string) => {
  const [a, b] = args.split(' ').map((i) => Number(i))
  const answer = (a * b) % 2 === 0 ? 'Even' : 'Odd'
  console.log(answer)
}

main(fs.readFileSync('/dev/stdin', 'utf-8'))
