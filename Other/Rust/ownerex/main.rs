fn main() {
    copy_ex();

    let s1 = gives_ownership();

    let s2 = String::from("Hello");

    let s3 = takes_and_gives_back(s2);

    println!("{}, {}", s1, s3);

    // println!("{}", s2); <- Error
}

fn copy_ex(){
    let mut s = String::from("hello");

    println!("The value of s is {}", s);

    s.push_str(", world");

    println!("The value of s is {}", s);

    let s1 = String::from("Hello");
    let s2 = s1.clone();

    println!("s1 : {}, s2 : {}",s1,s2);
}


fn gives_ownership() -> String{
    let some_string = String::from("Hello");
    some_string
}

fn takes_and_gives_back(a_string : String) -> String{
    a_string
}