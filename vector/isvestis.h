#ifndef ISVESTIS_H
#define ISVESTIS_H

#include "studentas.h"
#include <iomanip>
#include <iostream>
#include <fstream>

int menu();

int failoPasirinkimas();

int rusiavimoPasirinkimas();

int testavimoPasirinkimas();

int studentuPasirinkimas();

int ndPasirinkimas();

bool medianosUzklausa();

bool failoUzklausa();

void isvestis(const std::vector<Studentas> &A, bool medianos, bool failas = true, const std::string &failoPavadinimas = "rezultatai.txt");

int lietuviskosRaides(const std::string& eilute);

#endif