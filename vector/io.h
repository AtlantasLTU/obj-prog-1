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

Studentas skaitymas();

void studentoVardoPavardesIvestis(Studentas &A);

void namuDarbuRezultatuIvestis(Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia = false);

bool arTikSkaicius(const std::string& s);

bool gautiPatvirtinima(std::string pranesimas);

void isvestis(const std::vector<Studentas> &A, bool medianos);

bool medianosUzklausa();

std::vector<Studentas> ivestiStudentus();

bool studentoUzklausa();

int menu();

#endif