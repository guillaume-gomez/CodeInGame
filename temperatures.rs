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

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32); // the number of temperatures to analyse
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let temps = input_line.trim_right().to_string(); // the n temperatures expressed as integers ranging from -273 to 5526
    let temps_v: Vec<&str> = temps.split(' ').collect();
    if (temps.len() == 0) {
        println!("0");
    }
    else {
        let mut index_min = 0;
        let mut min_value :i32 = 5526;
        for (index, temp) in temps_v.iter().enumerate() {
           print_err!("{}", temp);
           let tempInteger = temp.parse::<i32>().unwrap();       
           if ( min_value.abs() > tempInteger.abs() || 
               (min_value.abs() == tempInteger && tempInteger > 0)){
                min_value = tempInteger;
                index_min = index;
           }
        }
        println!("{}", temps_v[index_min]);
    }
}
