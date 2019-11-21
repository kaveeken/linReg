#include <vector>
#include <tuple>
#include <cmath>
#include <iostream>

#include "header.h"

int indexSmallest(const std::vector<double> &vec)
{
  int index = 0;
  for(int i = 1; i < vec.size(); i++)
    {
      if(vec[i] < vec[index])
        index = i;
    }
  return index;
}

int indexLargest(const std::vector<double> &vec)
{
  int index = 0;
  for(int i = 1; i < vec.size(); i++)
    {
      if(vec[i] > vec[index])
        index = i;
    }
  return index;
}

std::vector<double> sclMult(const std::vector<double> &vec, double scl)
{
  std::vector<double> vvec = vec;
  for(int i; i < vec.size(); i++)
    vvec[i] *= scl;
  return vvec;
}
std::vector<double> sclAdd(const std::vector<double> &vec, double scl)
{
  std::vector<double> vvec = vec;
  for(int i; i < vec.size(); i++)
    vvec[i] += scl;
  return vvec;
}
std::vector<double> vecAdd(const std::vector<double> &vec1, const std::vector<double> &vec2)
{
  std::vector<double> vvec = vec1;
  for(int i; i < vec1.size(); i++)
    vvec[i] += vec2[i];
  return vvec;
}
std::vector<double> vecSub(const std::vector<double> &vec1, const std::vector<double> &vec2)
{
  std::vector<double> vvec = vec1;
  for(int i; i < vec1.size(); i++)
    vvec[i] -= vec2[i];
  return vvec;
}
std::vector<std::vector<double> > vecCat(const std::vector<double> &vec1,
                                         const std::vector<double> &vec2,
                                         const std::vector<double> &vec3)
{
  std::vector<std::vector<double> > vecCat(3);
  vecCat[0] = vec1;
  vecCat[1] = vec2;
  vecCat[2] = vec3;
  return vecCat;
}
std::tuple<std::vector<std::vector<double> >, std::vector<double> >
sort(const std::vector<std::vector<double> > &X, const std::vector<double> &err)
{
  std::vector<double> sortErr(3);
  std::vector<std::vector<double> > sortX(3);
  int small = indexSmallest(err), large = indexLargest(err);
  int middle = fabs(small + large - 3);
  sortErr[0] = err[small];
  sortErr[1] = err[middle];
  sortErr[2] = err[large];
  sortX[0] = X[small];
  sortX[1] = X[middle];
  sortX[2] = X[large];
  return std::make_tuple(sortX,sortErr);
}

double vecMean(const std::vector<double> &vec)
{
  double sum = 0;
  for(int i = 0;i < vec.size();i++){
    sum += vec[i];
  }
  return sum / vec.size();
}
double vecSum(const std::vector<double> &vec)
{
  double sum = 0;
  for(int i = 0;i < vec.size();i++){
    sum += vec[i];
      }
  return sum;
    }

void dot()
{
  std::cout << '.' << std::endl;
}