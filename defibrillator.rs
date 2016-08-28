use std::io;

macro_rules! print_err {
    ($($arg:tt)*) => (
        {
            use std::io::Write;
            writeln!(&mut ::std::io::stderr(), $($arg)*).ok();
        }
    )
}

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

struct Debrillator {
    id: i32,
    name: String,
    address: String,
    lat: f32,
    long: f32

}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let mut debrillators: Vec<Debrillator> = Vec::new();
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let lon = input_line.trim().to_string();
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let lat = input_line.trim().to_string();
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32);
    for i in 0..n as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let defib = input_line.trim_right().to_string();
        let defibParams: Vec<&str> = defib.split(';').collect();
        let debrillator = Debrillator{ id: defibParams[0].parse::<i32>().unwrap(),
                                       name: defibParams[1].to_string(),
                                       address: defibParams[2].to_string(),
                                       lat: defibParams[3].replace(",",".").parse::<f32>().unwrap(),
                                       long: defibParams[4].replace(",",".").parse::<f32>().unwrap()
                                     };
    }

    // Write an action using println!("message...");
    // To debug: print_err!("Debug message...");

    println!("answer");
}
