# Rust Casadi Interface

This is an interface to CasADi functions of the form `phi(u; p)`, where `u`
is a decision variable and `p` a parameter.

Here is an example of such a function (MATLAB example)

```matlab
% File: matlab/example.m
nu = 10;                           % number of decision variables
np = 2;                            % number of parameters 

u = casadi.SX.sym('u', nu);        % decision variables
p = casadi.SX.sym('p', np);        % parameters

phi = (p'*p) * cos(sin(u))' * u;   % cost function phi(u; p)
```

We may then create C code for this function using

```matlab
phi_fun = casadi_generate_c_code(nu, np, u, p, phi, 'phi');
```

This will create a function that maps `(u, p)` to `(phi(u; p), J_u phi(u; p))`,
where `phi(u; p)` is the value of function `phi` and `J_u phi(u; p)` is the 
Jacobian matrix (with respect to `u`).


First we need to build the interface:

```
$ make
```

We may now use the Rust interface to consume that function. Here is an example:


```rust
// File: main.rs
extern crate icasadi;

fn main() {
    let u = [1.0, 2.0, 3.0, -5.0, 1.0, 10.0, 14.0, 17.0, 3.0, 5.0];
    let p = [1.0, -1.0];
    let mut cost_value = 0.0;
    let mut jac = [0.0; 10];
    
    icasadi::icasadi(&u, &p, &mut cost_value, &mut jac);

    println!("cost value = {}", cost_value);
    println!("jacobian   = {:#?}", jac);
}
```

To compile `main.rs`, run:

```
$ export RUSTFLAGS='-L ./lib/' 
$ cargo run
```

Note: this interface is still work in progress!