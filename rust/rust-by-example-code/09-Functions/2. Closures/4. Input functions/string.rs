fn main() {
    let s = "hello_world";
    let ss = "hello_words".to_string();
    let mut mutable_string = String::from("hello");

    coerce_success(&s);
    coerce_success(&s.to_string());
    coerce_success(&ss);
    coerce_success(&mutable_string);
    coerce_fail(&s.to_string());
    coerce_fail(&ss);
    coerce_fail(&mutable_string);
}

fn coerce_success(data: &str) { // compiles just fine, even though we put in a &String
    println!("{}", data);
}

fn coerce_fail(data: &String) { // error - expected &String, but found &str
    println!("{}", data);
}