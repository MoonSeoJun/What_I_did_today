struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

fn main() {
    let user1 = User{
        username : String::from("asdf"),
        email : String::from("ASDFSADF"),
        sign_in_count : 1,
        active : true,
    };

    println!("username : {}, email : {}, sign in count : {}, active : {}", user1.username, user1.email, user1.sign_in_count, user1.active)
}
