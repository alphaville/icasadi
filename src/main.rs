extern crate icasadi;

fn main() {
    let u = [1.0, 2.0, 3.0, -5.0, 1.0, 10.0, 14.0, 17.0, 3.0, 5.0];
    let p = [1.0, -1.0];
    let mut cost_value = 0.0;
    let mut jac = [4.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0];

    
    icasadi::icasadi(&u, &p, &mut cost_value, &mut jac);

    println!("cost value = {}", &cost_value);
    println!("jacobian   = {:#?}", &jac);
    println!("u = {:#?}", &u);
    println!("p = {:#?}", &p);
}
