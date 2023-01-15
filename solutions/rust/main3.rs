use proconio::input;

fn main() {
    input! {
        str: String
    }
    println!("{}", str.chars().filter(|c| *c == '1').count());
}
