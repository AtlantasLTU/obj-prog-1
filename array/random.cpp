#include "random.h"
#include "studVPGen.h"

using std::cout;
using std::cin;
using std::endl;

void studentoVardoPavardesIvestisRandom(Studentas &A, int pasirinkimas)
{
    switch(pasirinkimas)
    {
        case 2:
        {
            studentoVardoPavardesIvestis(A);
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

Studentas skaitymasRandom(int pasirinkimas)
{
    Studentas A;
    switch(pasirinkimas)
    {
        case 2:
        {
            studentoVardoPavardesIvestisRandom(A, pasirinkimas);
            namuDarbuRezultataiRandom(A, namuDarbuRezultataiIvestisRandom());
            egzaminoRezultatasRandom(A);
            return A;
        }
        case 3:
        {
            studentoVardoPavardesIvestisRandom(A, pasirinkimas);
            namuDarbuRezultataiRandom(A, namuDarbuRezultataiIvestisRandom());
            egzaminoRezultatasRandom(A);
            return A;
        }
        default:
        {
            cout << "skaitymasRandom default atvejis" << std::endl;
            return A;
        }
    }
}

void egzaminoRezultatasRandom(Studentas &A)
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1,10);
    A.rez = dist(rng);
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
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1,10);
    for(int i = 0; i < ndKiekis; i++){
        pridetiNd(A, dist(rng));
    }
}

Studentas* ivestiStudentusRandom(int pasirinkimas, int &kiekis)
{
    int vieta = 2;
    kiekis = 0;
    Studentas *studentai = new Studentas[vieta];
    switch(pasirinkimas)
    {
        case 2:
        {
            while(studentoUzklausa())
            {
                padidintiStudentasMasyva(kiekis, vieta, studentai);
                studentai[kiekis++] = skaitymasRandom(pasirinkimas);
            }
            break;
        }
        case 3:
        {
            kiekis = randomStudentuKiekis();
            delete[] studentai;
            studentai = new Studentas[kiekis];
            for(int i = 0; i < kiekis; i++)
            {
                studentai[i] = skaitymasRandom(pasirinkimas);
            }
            break;
        }
        default:
        {
            cout << "ivestiStudentusRandom default atvejis" << std::endl;
        }
    }
    return studentai;
} 