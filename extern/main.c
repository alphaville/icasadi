#include "icasadi.h"
#include <stdio.h>

int main() {
    // long long int n = phi_n_in();
    double u[CASADI_NU] = {1,1,1,1,1,1,1,1,1,1};
    double p[CASADI_NP] = {1,1};

    double phival = 0;
    double cost_jacobian[CASADI_NU] = {0};

    icasadi_fun(u, p, &phival, cost_jacobian);
    printf("cost value = %g\n", phival);
    printf("jacobian of cost =\n");
    printf("[\n");
    int i;
    for (i = 0; i < CASADI_NU; ++i){
        printf("  %g\n", cost_jacobian[i]);
    }
    printf("]\n");
    return 0;
}