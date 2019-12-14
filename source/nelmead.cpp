#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

#include "header.h"

std::vector<std::vector<double> > nelMeadInit(const std::vector<double> &guess)
{
  std::vector<std::vector<double> > X(3);
  double alpha = 0.05; // 0.05
  double beta = 0.05;
  X[0] = guess;
  if(guess[0] == 0)
    alpha = 0.00025; // 0.00025
  std::vector<double> Xa = {guess[0] + alpha * guess[0], guess[1]};
  if(guess[1] == 0)
    beta = 0.00025; // wait what
  std::vector<double> Xb = {guess[0], guess[1] + beta * guess[1]};
  X[1] = Xa;
  X[2] = Xb;
  return X;
}

double objective(const std::vector<double> &t,
                 const std::vector<double> &y,
                 const std::vector<double> &Xi)
{
  //std::vector<double> fx(t.size());
  double sd = 0.0;
  for(int i = 0; i < t.size(); i++){
    double fx = Xi[0] * t[i] + Xi[1];
    sd += (fx - y[i]) * (fx - y[i]);
  }
  double msd = sd / t.size();
  return std::sqrt(msd);
}

std::tuple<double, std::vector<double> >  nelMead(const std::vector<std::vector<double> > &X,
                                                  const std::vector<double> &t,
                                                  const std::vector<double> &y,
                                                  int n = 0)
{
  double alpha = 0.5, gamma = 1.0, rho = 0.5, sigma = 0.5;
  n++;
  std::vector<double> err(3);
  //std::cout << n /*<< X.size()*/ << std::endl;
  for(int j = 0; j < 3; j++)
    err[j] = objective(t,y,X[j]);
  std::vector<double> sortErr;
  std::vector<std::vector<double> > sortX;
  std::tie(sortX,sortErr) = sort(X,err);
  std::vector<double> s2 = vecAdd(sortX[0], sclMult(vecSub(sortX[1], sortX[0]),sigma));
  std::vector<double> t3 = vecAdd(sortX[0], sclMult(vecSub(sortX[2], sortX[0]),sigma));

  if(fabs(X[0][0] * X[0][0] - X[1][0] * X[1][0]) < 0.0000000001/*X[0][0] * X[0][0] * 0.00000001 */ &&
     fabs(X[0][1] * X[0][1] - X[1][1] * X[1][1]) < 0.0000000001/*X[0][1] * X[0][1] * 0.00000001 */ &&
     fabs(X[0][0] * X[0][0] - X[2][0] * X[2][0]) < 0.0000000001/*X[0][0] * X[0][0] * 0.00000001 */ &&
     fabs(X[0][1] * X[0][1] - X[2][1] * X[2][1]) < 0.0000000001/*X[0][1] * X[0][1] * 0.00000001 */){
    // now actually tests convergence
    std::cout << "nsteps: " << n << std::endl;
    //printMat(sortX);
    return std::make_tuple(sortErr[0],sortX[0]);
  }
  //dot("a");
  if(n >= 800){
    //std::cout << "800 steps\n";
    printMat(sortX);
    return std::make_tuple(sortErr[0],sortX[0]);
  }

  std::vector<double> coid = sclMult(vecAdd(sortX[0],sortX[1]), 0.5);
  //printVec(coid);
  std::vector<double> refl = vecAdd(coid, sclMult(vecSub(coid, sortX[2]),alpha));
  double errRefl = objective(t,y,refl);
  //  dot();
  if(errRefl > sortErr[0] && errRefl < sortErr[1]) // reflect
    return nelMead(vecCat(sortX[0],sortX[1],refl),t,y,n);
  else if(errRefl < sortErr[0]){
    // dot("b");
    std::vector<double> expd = vecAdd(coid,sclMult(vecSub(refl,coid),gamma));
    double errExpd = objective(t,y,expd);
    if(errExpd < errRefl) // expand
      return nelMead(vecCat(sortX[0],sortX[1],expd),t,y,n);
    else // reflect
      return nelMead(vecCat(sortX[0],sortX[1],refl),t,y,n);
  } else if(errRefl >= sortErr[2]){ // contract
    //dot("c");
    std::vector<double> ctrt = vecAdd(coid, sclMult(vecSub(sortX[2],coid),rho));
    //    dot("c2");
    double errCtrt = objective(t,y,ctrt);
    //    std::cout << sortErr[2];
    if(errCtrt < sortErr[2])
      return nelMead(vecCat(sortX[0],sortX[1],ctrt),t,y,n);
  }
  // else { // shrink
  //dot("d");
  std::vector<double> second = vecAdd(sortX[0], sclMult(vecSub(sortX[1], sortX[0]),sigma));
  std::vector<double> third = vecAdd(sortX[0], sclMult(vecSub(sortX[2], sortX[0]),sigma));
  return nelMead(vecCat(sortX[0],second,third),t,y,n);
  //}
}
