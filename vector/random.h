#ifndef RANDOM_H
#define RANDOM_H
#include "studentas.h"
#include "io.h"

Studentas skaitymasRandom(int pasirinkimas);

void studentoVardoPavardesIvestisRandom(Studentas &A, int pasirinkimas);

int namuDarbuRezultataiIvestisRandom();

void namuDarbuRezultataiRandom(Studentas &A, int ndKiekis);

int randomStudentuKiekis();

std::vector<Studentas> ivestiStudentusRandom(int pasirinkimas);

void egzaminoRezultatasRandom(Studentas &A);

#endif