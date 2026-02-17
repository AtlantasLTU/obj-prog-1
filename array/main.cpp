#include <iostream>
#include <string>

//Header file includes
#include "io.h"
#include "random.h"

//namespaces
using std::cin;
using std::cout;

#ifdef _WIN32 // naudojame preprocesorių, kad kompiliatorius, naudojant Windows, pridėtų windows.h antraščių failą, kad vėliau galėtume pakeistį terminalo išvesties ir įvesties užkodavimą į UTF-8
#include <windows.h> // windows antraščių failas
#endif

int main()
{

    #ifdef _WIN32 // Jei kompiliuojama Windows operacinei sistemai nustatyti konsoles įvestį ir išvestį UTF-8 užkodavimui.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    srand(time(nullptr));
    //pasirinkima galima tobulint su enumeratorium del type safety ir jei butu norima valdyti atminti.
    int pasirinkimas = menu();
    switch(pasirinkimas){
        case 1: // rankinis ivedimas
        {
            bool medianos = medianosUzklausa();
            int kiekis;
            Studentas *studentai = ivestiStudentus(kiekis);
            isvestis(studentai, kiekis, medianos);
            for(int i = 0; i < kiekis; i++){
                delete[] studentai[i].nd;
            }
            delete[] studentai;
            break;
        }
        case 2: // tik pazymiu generavimas.
        {
            bool medianos = medianosUzklausa();
            int kiekis;
            Studentas *studentai = ivestiStudentusRandom(pasirinkimas, kiekis);
            isvestis(studentai, kiekis, medianos);
            for(int i = 0; i < kiekis; i++){
                delete[] studentai[i].nd;
            }
            delete[] studentai;
            break;
        }
        case 3: // studentu ir pazymiu generavimas;
        {
            bool medianos = medianosUzklausa();
            int kiekis;
            Studentas *studentai = ivestiStudentusRandom(pasirinkimas, kiekis);
            isvestis(studentai, kiekis, medianos);
            for(int i = 0; i < kiekis; i++){
                delete[] studentai[i].nd;
            }
            delete[] studentai;
            break;
        }
        case 4: // darbo baigtis
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
