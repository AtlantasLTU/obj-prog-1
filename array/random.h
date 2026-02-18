#ifndef RANDOM_H
#define RANDOM_H
#include "studentas.h"
#include "io.h"
#include <random>
#include <ctime>

void studentoVardoPavardesIvestisRandom(Studentas &A, int pasirinkimas);

Studentas skaitymasRandom();

void egzaminoRezultatasRandom(Studentas &A);

int namuDarbuRezultataiIvestisRandom();

int randomStudentuKiekis();

void namuDarbuRezultataiRandom(Studentas &A, int ndKiekis);

Studentas* ivestiStudentusRandom(int pasirinkimas, int &kiekis);

#endif