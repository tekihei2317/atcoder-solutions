use proconio::input;

fn main() {
    input! {
        a: u32,
        b: u32,
    }

    let answer = if a * b % 2 == 1 {
        "Odd"
    } else {
        "Even"
    };
    println!("{}", answer);
}
