#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <tuple>

// utils
int indexSmallest(const std::vector<double> &vec);
int indexLargest(const std::vector<double> &vec);
std::vector<double> sclMult(const std::vector<double> &vec, double scl);
std::vector<double> sclAdd(const std::vector<double> &vec, double scl);
std::vector<double> vecAdd(const std::vector<double> &vec1, const std::vector<double> &vec2);
std::vector<double> vecSub(const std::vector<double> &vec1, const std::vector<double> &vec2);
std::vector<std::vector<double> > vecCat(const std::vector<double> &vec1,
                                         const std::vector<double> &vec2,
                                         const std::vector<double> &vec3);
std::tuple<std::vector<std::vector<double> >, std::vector<double> >
  sort(const std::vector<std::vector<double> > &X, const std::vector<double> &err);
double vecMean(const std::vector<double> &vec);
void dot();
// Nelder-Mead
std::vector<std::vector<double> > nelMeadInit(const std::vector<double> &guess);
double objective(const std::vector<double> &t,
                 const std::vector<double> &y,
                 const std::vector<double> &Xi);
std::tuple<double, std::vector<double> >  nelMead(const std::vector<std::vector<double> > &X,
                                                  const std::vector<double> &t,
                                                  const std::vector<double> &y,
                                                  int n);
#endif

