#include <iostream>
#include <string>
#include <vector>

//Header file includes
#include "io.h"
#include "random.h"

//namespaces
using std::vector;
using std::cin;
using std::cout;

#ifdef _WIN32 // naudojame preprocesorių, kad kompiliatorius, naudojant Windows, pridėtų windows.h antraščių failą, kad vėliau galėtume pakeistį terminalo išvesties ir įvesties užkodavimą į UTF-8
#include <windows.h> // windows antraščių failas
#endif

//apsaugot nuo CTRL+D, Enter, padaryti UX geresni tsg

int main()
{
    #ifdef _WIN32 // Jei kompiliuojama Windows operacinei sistemai nustatyti konsoles įvestį ir išvestį UTF-8 užkodavimui.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    //pasirinkima galima tobulint su enumeratorium del type safety ir jei butu norima valdyti atminti.
    int pasirinkimas = menu();
    bool failas = !failoUzklausa();
    switch(pasirinkimas){
        case 1: // rankinis ivedimas
        {
            bool medianos = medianosUzklausa();
            std::vector<Studentas> studentai = ivestiStudentus();
            isvestis(studentai, medianos, failas);
            break;
        }
        case 2: // tik pazymiu generavimas.
        {
            bool medianos = medianosUzklausa();
            std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
            isvestis(studentai, medianos, failas);
            break;
        }
        case 3: // studentu ir pazymiu generavimas;
        {
            bool medianos = medianosUzklausa();
            std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
            isvestis(studentai, medianos, failas);
            break;
        }
        case 4:
        {
            int fPasirinkimas = failoPasirinkimas(); // galima prideti, kad failo pavadinima butu galima paciam irasyt. 
            int rPasirinkimas = rusiavimoPasirinkimas();
            switch(fPasirinkimas){
                case 1:
                {
                    auto start = std::chrono::high_resolution_clock::now(); 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("kursiokai.txt", 2);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> apdorojimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> rusiavimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    isvedimas(studentai, failas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> isvedimoTrukme = end-start; // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme.count() << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme.count() << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme.count() << " s\n";
                    std::cout << "Bendra trukmė: " << (apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme).count() << " s";
                    break;
                }
                case 2:
                {
                    auto start = std::chrono::high_resolution_clock::now(); 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai10000.txt", 10000);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> apdorojimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> rusiavimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    isvedimas(studentai, failas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> isvedimoTrukme = end-start; // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme.count() << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme.count() << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme.count() << " s\n";
                    std::cout << "Bendra trukmė: " << (apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme).count() << " s";
                    break;
                }
                case 3:
                {   
                    auto start = std::chrono::high_resolution_clock::now(); 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai100000.txt", 100000);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> apdorojimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> rusiavimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    isvedimas(studentai, failas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> isvedimoTrukme = end-start; // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme.count() << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme.count() << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme.count() << " s\n";
                    std::cout << "Bendra trukmė: " << (apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme).count() << " s";
                    break;
                }
                case 4:
                {
                    auto start = std::chrono::high_resolution_clock::now(); 
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai1000000.txt", 1000000);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> apdorojimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    rusiavimasSkirstymas(studentai, rPasirinkimas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> rusiavimoTrukme = end-start; // Skirtumas (s)
                    start = std::chrono::high_resolution_clock::now(); 
                    isvedimas(studentai, failas);
                    end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> isvedimoTrukme = end-start; // Skirtumas (s)
                    std::cout << "Failo apdorojimas (nuskaitymas bei rezultatų apskaičiavimas) į studentai vektorių užtruko: "<< apdorojimoTrukme.count() << " s\n";
                    std::cout << "Duomenų rūšiavimas pagal pasirinktą parametrą užtruko: "<< rusiavimoTrukme.count() << " s\n";
                    std::cout << "Studentų išvedimas užtruko: "<< isvedimoTrukme.count() << " s\n";
                    std::cout << "Bendra trukmė: " << (apdorojimoTrukme+rusiavimoTrukme+isvedimoTrukme).count() << " s";
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        case 5: // darbo baigtis
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
