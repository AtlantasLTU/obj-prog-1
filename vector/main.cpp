#include "main.h"

// ar refactorint bei atnaujint iki tokio pat funkcionalumo masyvu versija, kadangi v0.2 liepta dirbti tik su vector, o dabar jau nebe. Masyvu versija galbut nebenaudojama?
// ar visur naudot try catch ar galima naudot ir return kodus ir t.t.
// 1) restructurint failus.
// 2) template, kad lengviau sort perskaityt
// 3) Prideti isimciu valdyma:
//      a) programa tikrina naudojant klaidų gaudymo mechanizmą ar failas egzistuoja nurodytoje vietoje. 
//      b) programoje turi būti realizuoti duomenų įvesties tikrinimai naudojant klaidų gaudymo mechanizmą (raidžių, žodžių, sveikųjų ir realiųjų skaičių), visi pranešimai turi būti išvedami lietuvių kalbą (unicode naudoti nebūtina).    

int main()
{
    try
    {
        #ifdef _WIN32 // Jei kompiliuojama Windows operacinei sistemai nustatyti konsoles įvestį ir išvestį UTF-8 užkodavimui.
        SetConsoleOutputCP(CP_UTF8); // pakeičiame išvesties code page į UTF-8
        SetConsoleCP(CP_UTF8); // pakeičiame įvesties code page į UTF-8
        #endif
        //pasirinkima galima tobulint su enumeratorium del type safety ir jei butu norima valdyti atminti.
        int pasirinkimas = menu();
        bool failas;
        bool medianos;
        if(pasirinkimas<5)
        {
            failas = !failoUzklausa();
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
                int fPasirinkimas = failoPasirinkimas();
                int rPasirinkimas = rusiavimoPasirinkimas();
                switch(fPasirinkimas){
                    case 1:
                    {
                        failoApdorojimas("kursiokai.txt", 2, ndKiekis, medianos, rPasirinkimas, failas);
                        break;
                    }
                    case 2:
                    {
                        failoApdorojimas("studentai10000.txt", 10000, ndKiekis, medianos, rPasirinkimas, failas);
                        break;
                    }
                    case 3:
                    {   
                        failoApdorojimas("studentai100000.txt", 100000, ndKiekis, medianos, rPasirinkimas, failas);
                        break;
                    }
                    case 4:
                    {
                        failoApdorojimas("studentai1000000.txt", 1000000, ndKiekis, medianos, rPasirinkimas, failas);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 5: // testavimas su failais // kiekviename test case'e uzkomentuota koda arba jo dalis galima atkomentuoti bei keisti parametrus, kad pakeisti kas yra testuojama, kadangi tiksliai neapibrezta pagal ka testuoti.
            {
                int ndKiekis = 0;
                int fPasirinkimas = failoPasirinkimas();
                //int rPasirinkimas = rusiavimoPasirinkimas();
                int tPasirinkimas = testavimoPasirinkimas();
                switch(fPasirinkimas){
                    case 1:
                    {
                        failoTestavimas("kursiokai.txt", 2, tPasirinkimas, ndKiekis);
                        break;
                    }
                    case 2:
                    {
                        failoTestavimas("studentai10000.txt", 10000, tPasirinkimas, ndKiekis);
                        break;
                    }
                    case 3:
                    {   
                        failoTestavimas("studentai100000.txt", 100000, tPasirinkimas, ndKiekis);
                        break;
                    }
                    case 4:
                    {
                        failoTestavimas("studentai1000000.txt", 1000000, tPasirinkimas, ndKiekis);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 6: // darbo baigtis
            {
                std::cout << "Darbas su programa baigtas.";
                return 0;
            }
            default:
            {
                std::cout << "How did we get here?" << std::endl; // https://minecraft.wiki/w/Tutorial:Advancement_guide/How_Did_We_Get_Here%3F
                return 0;
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

void failoTestavimas(std::string failoPavadinimas, int rezervas, int tPasirinkimas, int &ndKiekis)
{
    double bendraTrukme = 0;
    for (int i = 0; i < tPasirinkimas; i++)
    {
        Timer t;
        ndKiekis = 0;
        std::vector<Studentas> studentai = skaitymasIsFailo(failoPavadinimas, ndKiekis, rezervas);
        bendraTrukme += t.elapsed();
        // ar testuoti skaiciavimu greiti?
        /* t.reset();
        skaiciavimas(studentai, medianos, ndKiekis);
        bendraTrukme += t.elapsed(); */
        // ar testuoti sorts?
        /* t.reset();
        rusiavimasSkirstymas(studentai, rPasirinkimas, medianos);
        bendraTrukme += t.elapsed(); */
        // ar testuoti isvedima?
        /* t.reset();
        isvestis(studentai, medianos, failas);
        bendraTrukme += t.elapsed(); */
    }
    std::cout << "Failo įvedimas vidutiniškai užtruko: " << bendraTrukme / tPasirinkimas << "\n";
    std::cout << "Bendra trukmė: " << bendraTrukme << "\n";
}

void failoApdorojimas(std::string failoPavadinimas, int rezervas, int &ndKiekis, bool medianos, int rPasirinkimas, bool failas)
{
    Timer t;
    std::vector<Studentas> studentai = skaitymasIsFailo(failoPavadinimas, ndKiekis, rezervas);
    double skaitymoTrukme = t.elapsed(); // Skirtumas (s)
    t.reset();
    skaiciavimas(studentai, medianos, ndKiekis);
    double skaiciavimoTrukme = t.elapsed();
    t.reset();
    rusiavimasSkirstymas(studentai, rPasirinkimas, medianos);
    double rusiavimoTrukme = t.elapsed();
    t.reset();
    isvestis(studentai, medianos, failas);
    double isvedimoTrukme = t.elapsed(); // Skirtumas (s)
    std::cout << "Failo nuskaitymas į studentai vektorių užtruko: " << skaitymoTrukme << " s\n";
    std::cout << "Rezultatų skaičiavimas užtruko: " << skaiciavimoTrukme << " s\n";
    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: " << rusiavimoTrukme << " s\n";
    std::cout << "Studentų išvedimas užtruko: " << isvedimoTrukme << " s\n";
    std::cout << "Bendra trukmė: " << skaitymoTrukme + skaiciavimoTrukme + rusiavimoTrukme + isvedimoTrukme << " s";
}
