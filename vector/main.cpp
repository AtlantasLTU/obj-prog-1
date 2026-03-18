#include "main.h"

// programoje turi atsirasti realizacija su deque ir list, vector PALIEKAM
// matuoti duomenu nuskaityma is failu i atitinkama konteineri (failai islieka tokie patys)
// studentu rusiavimas didejimo tvarka (funkcija sort);
// studentu skirstymas i dvi grupes/kategorijas vargsiukai ir galvociai
int main()
{
    try
    {
        #ifdef _WIN32 // Jei kompiliuojama Windows operacinei sistemai nustatyti konsoles įvestį ir išvestį UTF-8 užkodavimui.
        SetConsoleOutputCP(CP_UTF8); // pakeičiame išvesties code page į UTF-8
        SetConsoleCP(CP_UTF8); // pakeičiame įvesties code page į UTF-8
        #endif
        bool veikimas = true;
        while(veikimas)
        {
            //pasirinkima galima tobulint su enumeratorium del type safety ir jei butu norima valdyti atminti.
            int pasirinkimas = menu();
            bool failas = false;
            bool medianos = false;
            if(pasirinkimas<5)
            {
                failas = !failoUzklausa();
                medianos = medianosUzklausa();
            } else if(pasirinkimas == 5){
                medianos = medianosUzklausa();
            }

            switch(pasirinkimas){
                case 1: // rankinis ivedimas
                {
                    std::vector<Studentas> studentai = ivestiStudentus();
                    skaiciavimas(studentai, medianos);
                    isvestis(studentai, medianos, failas);
                    break;
                }
                case 2: // tik pazymiu generavimas.
                {
                    std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
                    skaiciavimas(studentai, medianos);
                    isvestis(studentai, medianos, failas);
                    break;
                }
                case 3: // studentu ir pazymiu generavimas;
                {
                    std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
                    skaiciavimas(studentai, medianos);
                    isvestis(studentai, medianos, failas);
                    break;
                }
                case 4: // skaitymas is failo
                {
                    int ndKiekis = 0;
                    int rezervas = 0;
                    std::string fPasirinkimas;
                    failoPasirinkimas(rezervas, fPasirinkimas);
                    int rPasirinkimas = rusiavimoPasirinkimas();
                    failoApdorojimas(fPasirinkimas, rezervas, ndKiekis, medianos, rPasirinkimas, failas);
                    break;
                }
                case 5: // testavimas su failais // kiekviename test case'e uzkomentuota koda arba jo dalis galima atkomentuoti bei keisti parametrus, kad pakeisti kas yra testuojama, kadangi tiksliai neapibrezta pagal ka testuoti.
                {
                    int ndKiekis = 0;
                    int rezervas = 0;
                    std::string fPasirinkimas;
                    failoPasirinkimas(rezervas, fPasirinkimas);
                    //int rPasirinkimas = rusiavimoPasirinkimas();
                    int tPasirinkimas = testavimoPasirinkimas();
                    if(tPasirinkimas <= 0) throw std::invalid_argument("Testavimo skaičius turi būti daugiau už 0!");
                    failoTestavimas(fPasirinkimas, rezervas, tPasirinkimas, ndKiekis, medianos);
                    break;
                }
                case 6:
                {   
                    int studentuKiekis = studentuPasirinkimas();
                    int ndKiekis = ndPasirinkimas();
                    int tPasirinkimas = testavimoPasirinkimas();
                    if(tPasirinkimas <= 0) throw std::invalid_argument("Testavimo skaičius turi būti daugiau už 0!");
                    double trukme = 0;
                    for(int i = 0; i < tPasirinkimas+1; i++)
                    {
                        if(i!=0)
                        {
                            Timer t;
                            failoGeneravimas(studentuKiekis, ndKiekis);
                            trukme += t.elapsed();
                        }
                        else
                        {
                            failoGeneravimas(studentuKiekis, ndKiekis);
                        }
                    }
                    std::cout << "Failų(-o) generavimas vidutiniškai užtruko: " << trukme/tPasirinkimas << " s\n";
                    break;
                }
                case 7: // darbo baigtis
                {
                    std::cout << "Darbas su programa baigtas.";
                    veikimas = false;
                    return 0;
                }
                default:
                {
                    std::cout << "How did we get here?" << std::endl; // https://minecraft.wiki/w/Tutorial:Advancement_guide/How_Did_We_Get_Here%3F
                    return 0;
                }
            }
        }
    }
    catch(const std::exception &klaida)
    {
        std::cerr << klaida.what() << "\n";
        return 1;
    }
    return 0;
}

void failoTestavimas(const std::string &failoPavadinimas, int rezervas, int tPasirinkimas, int &ndKiekis, bool medianos)
{
    double skaitymoTrukme = 0;
    double skaiciavimoTrukme = 0;
    double rusiavimoTrukme = 0;
    double skirstymoTrukme = 0;
    double isvedimoTrukme1 = 0;
    double isvedimoTrukme2 = 0;
    for(int i = 0; i < tPasirinkimas+1; i++)
    {   
        ndKiekis = 0;
        if(i!=0)
        {
            Timer t;
            std::vector<Studentas> studentai = skaitymasIsFailo(failoPavadinimas, ndKiekis, rezervas);
            skaitymoTrukme += t.elapsed(); // Skirtumas (s)
            t.reset();
            skaiciavimas(studentai, medianos, ndKiekis);
            skaiciavimoTrukme += t.elapsed();
            t.reset();
            rusiavimasSkirstymas(studentai, 5);
            rusiavimoTrukme += t.elapsed();
            t.reset();
            std::vector<Studentas> galvociai;
            std::vector<Studentas> vargsiukai;
            galvociai.reserve(studentai.size());
            vargsiukai.reserve(studentai.size());
            skirstymas(studentai, galvociai, vargsiukai);
            skirstymoTrukme += t.elapsed();
            t.reset();
            isvestis(galvociai, medianos, true, "galvociai.txt");
            isvedimoTrukme1 += t.elapsed(); // Skirtumas (s)
            t.reset();
            isvestis(vargsiukai, medianos, true, "vargsiukai.txt");
            isvedimoTrukme2 += t.elapsed(); // Skirtumas (s)
        } 
        else 
        {
            std::vector<Studentas> studentai = skaitymasIsFailo(failoPavadinimas, ndKiekis, rezervas);
            skaiciavimas(studentai, medianos, ndKiekis);
            rusiavimasSkirstymas(studentai, 5);
            std::vector<Studentas> galvociai;
            std::vector<Studentas> vargsiukai;
            galvociai.reserve(studentai.size());
            vargsiukai.reserve(studentai.size());
            skirstymas(studentai, galvociai, vargsiukai);
            isvestis(galvociai, medianos, true, "galvociai.txt");
        }
    }
    std::cout << "Failo nuskaitymas į studentai vektorių vidutiniškai užtruko: " << skaitymoTrukme/tPasirinkimas << " s\n";
    std::cout << "Rezultatų skaičiavimas vidutiniškai užtruko: " << skaiciavimoTrukme/tPasirinkimas << " s\n";
    std::cout << "Duomenų rūšiavimas didėjančiai vidutiniškai užtruko: " << rusiavimoTrukme/tPasirinkimas << " s\n";
    std::cout << "Studentų skirstymas pagal pažymius vidutiniškai užtruko: " << skirstymoTrukme/tPasirinkimas << " s\n";
    std::cout << "Studentų išvedimas į vargsiukai.txt vidutiniškai užtruko: " << isvedimoTrukme1/tPasirinkimas << " s\n";
    std::cout << "Studentų išvedimas į galvociai.txt vidutiniškai užtruko: " << isvedimoTrukme2/tPasirinkimas << " s\n";
    std::cout << "Bendra trukmė: " << skaitymoTrukme + skaiciavimoTrukme + rusiavimoTrukme + skirstymoTrukme + isvedimoTrukme1 + isvedimoTrukme2 << " s\n";
}

void failoApdorojimas(const std::string &failoPavadinimas, int rezervas, int &ndKiekis, bool medianos, int rPasirinkimas, bool failas)
{
    Timer t;
    std::vector<Studentas> studentai = skaitymasIsFailo(failoPavadinimas, ndKiekis, rezervas);
    double skaitymoTrukme = t.elapsed(); // Skirtumas (s)
    t.reset();
    skaiciavimas(studentai, medianos, ndKiekis);
    double skaiciavimoTrukme = t.elapsed();
    t.reset();
    rusiavimasSkirstymas(studentai, rPasirinkimas);
    double rusiavimoTrukme = t.elapsed();
    t.reset();
    isvestis(studentai, medianos, failas);
    double isvedimoTrukme = t.elapsed(); // Skirtumas (s)
    std::cout << "Failo nuskaitymas į studentai vektorių užtruko: " << skaitymoTrukme << " s\n";
    std::cout << "Rezultatų skaičiavimas užtruko: " << skaiciavimoTrukme << " s\n";
    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: " << rusiavimoTrukme << " s\n";
    std::cout << "Studentų išvedimas užtruko: " << isvedimoTrukme << " s\n";
    std::cout << "Bendra trukmė: " << skaitymoTrukme + skaiciavimoTrukme + rusiavimoTrukme + isvedimoTrukme << " s\n";
}