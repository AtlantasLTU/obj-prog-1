#ifndef IO_H
#define IO_H
#include "studentas.h"
#include <limits>
#include "calc.h"
#include <iostream>
#include <sstream>
#include <iomanip>

int menu();

bool medianosUzklausa();

bool studentoUzklausa();

bool gautiPatvirtinima(std::string pranesimas);

Studentas *ivestiStudentus(int &kiekis);

void padidintiStudentasMasyva(int &kiekis, int &vieta, Studentas *&studentai);

Studentas skaitymas();

void isvestis(const Studentas *A, int kiekis, bool medianos);

void studentoVardoPavardesIvestis(Studentas &A);

void namuDarbuRezultatuIvestis(Studentas &A);

void pridetiNd(Studentas &A, int paz);

void egzaminoRezultatoIvestis(Studentas &A);

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia = false);

bool arTikSkaicius(const std::string& eilute);

#endif