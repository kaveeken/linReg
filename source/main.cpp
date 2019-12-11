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
  rLogY.push_back(0.0702614);
  rLogY.push_back(0);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.233115);
  rLogY.push_back(0.233115);
  rLogY.push_back(0.0157952);
  rLogY.push_back(0.0157952);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.0702614);
  rLogY.push_back(0.0974946);
  rLogY.push_back(0.0974946);
  rLogY.push_back(0.485839);
  rLogY.push_back(0.484749);
  rLogY.push_back(0.087146);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.337691);
  rLogY.push_back(0.451525);
  rLogY.push_back(0.456972);
  rLogY.push_back(0.467865);
  rLogY.push_back(0.467865);
  rLogY.push_back(0.467865);
  rLogY.push_back(0.478758);
  rLogY.push_back(0.478758);
  rLogY.push_back(0.467865);
  rLogY.push_back(0.467865);
  rLogY.push_back(0.908497);
  rLogY.push_back(0.751089);
  rLogY.push_back(0.680283);
  rLogY.push_back(0.723856);
  rLogY.push_back(0.734205);
  rLogY.push_back(0.723312);
  rLogY.push_back(0.745643);
  rLogY.push_back(0.745643);
  rLogY.push_back(0.723856);
  rLogY.push_back(0.723312);
  rLogY.push_back(0.723856);
  rLogY.push_back(1);
  rLogY.push_back(1);
  rLogY.push_back(0.88671);
  rLogY.push_back(0.88671);
  rLogY.push_back(0.88671);
  rLogY.push_back(0.805011);
  rLogY.push_back(0.478758);
  rLogY.push_back(0.478758);
  rLogY.push_back(0.484205);
  rLogY.push_back(0.777233);
  rLogY.push_back(0.777233);
  rLogY.push_back(0.484205);
  rLogY.push_back(0.777778);
  rLogY.push_back(0.484205);
  rLogY.push_back(0.776688);
  rLogY.push_back(0.776688);
  rLogY.push_back(0.473312);
  rLogY.push_back(0.315904);
  rLogY.push_back(0.315904);
  rLogY.push_back(0.776688);
  rLogY.push_back(0.776688);
  rLogY.push_back(0.776688);
  rLogY.push_back(0.776688);
  rLogY.push_back(0.337146);
  rLogY.push_back(0.321351);
  rLogY.push_back(0.315904);
  rLogY.push_back(0.27451);
  rLogY.push_back(0.23366);
  rLogY.push_back(0.23366);
  rLogY.push_back(0.560458);
  rLogY.push_back(0.18573);
  rLogY.push_back(0.320261);
  rLogY.push_back(0.815904);
  rLogY.push_back(0.815904);
  rLogY.push_back(0.815904);
  rLogY.push_back(0.815904);
  rLogY.push_back(0.988017);
  rLogY.push_back(0.988017);
  rLogY.push_back(0.988017);
  rLogY.push_back(0.941721);
  rLogY.push_back(0.988017);
  rLogY.push_back(0.988017);
  rLogY.push_back(0.941721);
  rLogY.push_back(0.940087);
  rLogY.push_back(0.940087);
  rLogY.push_back(0.940087);
  rLogY.push_back(0.940087);
  rLogY.push_back(0.778322);
  rLogY.push_back(0.940087);

  //
  rLogT.push_back(0.0);
  rLogT.push_back(0.693147);
  rLogT.push_back(1.09861);
  rLogT.push_back(1.38629);
  rLogT.push_back(1.60944);
  rLogT.push_back(1.79176);
  rLogT.push_back(1.94591);
  rLogT.push_back(2.07944);
  rLogT.push_back(2.19722);
  rLogT.push_back(2.30259);
  rLogT.push_back(2.3979 );
  rLogT.push_back(2.48491);
  rLogT.push_back(2.56495);
  rLogT.push_back(2.63906);
  rLogT.push_back(2.70805);
  rLogT.push_back(2.77259);
  rLogT.push_back(2.83321);
  rLogT.push_back(2.89037);
  rLogT.push_back(2.94444);
  rLogT.push_back(2.99573);
  rLogT.push_back(3.04452);
  rLogT.push_back(3.09104);
  rLogT.push_back(3.13549);
  rLogT.push_back(3.17805);
  rLogT.push_back(3.21888);
  rLogT.push_back(3.2581 );
  rLogT.push_back(3.29584);
  rLogT.push_back(3.3322 );
  rLogT.push_back(3.3673 );
  rLogT.push_back(3.4012 );
  rLogT.push_back(3.43399);
  rLogT.push_back(3.46574);
  rLogT.push_back(3.49651);
  rLogT.push_back(3.52636);
  rLogT.push_back(3.55535);
  rLogT.push_back(3.58352);
  rLogT.push_back(3.61092);
  rLogT.push_back(3.63759);
  rLogT.push_back(3.66356);
  rLogT.push_back(3.68888);
  rLogT.push_back(3.71357);
  rLogT.push_back(3.73767);
  rLogT.push_back(3.7612 );
  rLogT.push_back(3.78419);
  rLogT.push_back(3.80666);
  rLogT.push_back(3.82864);
  rLogT.push_back(3.85015);
  rLogT.push_back(3.8712 );
  rLogT.push_back(3.89182);
  rLogT.push_back(3.91202);
  rLogT.push_back(3.93183);
  rLogT.push_back(3.95124);
  rLogT.push_back(3.97029);
  rLogT.push_back(3.98898);
  rLogT.push_back(4.00733);
  rLogT.push_back(4.02535);
  rLogT.push_back(4.04305);
  rLogT.push_back(4.06044);
  rLogT.push_back(4.07754);
  rLogT.push_back(4.09434);
  rLogT.push_back(4.11087);
  rLogT.push_back(4.12713);
  rLogT.push_back(4.14313);
  rLogT.push_back(4.15888);
  rLogT.push_back(4.17439);
  rLogT.push_back(4.18965);
  rLogT.push_back(4.20469);
  rLogT.push_back(4.21951);
  rLogT.push_back(4.23411);
  rLogT.push_back(4.2485 );
  rLogT.push_back(4.26268);
  rLogT.push_back(4.27667);
  rLogT.push_back(4.29046);
  rLogT.push_back(4.30407);
  rLogT.push_back(4.31749);
  rLogT.push_back(4.33073);
  rLogT.push_back(4.34381);
  rLogT.push_back(4.35671);
  rLogT.push_back(4.36945);
  rLogT.push_back(4.38203);
  rLogT.push_back(4.39445);
  rLogT.push_back(4.40672);
  rLogT.push_back(4.41884);
  rLogT.push_back(4.43082);
  rLogT.push_back(4.44265);
  rLogT.push_back(4.45435);
  rLogT.push_back(4.46591);
  rLogT.push_back(4.47734);
  rLogT.push_back(4.48864);
  rLogT.push_back(4.49981);
  rLogT.push_back(4.51086);
  rLogT.push_back(4.52179);
  rLogT.push_back(4.5326 );
  rLogT.push_back(4.54329);
  rLogT.push_back(4.55388);
  rLogT.push_back(4.56435);
  rLogT.push_back(4.57471);
  rLogT.push_back(4.58497);
  rLogT.push_back(4.59512);
  rLogT.push_back(4.60517);

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
  */
  double rmsdd = 0.0;
  std::vector<double> fitt;
  std::tie(rmsdd,fitt) = linReg(rLogT,rLogY);
  std::vector<double> linee;
  for(int k = 0; k < rLogT.size(); ++k)
    linee.push_back(fitt[0] * rLogT[k] + fitt[1]);
  fileStream.open("test.xvg");
  fileStream << "# error: " << rmsdd << std::endl;
  /*fileStream << "@ legend on\n"
    << "@ s0 legend \"time\"\n"
    << "@ s1 legend \"price\"\n"
    << "@ s2 legend \"fit\"\n"
    << "@target G0.S0\n"
    << "@type xy\n";*/
  writeXvg(fileStream,rLogT,rLogY,linee);
  fileStream.close();

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
      yNorm.push_back((y[j]-tb[1]) / (tb[0] - tb[1])); // 0 is a problem but +1 feels wrong
      yNL.push_back(std::log(yNorm[i]));
    }
    std::tie(rmsd,fit) = linReg(lt,yNL);
    sumSlope += fit[0];
    sumCept += fit[1];
    //printVec(y);
    //printVec(yNorm);
    //printVec(tb);
    if(fit[0] > 0) {// and fit[1] > 1)
      pos++;
      if(/*pos % 1000 == 1*//*rmsd < minErr*/ true){
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
        writeXvg(fileStream,lt,yNorm,line);
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
