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

std::ifstream in("duom.txt");
std::ofstream out("rez.txt");

struct Studentas{
    std::string vardas = "R", pavarde = "R";
    //int *paz; // nuspresti kiek pazymiu tures studentas galu gale
    vector<int> nd;
    int rez;
};

int main(){

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
    cout << "Įveskite namų darbų pažymį: ";
    cin >> ndPaz;
    do{
        A.nd.push_back(ndPaz);
        cout << A.nd.size() << " " << std::endl;
        cout << "Įveskite namų darbų pažymį: ";
    }while(cin >> ndPaz && A.nd.size() < 9);
    cout << "Įveskite egzamino rezultatą: ";
    cin >> A.rez;
    cout << std::endl;
    //A.rez = A.paz.

    cout << "Pavarde" << std::setw(10) <<  "Vardas" << std::setw(40) << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(59) << "-" << std::endl;
    for(int i = 0; i < 1; i++){
        cout << A.vardas << " " <<  A.pavarde;
    }

    return 0;
}