#include "random.h"
#include "studVPGen.h"

using std::cout;
using std::cin;
using std::endl;

void studentoVardoPavardesIvestisRandom(Studentas &A, const int &pasirinkimas)
{
    switch(pasirinkimas)
    {
        case 2:
        {
            // the reference pass will still be used here, just haven't written the code yet
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
            break;
        }
        case 3:
        {   
            cout << "Sugeneruotas vardas!" << std::endl;
            gen_map(A);
            break;
        }
        default:
        {
            cout << "studentoVardoPavardesIvestisRandom default atvejis";
            break;
        }
    }
}

Studentas skaitymasRandom(const int &pasirinkimas)
{
    Studentas A;
    switch(pasirinkimas)
    {
        case 2:
        {
            studentoVardoPavardesIvestisRandom(A, pasirinkimas);
            namuDarbuRezultataiRandom(A, namuDarbuRezultataiIvestisRandom());
            egzaminoRezultatoIvestis(A);
            return A;
        }
        case 3:
        {
            studentoVardoPavardesIvestisRandom(A, pasirinkimas);
            namuDarbuRezultataiRandom(A, namuDarbuRezultataiIvestisRandom());
            egzaminoRezultatoIvestis(A);
            return A;
        }
        default:
        {
            cout << "skaitymasRandom default atvejis" << std::endl;
            return A;
        }
    }
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

int randomStudentuKiekis()
{    
    int N = 100;
    int generuojamuStudSkaicius = -1;
    cout << "Įveskite norimą generuoti studentų kiekį: ";
    while (true)
    {
        if (!(cin >> generuojamuStudSkaicius)) // tikrina ar ivestas sveikas skaicius, kadangi t - int kintamasis
        {
            cin.clear();                                                   // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas generuojamų studentų kiekis turi būti sveikasis skaičius nuo 0 iki " << N << '!' << std::endl;
            continue;
        }
        if (generuojamuStudSkaicius < 0 || generuojamuStudSkaicius > N) // tikrina ar ivestas skaicius maziau uz 1 arba daugiau uz 10, jei salyga tenkinama, pradedama nauja ciklo iteracija
        {
            generuojamuStudSkaicius = -1;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas generuojamų studentų kiekis turi būti sveikasis skaičius nuo 0 iki " << N << '!' << std::endl;
            continue;
        }
        break;
    }
    return generuojamuStudSkaicius;
}

void namuDarbuRezultataiRandom(Studentas &A, int ndKiekis)
{
    for(int i = 0; i < ndKiekis; i++){
        A.nd.push_back(1 + (double) rand() / RAND_MAX * (10 - 1));
    }
}

std::vector<Studentas> ivestiStudentusRandom(const int &pasirinkimas)
{
    std::vector<Studentas> studentai;
    switch(pasirinkimas)
    {
        case 2:
        {
            while(true)
            {
                bool ivestiStudenta = studentoUzklausa();
                if(ivestiStudenta)
                {
                    studentai.push_back(skaitymasRandom(pasirinkimas));
                } 
                else 
                {
                    break;
                }
            }
            break;
        }
        case 3:
        {
            int studKiekis = randomStudentuKiekis();
            for(int i = 0; i < studKiekis; i++)
            {
                studentai.push_back(skaitymasRandom(pasirinkimas));
            }
            break;
        }
        default:
        {
            cout << "ivestiStudentusRandom default atvejis" << std::endl;
            return studentai;
        }
    }
    return studentai;
} 