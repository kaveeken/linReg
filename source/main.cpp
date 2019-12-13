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
  /*
  std::vector<double> t = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,20,25,30,40,50};
  std::vector<double> y = {0,2,3,6,7,10,13,15,17,18,10,20,25,25,30,29,38,52,60,90,100};
  std::tie(rmsd,fit) = linReg(t,y);
  std::cout << std::endl << "rmsd: " << rmsd << '\n'
            << "slope: " << fit[0] << " intercept: " << fit[1] << std::endl;

  std::vector<double> tvec1 = {1.0,2.0,3.0};
  std::vector<double> tvec2 = {3.0,2.0,1.0};
  std::vector<double> tadd = vecAdd(tvec1,tvec2);
  std::vector<double> tsub = vecSub(tvec1,tvec2);
  std::vector<double> t1m5 = sclMult(tvec1,5);
  printVec(tvec1);
  printVec(tadd);
  printVec(t1m5);
  printVec(sclAdd(t1m5,2));
  printVec(tsub);
  double rmsdd = 0.0;
  std::vector<double> fitt;
  std::tie(rmsdd,fitt) = linReg(rLogT,rLogY);
  printVec(fitt);
  std::vector<double> linee;
  for(int k = 0; k < rLogT.size(); ++k)
    linee.push_back(fitt[0] * rLogT[k] + fitt[1]);
  fileStream.open("test.xvg");
  fileStream << "# error: " << rmsdd << std::endl;
  writeXvg(fileStream,rLogT,rLogY,linee);
  fileStream.close();
  std::cout << "summed t: " << vecSum(rLogT) << ", y: " << vecSum(rLogY) << std::endl;
  */

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
    // rewrite to be neater
    std::vector<double> tb = topbot(y);
    std::vector<double> yNorm;
    std::vector<double> yNL;
    for(int j = 0; j < len; ++j){
      yNorm.push_back((y[j]-tb[1]) / (tb[0] - tb[1])+ 1); // 0s make problems but +1?
      yNL.push_back(std::log(yNorm[j]));
    }
    fileStream.open("yNorm.tmp");
    writeVec(fileStream,yNorm);
    fileStream.close();
    fileStream.open("lt.tmp");
    writeVec(fileStream,lt);
    fileStream.close();
    std::vector<double> ltwr = readVec("lt.tmp");
    fileStream.open("yNL.tmp");
    writeVec(fileStream,yNL);
    fileStream.close();
    std::vector<double> yNLwr = readVec("yNL.tmp");

    std::tie(rmsd,fit) = linReg(ltwr,yNLwr);
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
        for(int k = 0; k < len; ++k){
          line.push_back(fit[0] * lt[k] + fit[1]);
        }
        fileStream.open(fname);
        fileStream << "# error: " << rmsd << std::endl;
        /*fileStream << "@ legend on\n"
                   << "@ s0 legend \"time\"\n"
                   << "@ s1 legend \"price\"\n"
                   << "@ s2 legend \"fit\"\n"
                   << "@target G0.S0\n"
                   << "@type xy\n";*/
        writeXvg(fileStream,lt,yNL,line);
        fileStream.close();
        std::stringstream nameStream2;
        nameStream2 << "normed_" << pos << ".xvg";
        std::string fname2 = nameStream.str();
        fileStream.open(fname2);
        writeXvg(fileStream,t,yNorm,yNorm);
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
