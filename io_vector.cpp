#include "io.h"

void menu(){
    cout << "Pasirinkite programos eigą (1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - baigti darbą): " << std::endl;
    
}

Studentas skaitymas(){
    Studentas A;
    std::string eilute;
    studentoVardoPavardesIvestis(eilute, A);
    namuDarbuRezultatuIvestis(eilute, A);
    egzaminoRezultatoIvestis(A);
    return A;
}

void isvestis(Studentas &A, bool medianos)
{
    cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(65) << "-" << std::endl
         << std::setfill(' ');
    // for(int i = 0; i < 1; i++){
    cout << std::setw(15) << A.vardas << std::setw(14) << A.pavarde << " ";

    if (medianos)
    {
        float galutinis = galutinisMed(A);
        cout << std::setprecision(2) << std::fixed << std::setw(19) << "x.xx" << galutinis << std::endl;
    }
    else
    {
        float galutinis = galutinisVid(A);
        cout << std::setprecision(2) << std::fixed << std::setw(19) << galutinis << "y.yy" << std::endl;
    }
    //}
}

void studentoVardoPavardesIvestis(std::string &eilute, Studentas &A)
{
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

void namuDarbuRezultatuIvestis(std::string &eilute, Studentas &A)
{    // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                A.nd.push_back(ndPaz);
            }
        }
        catch (...)
        {
            // jei ivyksta klaida, prasoma per naujo ivesti skaiciu
            cout << "Įvestas namų darbų rezultatas turi būti sveikasis skaičius nuo 1 iki 10!" << endl;
        }
    }
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
