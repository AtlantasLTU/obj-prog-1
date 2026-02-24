#ifndef CALC_H
#define CALC_H
#include "studentas.h"

double galutinisVid(const Studentas &A);
double galutinisMed(const Studentas &A);
double galutinisVidF(const StudentasF &A, std::vector<int> nd, int rez, int ndKiekis);
double galutinisMedF(const StudentasF &A, std::vector<int> nd, int rez, int ndKiekis);

#endif