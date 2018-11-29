extern crate libc;
use libc::{c_double, c_int};

#[link(name = "csphi")]
extern "C" {

    pub fn icasadi_num_static_parameters() -> c_int;

    pub fn icasadi_num_decision_variables() -> c_int;

    pub fn icasadi_fun(
        u: *const c_double,
        casadi_static_params: *const c_double,
        cost_value: *mut c_double,
        cost_jacobian: *mut c_double,
    ) -> c_int;
}

pub fn num_static_parameters() -> c_int {
    unsafe { icasadi_num_static_parameters() }
}

pub fn num_decision_variables() -> c_int {
    unsafe { icasadi_num_decision_variables() }
}

pub fn icasadi(
    u: &[f64],
    casadi_static_params: &[f64],
    cost_value: &mut f64,
    cost_jacobian: &mut [f64],
) -> c_int {
    unsafe {
        icasadi_fun(
            u.as_ptr(),
            casadi_static_params.as_ptr(),
            cost_value,
            cost_jacobian.as_mut_ptr(),
        )
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn tst_num_static() {
        let np = num_static_parameters();
        assert_eq!(np, 2);
    }

    #[test]
    fn tst_num_decision_var() {
        let np = num_decision_variables();
        assert_eq!(np, 10);
    }

    #[test]
    fn tst_call_casadi_fun() {
        let u = [1.0, 2.0, 3.0, -5.0, 1.0, 10.0, 14.0, 17.0, 3.0, 5.0];
        let p = [1.0, -1.0];
        let mut cost_value = 0.0;
        let mut jac = [0.0; 10];
        icasadi(&u, &p, &mut cost_value, &mut jac);
        assert!((68.9259 - cost_value).abs() < 1e-4);        
    }
}
