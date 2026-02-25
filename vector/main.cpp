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
        if(pasirinkimas<4)
        {
            medianos = medianosUzklausa();
        }
    }
    
    switch(pasirinkimas){
        case 1: // rankinis ivedimas
        {
            std::vector<Studentas> studentai = ivestiStudentus();
            isvestis(studentai, medianos, failas);
            break;
        }
        case 2: // tik pazymiu generavimas.
        {
            std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
            isvestis(studentai, medianos, failas);
            break;
        }
        case 3: // studentu ir pazymiu generavimas;
        {
            std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
            isvestis(studentai, medianos, failas);
            break;
        }
        case 4: // skaitymas is failo
        {
            int fPasirinkimas = failoPasirinkimas();
            int rPasirinkimas = rusiavimoPasirinkimas();
            switch(fPasirinkimas){
                case 1:
                {
                    Timer t; 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("kursiokai.txt", 2);
                    double apdorojimoTrukme = t.elapsed(); // Skirtumas (s)
                    t.reset();
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    double rusiavimoTrukme = t.elapsed();
                    t.reset();
                    isvedimas(studentai, failas);
                    double isvedimoTrukme = t.elapsed(); // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
                    break;
                }
                case 2:
                {
                    Timer t; 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai10000.txt", 10000);
                    double apdorojimoTrukme = t.elapsed(); // Skirtumas (s)
                    t.reset();
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    double rusiavimoTrukme = t.elapsed();
                    t.reset();
                    isvedimas(studentai, failas);
                    double isvedimoTrukme = t.elapsed(); // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
                    break;
                }
                case 3:
                {   
                    Timer t; 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai100000.txt", 100000);
                    double apdorojimoTrukme = t.elapsed(); // Skirtumas (s)
                    t.reset();
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    double rusiavimoTrukme = t.elapsed();
                    t.reset();
                    isvedimas(studentai, failas);
                    double isvedimoTrukme = t.elapsed(); // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
                    break;
                }
                case 4:
                {
                    Timer t; 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai1000000.txt", 1000000);
                    double apdorojimoTrukme = t.elapsed(); // Skirtumas (s)
                    t.reset();
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    double rusiavimoTrukme = t.elapsed();
                    t.reset();
                    isvedimas(studentai, failas);
                    double isvedimoTrukme = t.elapsed(); // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme << " s\n";
                    std::cout << "Bendra trukmė: " << apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme << " s";
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case 5: // testavimas su failais
        {
            int fPasirinkimas = failoPasirinkimas();
            int rPasirinkimas = rusiavimoPasirinkimas();
            int tPasirinkimas = testavimoPasirinkimas();
            switch(fPasirinkimas){
                case 1:
                {
                    double bendraTrukme=0;
                    for(int i = 0; i < tPasirinkimas; i++){
                        Timer t; 
                        std::vector<StudentasF> studentai = skaitymasIsFailo("kursiokai.txt", 2);
                        bendraTrukme += t.elapsed();
                        //ar testuoti skaiciavimu greiti?
                        //ar testuoti sorts?
                        //ar testuoti isvedima?
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
                        std::vector<StudentasF> studentai = skaitymasIsFailo("studentai10000.txt", 10000);
                        bendraTrukme += t.elapsed();
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
                        std::vector<StudentasF> studentai = skaitymasIsFailo("studentai100000.txt", 100000);
                        bendraTrukme += t.elapsed();
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
                        std::vector<StudentasF> studentai = skaitymasIsFailo("studentai1000000.txt", 1000000);
                        bendraTrukme += t.elapsed();
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
