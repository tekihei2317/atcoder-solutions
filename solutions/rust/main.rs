fn read1<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    // Resultはハンドリングしないとwarningになるため、Optionに変換しているっぽい
    std::io::stdin().read_line(&mut s).ok();
    // okを呼び出さずにunwarpするとエラーになったが、よく分からなかった
    s.trim().parse().ok().unwrap()
}

fn readn<T: std::str::FromStr>(delimiter: &str) -> Vec<T> {
    let s = read1::<String>();
    // splitするとイテレータになるので、collectでVectorにしているっぽい
    s.split(delimiter).map(|e| e.parse().ok().unwrap()).collect::<Vec<T>>()
}

fn main() {
    let a = read1::<u32>();
    let bc = readn::<u32>(" ");
    let [b, c] = [bc[0], bc[1]];
    let s = read1::<String>();

    println!("{} {}", a + b + c, s);
}