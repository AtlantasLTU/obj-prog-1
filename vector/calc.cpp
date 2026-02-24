#include "calc.h"
#include <algorithm>

double galutinisVid(const Studentas &A){
    if(A.nd.empty() && maxNdKiekis == 0) return 0.6*A.rez;

    int sum = 0;
    for(int x : A.nd) // for_each X in vector A.nd, sum+=x
        sum += x;

    double vid = (double)sum / maxNdKiekis;
    return 0.4 * vid + 0.6 * A.rez;
}


double galutinisMed(const Studentas &A){
    if(A.nd.empty() && maxNdKiekis == 0) return 0.6*A.rez;

    std::vector<int> nd = A.nd;
    while(nd.size() < maxNdKiekis){ // jei nd masyvas mazesnis uz didziausia ndKieki, tai ji uzpildo nuliais
        nd.push_back(0);
    }
    std::sort(nd.begin(), nd.end());

    double med =
        (maxNdKiekis % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (nd.at(maxNdKiekis/2) + nd.at(maxNdKiekis/2 - 1)) / 2.0
        : nd.at(maxNdKiekis/2);

    return 0.4 * med + 0.6 * A.rez;
}

double galutinisVidF(const StudentasF &A, std::vector<int> nd, int rez, int ndKiekis){
    if(ndKiekis == 0) return 0.6*rez;

    int sum = 0;
    for(int x : nd) // for_each X in vector A.nd, sum+=x
        sum += x;

    double vid = (double)sum / ndKiekis;
    return 0.4 * vid + 0.6 * rez;
}


double galutinisMedF(const StudentasF &A, std::vector<int> nd, int rez, int ndKiekis){
    if(ndKiekis == 0) return 0.6*rez;

    /* while(nd.size() < maxNdKiekis){ // jei nd masyvas mazesnis uz didziausia ndKieki, tai ji uzpildo nuliais
        nd.push_back(0);
    } */
    std::sort(nd.begin(), nd.end());

    double med =
        (ndKiekis % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (nd.at(ndKiekis/2) + nd.at(ndKiekis/2 - 1)) / 2.0
        : nd.at(ndKiekis/2);

    return 0.4 * med + 0.6 * rez;
}