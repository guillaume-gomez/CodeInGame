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


fn manageMoto(road: i32, gap: i32, platform: i32, speed: i32, coordX: i32, jumped: &mut bool) -> String{
    let nextPosition :i32 = coordX + speed;
    if ( *jumped ) {
        return "SLOW".to_owned();
    }
    if ( nextPosition > road ) {
        *jumped = true;
        return "JUMP".to_owned();
    }

    if ( speed > gap + 1 ) {
        return "SLOW".to_owned();
    }
    else if (speed == gap + 1) {
        return "WAIT".to_owned();
    }
    else {
       return "SPEED".to_owned();
    }
}

fn moveMoto(coordX: i32, speed: i32) -> i32 {
    coordX + speed
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let road = parse_input!(input_line, i32); // the length of the road before the gap.
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let gap = parse_input!(input_line, i32); // the length of the gap.
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let platform = parse_input!(input_line, i32); // the length of the landing platform.

    let mut jumped = false;
    // game loop
    loop {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let mut speed = parse_input!(input_line, i32); // the motorbike's speed.
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let coord_x = parse_input!(input_line, i32); // the position on the road of the motorbike.
        
        // Write an action using println!("message...");
        // To debug: print_err!("Debug message...");
        let action = manageMoto(road, gap, platform, speed, coord_x, &mut jumped);
        speed = moveMoto(coord_x, speed);
        // A single line containing one of 4 keywords: SPEED, SLOW, JUMP, WAIT.
        println!("{}", action);
    }
}
