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
#include <chrono>
#include <fstream>

int menu();

int failoPasirinkimas();

int rusiavimoPasirinkimas();

int testavimoPasirinkimas();

bool medianosUzklausa();

bool failoUzklausa();

bool gautiPatvirtinima(std::string pranesimas);

std::vector<Studentas> ivestiStudentus();

bool skaitymas(Studentas &A);

void isvestis(const std::vector<Studentas> &A, bool medianos, bool failas = true);

int lietuviskosRaides(const std::string& eilute);

/* void isvedimas(const std::vector<Studentas> &A, bool failas = true);
 */
bool studentoVardoPavardesIvestis(Studentas &A, std::string &eilute);

void namuDarbuRezultatuIvestis(Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia = false);

bool arTikSkaicius(const std::string &s);

std::vector<Studentas> skaitymasIsFailo(std::string failoPavadinimas, int &ndKiekis, int rezervas = 0);

void skaiciavimas(std::vector<Studentas> &A, bool medianos, int ndKiekis);

void skaiciavimas(std::vector<Studentas> &A, bool medianos);

void rusiavimasSkirstymas(std::vector<Studentas> &A, int rPasirinkimas, bool medianos);

#endif