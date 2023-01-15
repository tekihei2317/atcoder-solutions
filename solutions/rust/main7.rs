use proconio::input;

fn main() {
    input! {
        n: u32,
        mut a: [u32; n],
    }

    a.sort();
    a.reverse();

    let mut answer = 0;
    for (index, value) in a.iter().enumerate() {
        if index % 2 == 0 {
            answer += value;
        } else {
            answer -= value;
        }
    }
    println!("{}", answer);
}
