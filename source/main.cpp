#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <tuple>
#include <sstream>
#include <string>

#include "header.h"

std::ofstream fileStream;
std::vector<double> rLogY;
std::vector<double> rLogT;

int main()
{
  std::vector<double> close = readClose();
  std::cout << close.size() << std::endl;

  int len = 100, pos = 0;
  double sumSlope = 0.0, sumCept = 0.0, rmsd = 0.0;
  std::vector<double> fit;
  double minErr = 1.0;
  for(int i = 0; i < /*5; ++i){//*/close.size() - len; ++i){
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
    std::vector<double> tb = topbot(y);
    std::vector<double> yNorm;
    std::vector<double> yNL;
    for(int j = 0; j < len; ++j){
      yNorm.push_back((y[j]-tb[1]) / (tb[0] - tb[1])+ 1); // 0s make problems but +1?
      yNL.push_back(std::log(yNorm[j]));
    }

    std::tie(rmsd,fit) = linReg(t,yNL);
    sumSlope += fit[0];
    sumCept += fit[1];
    //printVec(y);
    //printVec(yNorm);
    //printVec(tb);
    if(fit[0] > 0) {// and fit[1] > 1)
      pos++;
      if(/*pos % 1000 == 1*/rmsd < 0.05){
        minErr = rmsd;
        std::stringstream nameStream;
        nameStream << "fit_" << pos << ".xvg";
        std::cout << nameStream.str() << std::endl;
        std::string fname = nameStream.str();
        //  fileStream_init(fileStream, fname);
        std::vector<double> line;
        for(int k = 0; k < len; ++k)
          line.push_back(fit[0] * t[k] + fit[1]);
        fileStream.open(fname);
        fileStream << "# error: " << rmsd << std::endl
                   << "# intersect: " << fit[1] << std::endl
                   << "# slope: " << fit[0] << std::endl
                   << "# time\tlog norm close \t linear fit " << std::endl;
        writeXvg(fileStream,t,yNL,line);
        std::vector<double> expline;
        for(int k = 0; k < len; ++k)
          expline.push_back(exp(fit[1]) * exp(fit[0] * t[k]));
        fileStream.close();
        std::stringstream nameStream2;
        nameStream2 << "normed_" << pos << ".xvg";
        std::string fname2 = nameStream2.str();
        fileStream.open(fname2);
        fileStream << "# error: " << rmsd << std::endl
                   << "# product part " << fit[1] << std::endl
                   << "# exponent part" << fit[0] << std::endl
                   << "# time \t norm close \t exponential fit " << std::endl;
        writeXvg(fileStream,t,yNorm,expline);
        fileStream.close();
      }
    }
  }
  /*
  std::cout << std::endl << "rmsd: " << rmsd << '\n'
            << "slope: " << fit[0] << " intercept: " << fit[1] << std::endl;
  std::cout << pos << std::endl;
  std::cout << sumSlope / (close.size() - len) << std::endl;
  std::cout << sumCept / (close.size() - len) << std::endl;
  */
  return 0;
}
