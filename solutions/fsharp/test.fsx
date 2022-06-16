let array = [| 3; 1; 4; 1 |]

array
|> Array.fold (fun sum value -> sum + value) 0
|> stdout.WriteLine
