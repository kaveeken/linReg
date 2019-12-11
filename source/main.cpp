#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <tuple>
#include <sstream>
#include <string>

#include "header.h"

std::ofstream fileStream;

int main()
{
  /*
  std::vector<double> t = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,20,25,30,40,50};
  std::vector<double> y = {0,2,3,6,7,10,13,15,17,18,10,20,25,25,30,29,38,52,60,90,100};
  std::tie(rmsd,fit) = linReg(t,y);
  std::cout << std::endl << "rmsd: " << rmsd << '\n'
            << "slope: " << fit[0] << " intercept: " << fit[1] << std::endl;
  */
  std::vector<double> close = readClose();
  std::cout << close.size() << std::endl;

  int len = 100, pos = 0;
  double sumSlope = 0.0, sumCept = 0.0, rmsd = 0.0;
  std::vector<double> fit;

  for(int i = 0; i < 5; ++i){//close.size() - len; ++i){
    double dI = 0.0;
    std::vector<double> t, y, lt, ly;
    //    std::vector<double> yy;
    for(int j = 1; j < len + 1; ++j){
      dI += 1.0;
      t.push_back(dI);
      y.push_back(close[j + i]);
      lt.push_back(std::log(dI));
      ly.push_back(std::log(close[j + i]));
    }
    // normalizing
    // rewrite to be neater
    std::vector<double> tb = topbot(y);
    std::vector<double> yNorm;
    for(int j = 0; j < len; ++j){
      /* std::cout << y[j] - tb[1] << std::endl;
      std::cout << tb[0] - tb[1] << std::endl;
      std::cout << (y[j] - tb[1]) / (tb[0] - tb[1]) << std::endl; */
      yNorm.push_back((y[j]-tb[1]) / (tb[0] - tb[1]) + 1); // 0 is a problem but +1 feels wrong
    }
    std::tie(rmsd,fit) = linReg(t,yNorm);
    sumSlope += fit[0];
    sumCept += fit[1];
    //printVec(y);
    //printVec(yNorm);
    //printVec(tb);
    if(/*fit[0] > 0*/true) {// and fit[1] > 1)
      pos++;
      if(/*pos % 1000 == 1 // */ true){
        std::stringstream nameStream;
        nameStream << "fit_" << pos << ".xvg";
        std::cout << nameStream.str() << std::endl;
        std::string fname = nameStream.str();
        //  fileStream_init(fileStream, fname);
        std::vector<double> line;
        for(int k = 0; k < len; ++k){
          line.push_back(fit[0] * t[k] + fit[1]);
        }
        fileStream.open(fname);
        writeXvg(fileStream,t,yNorm,line);
        fileStream.close();
      }
    }
  }
  std::cout << std::endl << "rmsd: " << rmsd << '\n'
            << "slope: " << fit[0] << " intercept: " << fit[1] << std::endl;
  std::cout << pos << std::endl;
  std::cout << sumSlope / (close.size() - len) << std::endl;
  std::cout << sumCept / (close.size() - len) << std::endl;
  return 0;
}
