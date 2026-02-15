#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

//Header file includes
#include "calc.h"
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

    bool medianos;
    char t;
    cout << "Išvesti medianas? (N, y)" << std::endl;
    do {
        cin >> t;
    } while(t!='N' && t!='Y' && t!='n' && t!='y');
    if(t == 'Y' || t == 'y'){
        medianos = true;
    } else if(t == 'N' || t == 'n'){
        medianos = false;
    }
    cout << "Pradedama studentų bei jų rezultatų įvestis. Tuščiame įvedimo lauke paspaudus klavišą ENTER - įvedimas nutraukiamas" << std::endl;

    Studentas A = skaitymas();

    cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) <<  "Vardas" << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(65) << "-" << std::endl << std::setfill(' ');
    //for(int i = 0; i < 1; i++){
        cout << std::setw(15) << A.vardas << std::setw(14) <<  A.pavarde << " ";

        if(medianos){
            float galutinis = galutinisMed(A);
            cout << std::setprecision(2) << std::fixed << std::setw(19) << "x.xx" << galutinis << std::endl;
        } else {
            float galutinis = galutinisVid(A);
            cout << std::setprecision(2) << std::fixed << std::setw(19) << galutinis << "y.yy" << std::endl;
        }
    //}

    return 0;
}
