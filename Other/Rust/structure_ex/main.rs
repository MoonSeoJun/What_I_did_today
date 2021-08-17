/*
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}
*/

struct Rectangle{
    length: u32,
    width: u32,
}

// Method
impl Rectangle {
    fn area(&self) -> u32{
        self.length * self.width
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.length > other.length && self.width > other.width
    }
}

fn main() {
    let rect = Rectangle{length:50, width:30};
    let rect2 = Rectangle{length:60, width:60};

    println!("The area of the rectangle is {} square pixels", rect.area());

    println!("Can rect hold rect2? {}", rect.can_hold(&rect2));

    /*
    let mut user1 = User{
        username : String::from("asdf"),
        email : String::from("ASDFSADF"),
        sign_in_count : 1,
        active : true,
    };

    println!("username : {}, email : {}, sign in count : {}, active : {}", user1.username, user1.email, user1.sign_in_count, user1.active);

    user1.email = String::from("asdfasd");

    println!("{}", user1.email);
    */
}
