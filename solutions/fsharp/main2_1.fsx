stdin.ReadLine()
|> Seq.filter ((=) '1')
|> Seq.length
|> stdout.WriteLine
