use std::cmp::PartialOrd;

fn main() {
    let numbers = vec![32,56,85,75,16];

    let largest = largerst(&numbers);

    let chars = vec!['a', 'g', 'y', 'e', '7'];

    let result = largerst(&chars);

    println!("The largest char is {}", result);

    println!{"The largest value is {}", largest};

}

fn largerst<T: PartialOrd + Copy>(list : &[T]) -> T{
    let mut largest = list[0];

    for &item in list.iter(){
        if item > largest {
            largest = item;
        }
    }
    largest
}