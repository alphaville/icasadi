extern crate icasadi;

fn main() {
    let mut u: [f64; 10] = [1.0, 2.0, 3.0, -5.0, 1.0, 10.0, 14.0, 17.0, 3.0, 5.0];
    let p = [1.0, -1.0];
    let mut cost_value = 0.0;
    let mut jac = vec![0.0; icasadi::num_decision_variables()];

    icasadi::icasadi_cost(&u, &p, &mut cost_value);

    println!("cost value = {:.3}", &cost_value);
    

    // ------------------------------------------------------------------------
    // Estimate Lipschitz constant at u
    // ------------------------------------------------------------------------
    let lip = icasadi::estimate_local_lipschitz_squared(&mut u, &p, &mut jac, &mut [0.0_f64; 10]);
    println!("jacobian   = {:.2?}", &jac);

    println!(
        "An approximate local squared Lipschitz constant of grad_f at u is L^2 = {:.4}",
        lip
    );
}
