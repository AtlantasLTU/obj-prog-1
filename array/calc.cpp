#include "calc.h"
#include <algorithm>

double galutinisVid(const Studentas &A){
    if(A.ndKiekis==0 && maxNdKiekis == 0) return 0.6*A.rez;

    int sum = 0;
    for(int x = 0; x < A.ndKiekis; x++) // is A.nd masyvo prideda kiekviena nari.
        sum += A.nd[x];

    double vid = (double)sum / maxNdKiekis;
    return 0.4 * vid + 0.6 * A.rez;
}


double galutinisMed(const Studentas &A){
    if(A.ndKiekis==0 && maxNdKiekis == 0) return 0.6*A.rez;

    int* nd = new int[maxNdKiekis];

    for(int i = 0;i<A.ndKiekis;i++)
        nd[i] = A.nd[i];

    for(int i = A.ndKiekis; i < maxNdKiekis; i++){
        nd[i] = 0;
    }

    std::sort(nd, nd + maxNdKiekis);

    double med =
        (maxNdKiekis % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (nd[maxNdKiekis/2] + nd[maxNdKiekis/2 - 1]) / 2.0
        : nd[maxNdKiekis/2];

    double rezultatas = 0.4 * med + 0.6 * A.rez;
    delete[] nd;
    
    return rezultatas;
}