stdin.ReadLine()
|> Seq.fold (fun count c -> if c = '1' then count + 1 else count) 0
|> stdout.WriteLine
