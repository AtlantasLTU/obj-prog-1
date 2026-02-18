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

bool gautiPatvirtinima(std::string pranesimas);

std::vector<Studentas> ivestiStudentus();

bool skaitymas(Studentas &A);

void isvestis(const std::vector<Studentas> &A, bool medianos);

bool studentoVardoPavardesIvestis(Studentas &A, std::string& eilute);

void namuDarbuRezultatuIvestis(Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia = false);

bool arTikSkaicius(const std::string& s);

#endif