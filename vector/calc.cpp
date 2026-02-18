#include "calc.h"
#include <algorithm>

double galutinisVid(const Studentas &A){
    if(A.nd.empty()) return 0.6*A.rez;

    int sum = 0;
    for(int x : A.nd) // for_each X in vector A.nd, sum+=x
        sum += x;

    double vid = (double)sum / A.nd.size();
    return 0.4 * vid + 0.6 * A.rez;
}


double galutinisMed(const Studentas &A){
    if(A.nd.empty()) return 0.6*A.rez;

    std::vector<int> nd = A.nd;
    std::sort(nd.begin(), nd.end());

    double med =
        (nd.size() % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (nd[nd.size()/2] + nd[nd.size()/2 - 1]) / 2.0
        : nd[nd.size()/2];

    return 0.4 * med + 0.6 * A.rez;
}