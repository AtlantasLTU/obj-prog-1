#ifndef IO_H
#define IO_H
#include "studentas.h"
#include <limits>
#include "calc.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Studentas skaitymas();

void studentoVardoPavardesIvestis(Studentas &A);

void namuDarbuRezultatuIvestis(Studentas &A);

void pridetiNd(Studentas &A, int paz);

void egzaminoRezultatoIvestis(Studentas &A);

void isvestis(const Studentas *A, int kiekis, bool medianos);

bool medianosUzklausa();

Studentas *ivestiStudentus(int &kiekis);

void padidintiStudentasMasyva(int &kiekis, int &vieta, Studentas *&studentai);

bool studentoUzklausa();

int menu();

#endif