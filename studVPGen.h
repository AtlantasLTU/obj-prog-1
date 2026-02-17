#ifndef studVPGen_H
#define studVPGen_H
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include "studentas.h"

using std::string;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::vector;
using std::map;
using std::mt19937;

using hrClock = std::chrono::high_resolution_clock; 
typedef std::uniform_int_distribution<int>  int_distribution;

void gen_map(Studentas &A);

#endif