#ifndef IVESTIS_H
#define IVESTIS_H

#include "studentas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

bool gautiPatvirtinima(std::string pranesimas);

std::vector<Studentas> ivestiStudentus();

bool skaitymas(Studentas &A);

bool studentoVardoPavardesIvestis(Studentas &A, std::string &eilute);

void namuDarbuRezultatuIvestis(Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia = false);

bool arTikSkaicius(const std::string &s);

std::vector<Studentas> skaitymasIsFailo(std::string failoPavadinimas, int &ndKiekis, int rezervas = 0);

#endif