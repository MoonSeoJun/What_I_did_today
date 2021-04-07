enum  IpAddKind {
    V4,
    V6,
}

enum Coin{
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

fn main() {
    let four = IpAddKind::V4;
    
    let five = Some(5);
    let six = plus_one(five);
    let none = plus_one(None);

}
