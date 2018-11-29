#ifndef ICASADI_HEADER_SENTINEL
#define ICASADI_HEADER_SENTINEL

#include "icasadi_config.h"

extern int CASADI_FUNCTION_NAME(
        const double** arg, 
        double** casadi_results, 
        long long int* iw, 
        double* w, 
        void* mem);

int icasadi_fun(
        const double *u, 
        const double *casadi_static_params,
        double* cost_value, 
        double* cost_jacobian);

int icasadi_num_decision_variables(void);

int icasadi_num_static_parameters(void);



#endif