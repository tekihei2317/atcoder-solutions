use proconio::input;

fn digit_sum(num: u32) -> u32 {
    if num == 0 {
        return 0;
    }

    return num % 10 + digit_sum(num / 10);
}

fn main() {
    input! {
        n: u32,
        a: u32,
        b: u32,
    }

    let answer = (1..=n).filter(|i| a <= digit_sum(*i) && digit_sum(*i) <= b).sum::<u32>();
    println!("{}", answer);
}
