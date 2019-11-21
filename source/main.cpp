#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

#include "header.h"

std::vector<double> guess(std::vector<double> t, std::vector<double> y)
{
  double tmean = vecMean(t);
  double ymean = vecMean(y);
  double numsum = 0.0;
  double densum = 0.0;
  for(int i = 0; i < t.size();i++){
    numsum += (t[i] - tmean) * (y[i] - ymean);
    densum += (t[i] - tmean) * (t[i] - tmean);
  }
  std::vector<double> guess = {numsum / densum, ymean - numsum/densum * tmean};
  return guess;
}

std::tuple<double,std::vector<double> > linReg(std::vector<double> t, std::vector<double> y)
{
  std::vector<double> guss = guess(t,y);
  std::vector<std::vector<double> > X = nelMeadInit(guss);
  double rmsd = 0;
  std::vector<double> fit(2);
  std::tie(rmsd,fit) = nelMead(X,t,y,0);
  //std::cout << fit[0] << ' ' << fit[1];
  return std::make_tuple(rmsd,fit);
}

int main()
{
  std::vector<double> t = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,20,25,30,40,50};
  std::vector<double> y = {0,2,3,6,7,10,13,15,17,18,10,20,25,25,30,29,38,52,60,90,100};
  double rmsd = 0;
  std::vector<double> fit;
  std::tie(rmsd,fit) = linReg(t,y);
  std::cout << std::endl << "rmsd: " << rmsd << '\n'
            << "slope: " << fit[0] << " intercept: " << fit[1] << std::endl;
  return 0;
}
