#ifndef IO_H
#define IO_H
#include "studentas.h"
#include <limits>
#include "calc.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

int menu();

bool medianosUzklausa();

bool studentoUzklausa();

bool gautiPatvirtinima(std::string pranesimas);

std::vector<Studentas> ivestiStudentus();

Studentas skaitymas();

void isvestis(const std::vector<Studentas> &A, bool medianos);

void studentoVardoPavardesIvestis(Studentas &A);

void namuDarbuRezultatuIvestis(Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia = false);

bool arTikSkaicius(const std::string& s);

#endif