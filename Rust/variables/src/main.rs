fn main() {
    let x = 5;

    let x = x + 1;

    let x = x + 5;

    println!("The value of x is {}", x);

    let spaces = "   ";
    let spaces = spaces.len();

    // let mut spaces = "   "
    // spaces = spaces.len() <-- Error

    println!("The value of space is {}", spaces);

    let tup:(i32, f64, u8) = (500, 6.4, 1);

    let (x, y, z) = tup;

    println!("The value of x,y,z is {}, {}, {}", x,y,z);

}
