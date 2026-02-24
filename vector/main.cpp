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
    switch(pasirinkimas){
        case 1: // rankinis ivedimas
        {
            bool medianos = medianosUzklausa();
            std::vector<Studentas> studentai = ivestiStudentus();
            isvestis(studentai, medianos);
            break;
        }
        case 2: // tik pazymiu generavimas.
        {
            bool medianos = medianosUzklausa();
            std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
            isvestis(studentai, medianos);
            break;
        }
        case 3: // studentu ir pazymiu generavimas;
        {
            bool medianos = medianosUzklausa();
            std::vector<Studentas> studentai = ivestiStudentusRandom(pasirinkimas);
            isvestis(studentai, medianos);
            break;
        }
        case 4:
        {
            bool medianos = medianosUzklausa();
            int fPasirinkimas = failoPasirinkimas(); // galima prideti, kad failo pavadinima butu galima paciam irasyt. 
            switch(fPasirinkimas){
                case 1:
                {
                    std::vector<StudentasF> studentai = skaitymasIsFailo("kursiokai.txt", medianos, 2);
                    break;
                }
                case 2:
                {
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai10000.txt", medianos, 10000);
                    break;
                }
                case 3:
                {   
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai100000.txt", medianos, 100000);
                    break;
                }
                case 4:
                {
                    std::vector<StudentasF> studentai = skaitymasIsFailo("studentai1000000.txt", medianos, 1000000);
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
