#ifndef APDOROJIMAS_H
#define APDOROJIMAS_H

#include <algorithm>
#include "studentas.h"
#include "calc.h"

void skaiciavimas(std::vector<Studentas> &A, bool medianos, int ndKiekis);

void skaiciavimas(std::vector<Studentas> &A, bool medianos);

void rusiavimasSkirstymas(std::vector<Studentas> &A, int rPasirinkimas, bool medianos);

void failoGeneravimas(int studentuKiekis, int ndKiekis);

void skirstymas(std::vector<Studentas> &studentai, std::vector<Studentas> &galvociai, std::vector<Studentas> &vargsiukai, int rezervas);

#endif