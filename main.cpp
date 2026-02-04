#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using std::vector;
using std::cin;
using std::cout;

std::ifstream in("duom.txt");
std::ofstream out("rez.txt");

struct Studentas{
    std::string vardas = "R", pavarde = "R";
    //int *paz; // nuspresti kiek pazymiu tures studentas galu gale
    vector<int> paz;
    int rez;
};

int main(){
    bool medianos;
    char t;
    cout << "Išvesti medianas? (N, y)" << std::endl;
    while(t!='N' || t!='Y' || t!='n' || t!='y'){
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
        int t;
        cin >> t;
        A.paz.insert(A.paz.begin(), t);
    }
    //A.rez = A.paz.

    cout << "Pavarde" << std::setw(10) <<  "Vardas" << std::setw(40) << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(59) << "-" << std::endl;
    for(int i = 0; i < 2; i++){
        cout << A.vardas << A.pavarde;
    }

    return 0;
}