#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double> > nelMeadInit(std::vector<double> guess)
{
  std::vector<std::vector<double> > X(3);
  double alpha = 0.05;
  double beta = 0.05;
  X[0] = guess;
  if(guess[0] == 0)
    alpha = 0.0025;
  std::vector<double> Xa = {guess[0] + alpha * guess[0], guess[1]};
  if(guess[1] == 0)
    beta = 0.0025;
  std::vector<double> Xb = {guess[0], guess[1] + beta * guess[1]};
  X[1] = Xa;
  X[2] = Xb;
  return X;
}

double objective(std::vector<double> t, std::vector<double> y, std::vector<double> Xi)
{
  std::vector<double> fx(x.size());
  double msd
  for(int i = 0; i < x.size(); i++){
    fx[i] = Xi[0] * t[i] + Xi[1]; // don't need a vector even
    msd += (fx[i] - y[i]) * (fx[i] - y[i]);
  }
  return std::sqrt(msd);
}

int indexSmallest(std::vector<double> vec)
{
  int index = 0;
  for(int i = 1; i < vec.size(); i++)
    {
      if(vec[i] < vec[index])
        index = i;
    }
  return index;
}

int indexLargest(std::vector<double> vec)
{
  int index = 0;
  for(int i = 1; i < vec.size(); i++)
    {
      if(vec[i] > vec[index])
        index = i;
    }
  return index;
}

std::vector<double> sclMult(std::vector<double> vec, double scl)
{
  for(int i; i < vec.size(); i++)
    vec[i] *= scl;
  return vec;
}
std::vector<double> sclAdd(std::vector<double> vec, double scl)
{
  for(int i; i < vec.size(); i++)
    vec[i] += scl;
  return vec;
}
std::vector<double> vecAdd(std::vector<double> vec1, std::vector<double> vec2)
{
  for(int i; i < vec.size(); i++)
    vec1[i] += vec2[i];
  return vec1;
}
std::vector<double> vecSub(std::vector<double> vec1, std::vector<double> vec2)
{
  for(int i; i < vec.size(); i++)
    vec1[i] -= vec2[i];
  return vec1;
}

std::tuple<std::vector<std::vector<double> >,
           std::vector<double> > sort(std::vector<std::vector<double> > X,
                                         std::vector<double> err)
{
  std::vector<double> sortErr(3);
  std::vector<std::vector<double> > sortX(3);
  int small = indexSmallest(err), large = indexLargest(err)
  int middle = fabs(small + large - 3);
  sortErr[0] = err[small];
  sortErr[1] = err[middle];
  sortErr[2] = err[large];
  sortX[0] = X[small];
  sortX[1] = X[middle];
  sortX[2] = X[large];
  return std::make_tuple(sortX,sortErr);
}

std::tuple<double, std::vector<double> >  nelMead(std::vector<std::vector<double> > X, int i = 0)
{
  double alpha = 0.5, gamma = 1.0, rho = 0.5, sigma = 0.5;
  i++;
  std::vector<double> err(3);
  for(int j = 0; j < 3; j++)
    err[j] = objective(t,y,X[j]);
  std::vector<double> sortErr(3);
  std::vector<std::vector<double> > sortX(3);
  std::tie(sortX,sortErr) = sort(X,err)
  if(fabs(err[0] - err[1]) < err[0] * 0.0001 && fabs(err[0] - err[1]) < err[0 * 0.0001])
    return std::make_tuple(sortErr[0],sortX[0]);
  if(i >= 800)
    return std::make_tuple(sortErr[0],sortX[0]);

  std::vector<double> coid = sclMult(vecAdd(sortX[0],sortX[1]), 0.5);
  std::vector<double> refl = vecAdd(coid, sclMult(vecSub(coid, sortX[2]),alpha))
}
