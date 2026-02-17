#include "calc.h"
#include <algorithm>

float galutinisVid(const Studentas &A){
    if(A.nd.empty()) return 0.6f*A.rez;

    int sum = 0;
    for(int x : A.nd) // for_each X in vector A.nd, sum+=x
        sum += x;

    float vid = (float)sum / A.nd.size();
    return 0.4f * vid + 0.6f * A.rez;
}


float galutinisMed(const Studentas &A){
    if(A.nd.empty()) return 0;

    std::vector<int> nd = A.nd;
    std::sort(nd.begin(), nd.end());

    int size = nd.size();
    float med =
        (size % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (nd[size/2] + nd[size/2 - 1]) / 2.0f
        : nd[size/2];

    return 0.4f * med + 0.6f * A.rez; // naudojama f, kad skaiciavimai butu atliekami su grynais float'ais, o ne double, nes paprastai 0.4 laikomas double. Beje, mum nereikia tokiu tiksliu vidurkiu, kaip double leistu, taigi sutaupom atminties.
}