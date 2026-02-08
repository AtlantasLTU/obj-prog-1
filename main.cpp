#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using std::vector;
using std::cin;
using std::cout;

#ifdef _WIN32 // naudojame preprocesorių, kad kompiliatorius, naudojant Windows, pridėtų windows.h antraščių failą, kad vėliau galėtume pakeistį terminalo išvesties ir įvesties užkodavimą į UTF-8
#include <windows.h>
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
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    bool medianos;
    char t;
    cout << "Išvesti medianas? (N, y)" << std::endl;
    while(t!='N' && t!='Y' && t!='n' && t!='y'){
        cin >> t;
    }
    if(t == 'Y' || t == 'y'){
        medianos = true;
    } else if(t == 'N' || t == 'n'){
        medianos = false;
    }
    Studentas A;
    cin >> A.vardas >> A.pavarde;
    for(int i = 0; i < 10; i++){
        cout << "Įveskite namų darbų pažymį" << std::endl;
        int t;
        cin >> t;
        A.nd.push_back(t);
    }
    //A.rez = A.paz.

    cout << "Pavarde" << std::setw(10) <<  "Vardas" << std::setw(40) << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(59) << "-" << std::endl;
    for(int i = 0; i < 1; i++){
        cout << A.vardas << " " <<  A.pavarde;
    }

    return 0;
}