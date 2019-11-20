# linReg
The linear regression- and curve fitting packages I'm using give confusing results,
so I need something I can tinker with.

First makes an initial guess, 
then minimizes RMSD according to Nelder-Mead 
until convergence in up to a given number of steps.

I might want to use least squares over RMSD.
The project that needs this validates fits by RMSD anyway,
so this is where I ended up.
