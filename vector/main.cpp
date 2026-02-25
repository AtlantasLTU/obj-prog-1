#include <iostream>
#include <string>
#include <vector>

//Header file includes
#include "io.h"
#include "random.h"
#include "Timer.h"

//namespaces
using std::vector;
using std::cin;
using std::cout;
using namespace std::chrono;

#ifdef _WIN32 // naudojame preprocesorių, kad kompiliatorius, naudojant Windows, pridėtų windows.h antraščių failą, kad vėliau galėtume pakeistį terminalo išvesties ir įvesties užkodavimą į UTF-8
#include <windows.h> // windows antraščių failas
#endif

//prideti failu testavima
//kadangi negalima turet antros strukturos, tai naudot sena, ja papildyt
//isvesti pritaikyti irgi

int main()
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
                    Timer t; 
                    std::vector<Studentas> studentai = skaitymasIsFailo("kursiokai.txt", ndKiekis, 2);
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
                    std::cout << "Failo nuskaitymas į studentai vektorių užtruko: "<< skaitymoTrukme << " s\n";
                    std::cout << "Rezultatų skaičiavimas užtruko: " << skaiciavimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << skaitymoTrukme+skaiciavimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
                    break;
                }
                case 2:
                {
                    Timer t; 
                    std::vector<Studentas> studentai = skaitymasIsFailo("studentai10000.txt", ndKiekis, 10000);
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
                    std::cout << "Failo nuskaitymas į studentai vektorių užtruko: "<< skaitymoTrukme << " s\n";
                    std::cout << "Rezultatų skaičiavimas užtruko: " << skaiciavimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << skaitymoTrukme+skaiciavimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
                    break;
                }
                case 3:
                {   
                    Timer t; 
                    std::vector<Studentas> studentai = skaitymasIsFailo("studentai100000.txt", ndKiekis, 100000);
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
                    std::cout << "Failo nuskaitymas į studentai vektorių užtruko: "<< skaitymoTrukme << " s\n";
                    std::cout << "Rezultatų skaičiavimas užtruko: " << skaiciavimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << skaitymoTrukme+skaiciavimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
                    break;
                }
                case 4:
                {
                    Timer t; 
                    std::vector<Studentas> studentai = skaitymasIsFailo("studentai1000000.txt", ndKiekis, 1000000);
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
                    std::cout << "Failo nuskaitymas į studentai vektorių užtruko: "<< skaitymoTrukme << " s\n";
                    std::cout << "Rezultatų skaičiavimas užtruko: " << skaiciavimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << skaitymoTrukme+skaiciavimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
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
                    double bendraTrukme=0;
                    for(int i = 0; i < tPasirinkimas; i++){
                        Timer t; 
                        std::vector<Studentas> studentai = skaitymasIsFailo("kursiokai.txt", ndKiekis, 2);
                        bendraTrukme += t.elapsed();
                        //ar testuoti skaiciavimu greiti?
                        /* t.reset();
                        skaiciavimas(studentai, medianos, ndKiekis);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti sorts?
                        /* t.reset();
                        rusiavimasSkirstymas(studentai, rPasirinkimas, medianos);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti isvedima?
                        /* t.reset();
                        isvestis(studentai, medianos, failas);
                        bendraTrukme += t.elapsed(); */
                    }   
                    std::cout << "Failo įvedimas vidutiniškai užtruko: " << bendraTrukme/tPasirinkimas << "\n";
                    std::cout << "Bendra trukmė: " << bendraTrukme << "\n";
                    break;
                }
                case 2:
                {
                    double bendraTrukme=0;
                    for(int i = 0; i < tPasirinkimas; i++){
                        Timer t; 
                        std::vector<Studentas> studentai = skaitymasIsFailo("studentai10000.txt", ndKiekis, 10000);
                        bendraTrukme += t.elapsed();
                        //ar testuoti skaiciavimu greiti?
                        /* t.reset();
                        skaiciavimas(studentai, medianos, ndKiekis);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti sorts?
                        /* t.reset();
                        rusiavimasSkirstymas(studentai, rPasirinkimas, medianos);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti isvedima?
                        /* t.reset();
                        isvestis(studentai, medianos, failas);
                        bendraTrukme += t.elapsed(); */
                    }   
                    std::cout << "Failo įvedimas vidutiniškai užtruko: " << bendraTrukme/tPasirinkimas << "\n";
                    std::cout << "Bendra trukmė: " << bendraTrukme << "\n";
                    break;
                }
                case 3:
                {   
                    double bendraTrukme=0;
                    for(int i = 0; i < tPasirinkimas; i++){
                        Timer t; 
                        std::vector<Studentas> studentai = skaitymasIsFailo("studentai100000.txt", ndKiekis, 100000);
                        bendraTrukme += t.elapsed();
                        //ar testuoti skaiciavimu greiti?
                        /* t.reset();
                        skaiciavimas(studentai, medianos, ndKiekis);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti sorts?
                        /* t.reset();
                        rusiavimasSkirstymas(studentai, rPasirinkimas, medianos);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti isvedima?
                        /* t.reset();
                        isvestis(studentai, medianos, failas);
                        bendraTrukme += t.elapsed(); */
                    }   
                    std::cout << "Failo įvedimas vidutiniškai užtruko: " << bendraTrukme/tPasirinkimas << "\n";
                    std::cout << "Bendra trukmė: " << bendraTrukme << "\n";
                    break;
                }
                case 4:
                {
                    double bendraTrukme=0;
                    for(int i = 0; i < tPasirinkimas; i++){
                        Timer t; 
                        std::vector<Studentas> studentai = skaitymasIsFailo("studentai1000000.txt", ndKiekis, 1000000);
                        bendraTrukme += t.elapsed();
                        //ar testuoti skaiciavimu greiti?
                        /* t.reset();
                        skaiciavimas(studentai, medianos, ndKiekis);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti sorts?
                        /* t.reset();
                        rusiavimasSkirstymas(studentai, rPasirinkimas, medianos);
                        bendraTrukme += t.elapsed(); */
                        //ar testuoti isvedima?
                        /* t.reset();
                        isvestis(studentai, medianos, failas);
                        bendraTrukme += t.elapsed(); */
                    }   
                    std::cout << "Failo įvedimas vidutiniškai užtruko: " << bendraTrukme/tPasirinkimas << "\n";
                    std::cout << "Bendra trukmė: " << bendraTrukme << "\n";
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        case 6: // darbo baigtis
        {
            cout << "Darbas su programa baigtas.";
            return 0;
        }
        default:
        {
            std::cout << "How did we get here?" << std::endl; // https://minecraft.wiki/w/Tutorial:Advancement_guide/How_Did_We_Get_Here%3F
            return 0;
        }
    }
    return 0;
}
