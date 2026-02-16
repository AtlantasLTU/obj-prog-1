#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

//Header file includes
#include "io.h"

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

    bool medianos = medianosUzklausa();
    
    cout << "Pradedama studentų bei jų rezultatų įvestis. Tuščiame įvedimo lauke paspaudus klavišą ENTER - įvedimas nutraukiamas" << std::endl;

    Studentas A = skaitymas();
    isvestis(A, medianos);

    return 0;
}
