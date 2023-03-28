// Define a function which takes a generic `F` argument
// bounded by `Fn`, and calls it
fn call_me<F: Fn(&str)>(f: F) {
    f("ha ha ha");
}

// Define a wrapper function satisfying the `Fn` bound
fn function(s: &str) {
    println!("I'm a function! {}", s);
}

fn main() {
    // Define a closure satisfying the `Fn` bound
    let closure = |a: &str| println!("I'm a closure! {}", a);

    call_me(closure);
    call_me(function);
}