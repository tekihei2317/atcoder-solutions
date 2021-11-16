const fs = require('fs')

const main = (arg: String) => {
  const input = arg.split('\n')

  const a = Number(input[0])
  const b = Number(input[1].split(' ')[0])
  const c = Number(input[1].split(' ')[1])
  const s = input[2]

  console.log(`${a + b + c} ${s}`)
}

main(fs.readFileSync('/dev/stdin', 'utf-8'))
