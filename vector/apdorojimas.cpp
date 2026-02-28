#include "apdorojimas.h"

void skaiciavimas(std::vector<Studentas> &A, bool medianos, int ndKiekis){
    if(medianos)
    {
        for(Studentas &X : A){
            X.galutinisMed = galutinisMedF(X, ndKiekis);
        }
    }
    else
    {
        for(Studentas &X : A){
            X.galutinisVid = galutinisVidF(X, ndKiekis);
        }
    }
}

void skaiciavimas(std::vector<Studentas> &A, bool medianos){
    if(medianos)
    {
        for(Studentas &X : A){
            X.galutinisMed = galutinisMed(X);
        }
    }
    else
    {
        for(Studentas &X : A){
            X.galutinisVid = galutinisVid(X);
        }
    }
}

template<class T>
void rusiavimasPagal(std::vector<Studentas> &studentai, T lambdaFunkcija, bool didejanciai = true)
{
    std::sort(studentai.begin(), studentai.end(),
        [didejanciai, lambdaFunkcija](const Studentas &A, const Studentas &B)
        {
            return didejanciai ? lambdaFunkcija(A) < lambdaFunkcija(B) : lambdaFunkcija(A) > lambdaFunkcija(B); // lambdaFunkcija(A) prilygsta kad i funkcija [](const Studentas &studentas){return studentas.vardas;} perduotas studentas A ir na, tas pats su B
        }
    );
}

void rusiavimasSkirstymas(std::vector<Studentas> &studentai, int rPasirinkimas, bool medianos){
    switch(rPasirinkimas){
        case 1: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.vardas;}); break;
        case 2: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.vardas;}, false); break;
        case 3: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.pavarde;}); break;
        case 4: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.pavarde;}, false); break;
        case 5: rusiavimasPagal(studentai, [medianos](const Studentas &studentas){return medianos ? studentas.galutinisMed : studentas.galutinisVid;}); break;
        case 6: rusiavimasPagal(studentai, [medianos](const Studentas &studentas){return medianos ? studentas.galutinisMed : studentas.galutinisVid;}, false); break;
        default:
        {
            break;
        }
    }
}