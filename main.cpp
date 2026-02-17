#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
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

// input tikrinimas
// galutinio rez skaiciavimas
// ivedimo patikslinimas

int main()
{

#ifdef _WIN32 // Jei kompiliuojama Windows operacinei sistemai nustatyti konsoles įvestį ir išvestį UTF-8 užkodavimui.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    srand(time(NULL));
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
        case 4: // darbo baigtis
        {
            cout << "Darbas su programa baigtas.";
            return 0;
            break;
        }
        default:
        {
            std::cout << "How did we get here?" << std::endl; // https://minecraft.wiki/w/Tutorial:Advancement_guide/How_Did_We_Get_Here%3F
        }
    }
    return 0;
}
