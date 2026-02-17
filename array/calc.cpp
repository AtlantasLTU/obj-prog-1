#include "calc.h"
#include <algorithm>

float galutinisVid(const Studentas &A){
    if(A.ndKiekis==0) return 0.6f*A.rez;

    int sum = 0;
    for(int x = 0; x < A.ndKiekis; x++) // is A.nd masyvo prideda kiekviena nari.
        sum += A.nd[x];

    float vid = (float)sum / A.ndKiekis;
    return 0.4f * vid + 0.6f * A.rez;
}


float galutinisMed(const Studentas &A){
    if(A.ndKiekis==0) return 0;

    int* nd = new int[A.ndKiekis];

    for(int i=0;i<A.ndKiekis;i++)
        nd[i] = A.nd[i];

    std::sort(nd, nd + A.ndKiekis);

    int size = A.ndKiekis;
    float med =
        (size % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (nd[size/2] + nd[size/2 - 1]) / 2.0f
        : nd[size/2];

    float rezultatas = 0.4f * med + 0.6f * A.rez; // naudojama f, kad skaiciavimai butu atliekami su grynais float'ais, o ne double, nes paprastai 0.4 laikomas double. Beje, mum nereikia tokiu tiksliu vidurkiu, kaip double leistu, taigi sutaupom atminties. 
    
    delete[] nd;
    
    return rezultatas;
}