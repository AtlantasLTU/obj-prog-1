#include "apdorojimas.h"
#include "studVPGen.h"
#include "random.h"
#include <fstream>

void skaiciavimas(std::vector<Studentas> &A, bool medianos, int ndKiekis){
    if(medianos)
    {
        for(Studentas &X : A){
            X.galutinis = galutinisMedF(X, ndKiekis);
        }
    }
    else
    {
        for(Studentas &X : A){
            X.galutinis = galutinisVidF(X, ndKiekis);
        }
    }
}

void skaiciavimas(std::vector<Studentas> &A, bool medianos){
    if(medianos)
    {
        for(Studentas &X : A){
            X.galutinis = galutinisMed(X);
        }
    }
    else
    {
        for(Studentas &X : A){
            X.galutinis = galutinisVid(X);
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
        case 5: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.galutinis;}); break;
        case 6: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.galutinis;}, false); break;
        default:
        {
            break;
        }
    }
}

void failoGeneravimas(int studentuKiekis, int ndKiekis)
{
    std::ostringstream out;
    out << std::left << std::setw(20) << "Vardas" << std::setw(21) << "Pavardė";
    for(int i = 1; i <= ndKiekis; i++){
        out << std::left << std::setw(10) << "ND"+std::to_string(i);
    }
    out << "Egz.\n";
    for(int i = 0; i < studentuKiekis; i++){
        Studentas A;
        gen_map(A);
        namuDarbuRezultataiRandom(A, ndKiekis);
        egzaminoRezultatasRandom(A);
        out << std::left << std::setw(20) << A.vardas << std::setw(20) << A.pavarde;
        for(int j = 0; j < ndKiekis; j++){
            out << std::left << std::setw(10) << A.nd.at(j);
        }
        out << std::left << A.rez << "\n";
    }
    std::string failoPavadinimas = std::string("studentai") + std::to_string(studentuKiekis) + ".txt";
    std::ofstream fout(failoPavadinimas);
    fout << out.str();
    fout.close();
}

void skirstymas(std::vector<Studentas> &studentai, std::vector<Studentas> &galvociai, std::vector<Studentas> &vargsiukai)
{
    for(Studentas &A : studentai)
    {
        if(A.galutinis<5){
            vargsiukai.push_back(std::move(A));
        } else {
            galvociai.push_back(std::move(A));
        }
    }
}