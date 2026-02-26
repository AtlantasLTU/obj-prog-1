#ifndef APDOROJIMAS_H
#define APDOROJIMAS_H

#include <algorithm>
#include "studentas.h"
#include "calc.h"

void skaiciavimas(std::vector<Studentas> &A, bool medianos, int ndKiekis);

void skaiciavimas(std::vector<Studentas> &A, bool medianos);

void rusiavimasSkirstymas(std::vector<Studentas> &A, int rPasirinkimas, bool medianos);

#endif