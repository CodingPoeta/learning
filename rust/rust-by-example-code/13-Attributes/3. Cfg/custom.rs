#[cfg(some_condition)]
fn conditional_function() {
    println!("condition met!");
}

#[cfg(other_condition)]
fn conditional_function() {
    println!("other_condition met!");
}

fn main() {
    conditional_function();
}
