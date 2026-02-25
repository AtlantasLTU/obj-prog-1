#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#define maxNdKiekis 10

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> nd;
    int rez;
    double galutinisVid = 0;
    double galutinisMed = 0;
};

#endif // STUDENTAS_H
