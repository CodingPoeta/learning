use std::fmt;

struct Circle {
    radius: i32
}

impl fmt::Display for Circle {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Circle of radius {}", self.radius)
    }
}

#[derive(Debug, PartialEq, Eq)]
struct ParseCircleError;

impl std::str::FromStr for Circle {
    type Err = ParseCircleError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let radius = s
            .strip_prefix("Circle of radius ")
            .ok_or(ParseCircleError)?;

        let radius_fromstr = radius.parse::<i32>().map_err(|_| ParseCircleError)?;

        Ok(Circle { radius: radius_fromstr })
    }
}

fn main() {
    // Converting to String: ToString
    let circle = Circle { radius: 6 };
    println!("{}", circle.to_string());

    // Parsing a String: FromStr 
    let parsed_circle: Circle = "Circle of radius 99".parse().unwrap();
    println!("Circle: {}", parsed_circle);

    // Parsing a String: FromStr 
    let parsed: i32 = "5".parse().unwrap();
    let turbo_parsed = "10".parse::<i32>().unwrap();

    let sum = parsed + turbo_parsed;
    println!("Sum: {:?}", sum);
}