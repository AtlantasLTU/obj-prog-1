#include "io.h"
#include <iostream>
using std::cout;
using std::cin;

Studentas skaitymas(){
    cout << "Įveskite studento vardą bei pavardę" << std::endl;
    Studentas A;
    cin >> A.vardas >> A.pavarde;
    
    int ndPaz;
    while (!cin.eof()){
        cout << "Įveskite namų darbų pažymį: ";

        if (!(cin >> ndPaz)) // tikrina ar ivestas sveikas skaicius, kadangi ndPaz - int kintamasis
        {
            cin.clear(); // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(10000,'\n'); // isvalo console ivesti, iki 10000 simboliu arba naujos eilutes simbolio
            cout << "Įvestas namų darbų rezultatas turi būti sveikasis skaičius nuo 1 iki 10!" << std::endl;
            continue; // pradeda nauja ciklo iteracija
        }
        if (ndPaz < 1 || ndPaz > 10) // tikrina ar ivestas skaicius maziau uz 1 arba daugiau uz 10, jei salyga tenkinama, pradedama nauja ciklo iteracija
        {    
            cin.clear(); // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(10000,'\n'); // isvalo console ivesti, iki 10000 simboliu arba naujos eilutes simbolio
            cout << "Įvestas namų darbų rezultatas turi būti nuo 1 iki 10!" << std::endl;
            continue;
        }
        A.nd.push_back(ndPaz); // prideda ivesta pazymi prie vektoriaus.
    }

    cout << "Įveskite egzamino rezultatą: ";
    while(A.rez==0 && !cin.eof())
    {
        if (!(cin >> A.rez)) // tikrina ar ivestas sveikas skaicius, kadangi ndPaz - int kintamasis
        {
            cin.clear(); // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(10000,'\n'); // isvalo console ivesti, iki 10000 simboliu arba naujos eilutes simbolio
            cout << "Įvestas namų darbų rezultatas turi būti sveikasis skaičius nuo 1 iki 10!" << std::endl;
        }
        if (A.rez < 1 || A.rez > 10) // tikrina ar ivestas skaicius maziau uz 1 arba daugiau uz 10, jei salyga tenkinama, pradedama nauja ciklo iteracija
        {    
            cin.clear(); // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(10000,'\n'); // isvalo console ivesti, iki 10000 simboliu arba naujos eilutes simbolio
            cout << "Įvestas namų darbų rezultatas turi būti nuo 1 iki 10!" << std::endl;
        }
    }
    cout << std::endl;
    return A;
}