function phi_fun = casadi_generate_c_code( nu, np, u, p, phi, function_name )
%CASADI_GENERATE_C_CODE Summary of this function goes here
%   Detailed explanation goes here

jphi = jacobian(phi, u);
phi_fun = casadi.Function(function_name, {u, p}, {phi, jphi});
phi_fun.generate(function_name);
movefile([function_name '.c'], '../extern/autogen-casadi-function.c');
casadi_generate_header(nu, np, function_name);


function casadi_generate_header(nu, np, function_name)
fid = fopen('../extern/icasadi_config.h', 'w');

fprintf(fid, '/* Auto-generated header file */\n');
fprintf(fid, '#ifndef ICASADI_CONFIG_HEADER_SENTINEL\n');
fprintf(fid, '#define ICASADI_CONFIG_HEADER_SENTINEL\n\n');

fprintf(fid, '#define CASADI_NU %d\n', nu);
fprintf(fid, '#define CASADI_NP %d\n', np);
fprintf(fid, '#define CASADI_FUNCTION_NAME %s\n\n', function_name);

fprintf(fid, '#endif\n');

fclose(fid);

