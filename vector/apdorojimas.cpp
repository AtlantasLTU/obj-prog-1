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

void rusiavimasSkirstymas(std::vector<Studentas> &studentai, int rPasirinkimas, bool medianos){
    switch(rPasirinkimas){
        case 1:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.vardas < B.vardas;
            });
            break;
        }
        case 2:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.vardas > B.vardas;
            });
            break;
        }
        case 3:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.pavarde < B.pavarde;
            });
            break;
        }
        case 4:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.pavarde > B.pavarde;
            });
            break;
        }
        case 5:
        {
            std::sort(studentai.begin(), studentai.end(), [medianos](const Studentas &A, const Studentas &B){
                if(medianos) return A.galutinisMed < B.galutinisMed;
                return A.galutinisVid < B.galutinisVid;
            });
            break;
        }
        case 6:
        {
            std::sort(studentai.begin(), studentai.end(), [medianos](const Studentas &A, const Studentas &B){
                if(medianos) return A.galutinisMed > B.galutinisMed;
                return A.galutinisVid > B.galutinisVid;
            });
            break;
        }
        default:
        {
            break;
        }
    }
}