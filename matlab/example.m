nu = 10;                           % number of decision variables
np = 2;                            % number of parameters 

u = casadi.SX.sym('u', nu);        % decision variables
p = casadi.SX.sym('p', np);        % parameters

phi = (p'*p) * cos(sin(u))' * u;   % cost function phi(u; p)

phi_fun = casadi_generate_c_code(nu, np, u, p, phi, 'phi');

u = [1.0, 2.0, 3.0, -5.0, 1.0, 10.0, 14.0, 17.0, 3.0, 5.0]';
p = [1.0, -1.0]';


[cost, jcost] = phi_fun(u, p)
