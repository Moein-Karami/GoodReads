#ifndef _GeneralFunctions_
#define _GeneralFunctions_

#include "ImportantLibraries.hpp"

std::vector<std::string> divideStrByChar(std::string str, char divider);
std::vector<int> convertStringsToInts(std::vector<std::string> strs);
std::vector<int> convertOneStringToVectorOfInts(std::string str,char divider);
std::vector<std::vector<std::string>> proccesFileInfo(std::string path);
double divide(double a,double b);

#endif