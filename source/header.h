#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <tuple>

/***** utils *****/
// smallest/largest value from a vector
int indexSmallest(const std::vector<double> &vec);
int indexLargest(const std::vector<double> &vec);
// some vector operations
std::vector<double> sclMult(const std::vector<double> &vec, double scl);
std::vector<double> sclAdd(const std::vector<double> &vec, double scl);
std::vector<double> vecAdd(const std::vector<double> &vec1, const std::vector<double> &vec2);
std::vector<double> vecSub(const std::vector<double> &vec1, const std::vector<double> &vec2);
std::vector<std::vector<double> > vecCat(const std::vector<double> &vec1,
                                         const std::vector<double> &vec2,
                                         const std::vector<double> &vec3);
double vecMean(const std::vector<double> &vec);
// sort two vectors of length 3 by the elements in the err vector
std::tuple<std::vector<std::vector<double> >, std::vector<double> >
  sort(const std::vector<std::vector<double> > &X, const std::vector<double> &err);
// print a dot
void dot();

/****** Nelder-Mead *****/
// make an initial simplex from a guess
std::vector<std::vector<double> > nelMeadInit(const std::vector<double> &guess);
double objective(const std::vector<double> &t,
                 const std::vector<double> &y,
                 const std::vector<double> &Xi);
// do the minimization
std::tuple<double, std::vector<double> >  nelMead(const std::vector<std::vector<double> > &X,
                                                  const std::vector<double> &t,
                                                  const std::vector<double> &y,
                                                  int n);

/****** regression *****/
// make an initial guess
std::vector<double> guess(std::vector<double> t, std::vector<double> y);
// do the thing
std::tuple<double,std::vector<double> > linReg(std::vector<double> t, std::vector<double> y);
#endif

