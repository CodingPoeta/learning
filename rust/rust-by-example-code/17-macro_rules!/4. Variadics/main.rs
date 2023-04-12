macro_rules! calculate {
  // The pattern for a single `eval`
  (eval $e:expr) => {
      {
          let val: usize = $e; // Force types to be integers
          println!("{} = {}", stringify!{$e}, val);
      }
  };

  // Decompose multiple `eval`s recursively
  (eval $e:expr, $(eval $es:expr),+) => {{
      println!("here");
      calculate! { eval $e }
      println!("there: {}", stringify!{$(eval $es),+});
      calculate! { $(eval $es),+ }
  }};
}

fn main() {
  calculate! { // Look ma! Variadic `calculate!`!
      eval 1 + 2,
      eval 3 + 4,
      eval (2 * 3) + 1
  }
}