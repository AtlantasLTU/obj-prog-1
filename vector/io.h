#ifndef IO_H
#define IO_H
#include "studentas.h"
#include <limits>
#include "calc.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

Studentas skaitymas();

void studentoVardoPavardesIvestis(Studentas &A);

void namuDarbuRezultatuIvestis(Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

void isvestis(const std::vector<Studentas> &A, bool medianos);

bool medianosUzklausa();

std::vector<Studentas> ivestiStudentus();

bool studentoUzklausa();

int menu();

#endif