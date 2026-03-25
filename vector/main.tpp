#include "main.h"
#include "apdorojimas.tpp"
#include "isvestis.tpp"

template<class Konteineris>
void failoTestavimas(const std::string &failoPavadinimas, int rezervas, int tPasirinkimas, int &ndKiekis, bool medianos)
{
    double skaitymoTrukme = 0;
    double skaiciavimoTrukme = 0;
    double rusiavimoTrukme = 0;
    double skirstymoTrukme = 0;
    double isvedimoTrukme1 = 0;
    double isvedimoTrukme2 = 0;
    ndKiekis = 0;
    Konteineris studentai = skaitymasIsFailo<Konteineris>(failoPavadinimas, ndKiekis, rezervas); // nuskaitymas
    skaiciavimas<Konteineris>(studentai, medianos, ndKiekis); // rezultatu apsiskaiciavimas pries rikiavima
    rusiavimasSkirstymas(studentai, 5); // rusiavimas didejanciai
    Konteineris galvociai;
    Konteineris vargsiukai;
    if constexpr(requires(Konteineris konteineris){konteineris.reserve(0);}){
        galvociai.reserve(studentai.size());
        vargsiukai.reserve(studentai.size());
    }
    skirstymasStrat2(studentai, vargsiukai); // skirstymas i galvocius ir vargsiukus
/*     isvestis(galvociai, medianos, true, "galvociai.txt");
    isvestis(vargsiukai, medianos, true, "vargsiukai.txt"); */
    for(int i = 0; i < tPasirinkimas; i++)
    {   
        ndKiekis = 0;
        Timer t;
        Konteineris studentai = skaitymasIsFailo<Konteineris>(failoPavadinimas, ndKiekis, rezervas); // nuskaitymas
        skaitymoTrukme += t.elapsed(); // Skirtumas (s)
/*         t.reset(); */
        skaiciavimas<Konteineris>(studentai, medianos, ndKiekis); // rezultatu apsiskaiciavimas pries rikiavima
/*         skaiciavimoTrukme += t.elapsed(); */
        t.reset();
        rusiavimasSkirstymas(studentai, 5); // rusiavimas didejanciai
        rusiavimoTrukme += t.elapsed();
        t.reset();
        Konteineris galvociai;
        Konteineris vargsiukai;
        if constexpr (requires(Konteineris konteineris){konteineris.reserve(0);}){
            galvociai.reserve(studentai.size());
            vargsiukai.reserve(studentai.size());
        }
        skirstymasStrat2(studentai, vargsiukai); // skirstymas i galvocius ir vargsiukus
        skirstymoTrukme += t.elapsed();
/*         t.reset(); */
        isvestis(studentai, medianos, true, "rezultatai.txt");
/*         isvedimoTrukme1 += t.elapsed(); // Skirtumas (s)
        t.reset();
        isvestis(vargsiukai, medianos, true, "vargsiukai.txt");
        isvedimoTrukme2 += t.elapsed(); // Skirtumas (s) */
    }
    std::cout << "Failo nuskaitymas į studentai konteinerį vidutiniškai užtruko: " << skaitymoTrukme/tPasirinkimas << " s\n";
/*     std::cout << "Rezultatų skaičiavimas vidutiniškai užtruko: " << skaiciavimoTrukme/tPasirinkimas << " s\n"; */
    std::cout << "Duomenų rūšiavimas didėjančiai vidutiniškai užtruko: " << rusiavimoTrukme/tPasirinkimas << " s\n";
    std::cout << "Studentų skirstymas pagal pažymius vidutiniškai užtruko: " << skirstymoTrukme/tPasirinkimas << " s\n";
/*     std::cout << "Studentų išvedimas į vargsiukai.txt vidutiniškai užtruko: " << isvedimoTrukme1/tPasirinkimas << " s\n";
    std::cout << "Studentų išvedimas į galvociai.txt vidutiniškai užtruko: " << isvedimoTrukme2/tPasirinkimas << " s\n"; */
    std::cout << "Bendra trukmė: " << skaitymoTrukme + skaiciavimoTrukme + rusiavimoTrukme + skirstymoTrukme + isvedimoTrukme1 + isvedimoTrukme2 << " s\n";
}