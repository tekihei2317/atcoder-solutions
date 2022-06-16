stdin.ReadLine()

stdin.ReadLine().Split()
|> Array.map int
|> Array.sortDescending
|> Array.mapi (fun index value -> if index % 2 = 0 then value else -value)
|> Array.sum
|> stdout.WriteLine
