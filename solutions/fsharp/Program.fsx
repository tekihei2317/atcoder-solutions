// For more information see https://aka.ms/fsharp-console-apps
let greeting name = sprintf "Hello, %s!!" name
let names = [ "alice"; "bob"; "carol" ]

names
|> List.map greeting
|> List.iter (fun str -> printfn "%s" str)
