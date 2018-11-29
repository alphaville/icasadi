extern crate cc;

fn main() {

    cc::Build::new()
        .flag_if_supported("-Wall")
        .pic(true)
        .flag("-Wno-unused-parameter")    
        .include("src")
        .file("extern/auto_casadi_cost.c")
        .file("extern/auto_casadi_grad.c")
        .file("extern/icasadi.c")          
        .compile("icasadi");
}