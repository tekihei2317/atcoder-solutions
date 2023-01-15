use proconio::input;

fn count(n: u32) -> u32 {
    if n % 2 != 0 {
        return 0;
    }
    return 1 + count(n / 2);
}

fn main() {
    input! {
        n: u32,
        a: [u32; n],
    }

    let answer = a.iter().map(|v| count(*v)).min().unwrap();
    println!("{}", answer);
}
