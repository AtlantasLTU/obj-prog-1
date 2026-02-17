#include "random.h"

using std::cout;
using std::cin;
using std::endl;

void studentoVardoPavardesIvestisRandom(Studentas &A)
{
    std::string eilute;
    // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true)
    {
        cout << "Įveskite studento vardą bei pavardę: ";
        std::getline(cin, eilute); // perskaito visa eilute

        // jei eilutė tuščia, nutraukiama studento įvestis
        if (eilute.empty())
        {   
            cout << "Turi būti įvesta studento vardas bei pavardė" << std::endl;
            continue;
        }

        std::istringstream iss(eilute);
        std::string vardas, pavarde;

        // įvestį skaidome į du žodžius
        if (!(iss >> vardas >> pavarde))
        {
            cout << "Įveskite vardą ir pavardę (du žodžiai)." << endl;
            continue;
        }

        // tikriname ar po vardo ir pavardės yra dar žodžių
        std::string ekstra;
        if (iss >> ekstra)
        {
            cout << "Įvesta per daug žodžių — reikia tik vardo ir pavardės." << endl;
            continue;
        }

        // Jei viskas gerai — saugom
        A.vardas = vardas;
        A.pavarde = pavarde;
        break;
    }
}

Studentas skaitymasRandom(/*const int &pasirinkimas*/)
{
    Studentas A;
    studentoVardoPavardesIvestisRandom(A);
    namuDarbuRezultataiRandom(A, namuDarbuRezultataiIvestisRandom());
    egzaminoRezultatoIvestis(A);
    return A;
}

int namuDarbuRezultataiIvestisRandom()
{    
    int N = 100;
    int generuojamuNdSkaicius = -1;
    cout << "Įveskite norimą generuoti namų darbų rezultatų kiekį: ";
    while (true)
    {
        if (!(cin >> generuojamuNdSkaicius)) // tikrina ar ivestas sveikas skaicius, kadangi t - int kintamasis
        {
            cin.clear();                                                   // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas generuojamų namų darbų rezultatų kiekis turi būti sveikasis skaičius nuo 0 iki " << N << '!' << std::endl;
            continue;
        }
        if (generuojamuNdSkaicius < 0 || generuojamuNdSkaicius > N) // tikrina ar ivestas skaicius maziau uz 1 arba daugiau uz 10, jei salyga tenkinama, pradedama nauja ciklo iteracija
        {
            generuojamuNdSkaicius = -1;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas generuojamų namų darbų rezultatų kiekis turi būti sveikasis skaičius nuo 0 iki " << N << '!' << std::endl;
            continue;
        }
        break;
    }
    return generuojamuNdSkaicius;
}

void namuDarbuRezultataiRandom(Studentas &A, int ndKiekis)
{
    for(int i = 0; i < ndKiekis; i++){
        A.nd.push_back(1 + (double) rand() / RAND_MAX * (10 - 1));
    }
}

std::vector<Studentas> ivestiStudentusRandom()
{
    std::vector<Studentas> studentai;
    while(true)
    {
        bool ivestiStudenta = studentoUzklausa();
        if(ivestiStudenta)
        {
            studentai.push_back(skaitymasRandom());
        } 
        else 
        {
            break;
        }
    }
    return studentai;
} 