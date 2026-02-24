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

bool medianosUzklausa();

bool gautiPatvirtinima(std::string pranesimas);

std::vector<Studentas> ivestiStudentus();

bool skaitymas(Studentas &A);

void isvestis(const std::vector<Studentas> &A, bool medianos);

void isvedimas(const std::vector<StudentasF> &A);

bool studentoVardoPavardesIvestis(Studentas &A, std::string& eilute);

void namuDarbuRezultatuIvestis(Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia = false);

bool arTikSkaicius(const std::string& s);

std::vector<StudentasF> skaitymasIsFailo(std::string failoPavadinimas, int rezervas = 0);

void rusiavimasSkirstymas(std::vector<StudentasF> &A, int rPasirinkimas);

#endif