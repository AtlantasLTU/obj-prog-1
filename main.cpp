#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using std::vector;
using std::cin;
using std::cout;

#ifdef _WIN32 // naudojame preprocesorių, kad kompiliatorius, naudojant Windows, pridėtų windows.h antraščių failą, kad vėliau galėtume pakeistį terminalo išvesties ir įvesties užkodavimą į UTF-8
#include <windows.h> // windows antraščių failas
#endif

// input tikrinimas
// galutinio rez skaiciavimas
// ivedimo patikslinimas

struct Studentas{
    std::string vardas = "R", pavarde = "R";
    //int *paz; // nuspresti kiek pazymiu tures studentas galu gale
    vector<int> nd;
    int rez;
};

float Galutinis(bool medianos, Studentas A)
{
    float galutinis = 0;
    int size = A.nd.size();
    if(medianos){
        float med = 0;
        if(size%2==0){
            med = (A.nd.at(size/2) + A.nd.at((size/2) - 1)) / 2.0;
        } else {
            med = A.nd.at(size/2);
        }
        galutinis = 0.4 * med + 0.6 * A.rez;
        return galutinis;
    } else {
        int sum = 0;
        float ndVid;
        for (int i = 0; i < size; i++){
            sum += A.nd.at(i);
        }
        ndVid = (float)sum / (float)size;
        galutinis = 0.4 * ndVid + 0.6 * A.rez;
        return galutinis;
    }
}

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

    cout << "Įveskite studento vardą bei pavardę" << std::endl;
    Studentas A;
    cin >> A.vardas >> A.pavarde;
    
    int ndPaz;
    while (A.nd.size() < 10){
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
    cin >> A.rez;
    cout << std::endl;

    cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) <<  "Vardas" << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(65) << "-" << std::endl << std::setfill(' ');
    //for(int i = 0; i < 1; i++){
        cout << std::setw(15) << A.vardas << std::setw(14) <<  A.pavarde << " ";
        float galutinis=Galutinis(medianos, A);
        if(medianos == true){
            cout << std::setprecision(2) << std::fixed << std::setw(19) << "x.xx" << galutinis << std::endl;
        } else {
            cout << std::setprecision(2) << std::fixed << std::setw(19) << galutinis << "y.yy" << std::endl;
        }
    //}

    return 0;
}
