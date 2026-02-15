#include "studentas.h"
#include <limits>
#include "calc.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;


Studentas skaitymas();

void studentoVardoPavardesIvestis(std::string &eilute, Studentas &A);

void namuDarbuRezultatuIvestis(std::string &eilute, Studentas &A);

void egzaminoRezultatoIvestis(Studentas &A);

void isvestis(Studentas &A, bool medianos);
