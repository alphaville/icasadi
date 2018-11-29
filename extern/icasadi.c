#include "icasadi.h"

int icasadi_fun(
        const double *u, 
        const double *casadi_static_params,
        double* cost_value, 
        double* cost_jacobian)
{
    const double* casadi_arguments[2] = {u, casadi_static_params};
    double *casadi_results[2] = {cost_value, cost_jacobian};
    return CASADI_FUNCTION_NAME(casadi_arguments, casadi_results, 0, 0, 0);
}

int icasadi_num_decision_variables(void){
    return CASADI_NU;
}

int icasadi_num_static_parameters(void){
    return CASADI_NP;
}

