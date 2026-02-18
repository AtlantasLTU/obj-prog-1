#include "calc.h"
#include <algorithm>

double galutinisVid(const Studentas &A){
    if(A.ndKiekis==0) return 0.6*A.rez;

    int sum = 0;
    for(int x = 0; x < A.ndKiekis; x++) // is A.nd masyvo prideda kiekviena nari.
        sum += A.nd[x];

    double vid = (double)sum / A.ndKiekis;
    return 0.4 * vid + 0.6 * A.rez;
}


double galutinisMed(const Studentas &A){
    if(A.ndKiekis==0) return 0.6*A.rez;

    int* nd = new int[A.ndKiekis];

    for(int i=0;i<A.ndKiekis;i++)
        nd[i] = A.nd[i];

    std::sort(nd, nd + A.ndKiekis);

    double med =
        (A.ndKiekis % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (nd[A.ndKiekis/2] + nd[A.ndKiekis/2 - 1]) / 2.0
        : nd[A.ndKiekis/2];

    double rezultatas = 0.4 * med + 0.6 * A.rez;
    delete[] nd;
    
    return rezultatas;
}