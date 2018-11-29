# Rust Casadi Interface
[![Build Status](https://travis-ci.org/alphaville/icasadi.svg?branch=master)](https://travis-ci.org/alphaville/icasadi)

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

We may then create C code for this function and its Jacobian using

```matlab
[cost, grad_cost] = casadi_generate_c_code(nu, np, u, p, phi, 'phi');
```


This will create two functions:

- `cost` : which maps `(u, p)` to `phi(u; p)`,
- `grad_cost` : the Jacobian matrix of `phi` with respect to `u` evaluated 
   at `(u, p)`


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
    
    icasadi_cost(u, p, &phival);       // compute the cost
    icasadi_grad(u, p, cost_jacobian); // compute the Jacobian of the cost

    println!("cost value = {}", cost_value);
    println!("jacobian   = {:#?}", jac);
}
```

To compile and run `main.rs`, run:

```
$ export RUSTFLAGS='-L ./lib/' 
$ cargo run
```

Note: this interface is still work in progress!
