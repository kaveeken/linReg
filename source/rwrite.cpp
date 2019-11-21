#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <sstream>

#include "header.h"

std::vector<double> readClose()
{
  std::string fname = "some_data";
  std::ifstream ifs(fname);
  if(!ifs.is_open())
    throw std::runtime_error("unable to open config_code.txt\n");

	// reading
	std::vector<double> vec;
  std::string str;
  while(std::getline(ifs,str))
		if(str.size() > 0)
			vec.push_back(std::stod(str));
    else
			throw std::runtime_error("aaaa");
  return vec;
}

void fileStream_init(std::ofstream &fileStream, const std::string &name)
{
  std::stringstream ss;
  std::stringstream dirStream;
  fileStream.open(name);
  if(!fileStream.is_open()) {
    std::stringstream ssErr;
    ssErr << "unable to open " << ss.str();
    throw std::runtime_error(ssErr.str());
  }
}

void writeXvg(std::ofstream &fileStream,
              const std::vector<double> &t,
              const std::vector<double> &y,
              const std::vector<double> &fit)
{
  for(int i = 0; i < t.size(); ++i){
    fileStream << t[i] << ' ' << y[i] << ' ' << fit[i] << std::endl;
  }
}
