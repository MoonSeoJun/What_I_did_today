fn main() {
    let x = five();
    
    println!("The value of x is {}", x);

    another_function(5, 6);
}

fn another_function(x:i32, y:i32){
    println!("The value of x, y is {}, {}", x, y);
}

fn five() -> i32{
    5 // <- ; not use
}