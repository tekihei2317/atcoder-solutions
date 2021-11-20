import * as fs from 'fs'

const input = fs.readFileSync('/dev/stdin', 'utf-8').trim()

const check = (points: number[][]) => {
  let [cx, cy, ct] = [0, 0, 0]

  for (const [nt, nx, ny] of points) {
    const distance = Math.abs(cx - nx) + Math.abs(cy - ny)
    const canVisit = distance <= nt - ct && distance % 2 === (nt - ct) % 2
    if (!canVisit) {
      return false
    }

    ;[cx, cy, ct] = [nx, ny, nt]
  }

  return true
}

const points = input
  .split('\n')
  .slice(1)
  .map((str) => str.split(' ').map(Number))

console.log(check(points) ? 'Yes' : 'No')
