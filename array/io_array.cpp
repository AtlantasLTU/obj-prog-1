#include "io.h"

using std::cout;
using std::cin;
using std::endl;

int menu()
{
    cout << "Pasirinkite programos eigą (1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - baigti darbą): " << std::endl;

    int pasirinkimas=0;
    while (true)
    {
        if (!(cin >> pasirinkimas)) // tikrina ar ivestas sveikas skaicius, kadangi t - int kintamasis
        {
            cin.clear();                                                   // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas pasirinkimas turi būti sveikasis skaičius (1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - baigti darbą)!:" << std::endl;
            continue;
        }
        if (pasirinkimas < 1 || pasirinkimas > 4) // tikrina ar ivestas skaicius maziau uz 1 arba daugiau uz 10, jei salyga tenkinama, pradedama nauja ciklo iteracija
        {
            pasirinkimas = 0;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas pasirinkimas turi būti sveikasis skaičius (1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - baigti darbą)!:" << std::endl;
            continue;
        }
        break;
    }
    cout << std::endl;
    return pasirinkimas;
}

bool medianosUzklausa()
{
    char t;

    while (true)
    {
        cout << "Skaičiuoti tik medianas? Jei ne, tai galutinis rezultatas bus skaičiuojamas su vidurkiu (y/n): ";

        if(!(cin >> t))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        t = std::tolower(t);

        if(t=='y') return true;
        if(t=='n') return false;

        cout << "Neteisinga įvestis! Skaičiuoti tik medianas? Jei ne, tai galutinis rezultatas bus skaičiuojamas su vidurkiu (y/n): ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool studentoUzklausa()
{
    char t;

    while (true)
    {
        cout << "Ar norite įvesti studentą? (y/n): ";

        if(!(cin >> t))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        t = std::tolower(t);

        if(t=='y') return true;
        if(t=='n') return false;

        cout << "Neteisinga įvestis! Ar norite įvesti studentą? (y/n): ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Studentas* ivestiStudentus(int &kiekis)
{
    int vieta = 1;
    kiekis = 0;
    Studentas *studentai = new Studentas[vieta];
    while(studentoUzklausa())
    {
        padidintiStudentasMasyva(kiekis, vieta, studentai);
        studentai[kiekis++] = skaitymas();
    }
    return studentai;
}

void padidintiStudentasMasyva(int &kiekis, int &vieta, Studentas *&studentai)
{
    if (kiekis >= vieta)
    {
        vieta = (vieta == 0) ? 1 : vieta * 2;

        Studentas *naujas = new Studentas[vieta];

        for (int i = 0; i < kiekis; i++)
        {
            naujas[i] = studentai[i];
        }

        delete[] studentai;
        studentai = naujas;
    }
}

Studentas skaitymas()
{
    Studentas A;
    studentoVardoPavardesIvestis(A);
    namuDarbuRezultatuIvestis(A);
    egzaminoRezultatoIvestis(A);
    return A;
}

void isvestis(const Studentas *A, int kiekis, bool medianos)
{
    cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(65) << "-" << std::endl
         << std::setfill(' ');
    for(int i = 0; i < kiekis; i++)
    {
        cout << std::setw(15) << A[i].vardas << std::setw(14) << A[i].pavarde << " ";
        if (medianos)
        {
            cout << std::setprecision(2) << std::fixed << std::setw(19) << "x.xx" << galutinisMed(A[i]) << std::endl;
        }
        else
        {
            cout << std::setprecision(2) << std::fixed << std::setw(19) << galutinisVid(A[i]) << "y.yy" << std::endl;
        }
    }
}

void studentoVardoPavardesIvestis(Studentas &A)
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

void namuDarbuRezultatuIvestis(Studentas &A)
{    // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio  
    std::string eilute;  
    while (true)
    {
        cout << "Įveskite namų darbų pažymį (ENTER tuščiame laukelyje, kad nutraukti įvestį): ";
        std::getline(cin, eilute); // perskaito visa eilute

        // patikrina ar eilute tuscia, jei taip, nutraukia namu darbu rezultatu ivesti (eilute tuscia, jei vartotojas paspaudzia ENTER, kai ji tuscia)
        if (eilute.empty())
        {
            break;
        }

        // eilute verciama is string i sveikaji skaiciu (int) ir tikrinama ar gautas sveikasis skaicius > 1 ir < 10
        try
        {
            int ndPaz = std::stoi(eilute); // stoi - "string to integer"

            if (ndPaz < 1 || ndPaz > 10)
            {
                cout << "Įvestas namų darbų rezultatas turi būti nuo 1 iki 10!" << endl;
            }
            else
            {
                pridetiNd(A, ndPaz);
            }
        }
        catch (...)
        {
            // jei ivyksta klaida, prasoma per naujo ivesti skaiciu
            cout << "Įvestas namų darbų rezultatas turi būti sveikasis skaičius nuo 1 iki 10!" << endl;
        }
    }
}

void pridetiNd(Studentas &A, int paz)
{
    if (A.ndKiekis == A.ndVieta)
    {
        A.ndVieta = (A.ndVieta == 0) ? 1 : A.ndVieta * 2;

        int* naujas = new int[A.ndVieta];
        for(int i=0;i<A.ndKiekis;i++)
            naujas[i] = A.nd[i];

        delete[] A.nd;
        A.nd = naujas;
    }

    A.nd[A.ndKiekis++] = paz;
}


void egzaminoRezultatoIvestis(Studentas &A)
{
    cout << "Įveskite egzamino rezultatą: ";
    while (true)
    {
        if (!(cin >> A.rez)) // tikrina ar ivestas sveikas skaicius, kadangi A.rez - int kintamasis
        {
            cin.clear();                                                   // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas egzamino rezultatas turi būti sveikasis skaičius nuo 1 iki 10!" << std::endl;
            continue;
        }
        if (A.rez < 1 || A.rez > 10) // tikrina ar ivestas skaicius maziau uz 1 arba daugiau uz 10, jei salyga tenkinama, pradedama nauja ciklo iteracija
        {
            A.rez = 0;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas egzamino rezultatas turi būti nuo 1 iki 10!" << std::endl;
            continue;
        }
        break;
    }
    cout << std::endl;
}
