#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>

struct Studentas {
    std::string vardas, pavarde;
    int *nd = nullptr;
    int ndKiekis = 0;
    int ndVieta = 0;
    int rez = 0;
};

#endif // STUDENTAS_H
