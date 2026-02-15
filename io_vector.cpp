#include "io.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Studentas skaitymas(){
    Studentas A;
    cout << "Įveskite studento vardą bei pavardę: ";
    cin >> A.vardas >> A.pavarde;
    
    // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string eilute;
    while (true)
    {
        cout << "Įveskite namų darbų pažymį: ";
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

            if (ndPaz < 1 || ndPaz > 10) {
                cout << "Įvestas namų darbų rezultatas turi būti nuo 1 iki 10! Bandykite dar kartą arba spauskite ENTER, kad baigti." << endl;
            } else {
                A.nd.push_back(ndPaz);
            }
        } 
        catch (...)
        {
            // jei ivyksta klaida, prasoma per naujo ivesti skaiciu
            cout << "Įvestas namų darbų rezultatas turi būti sveikasis skaičius nuo 1 iki 10! Bandykite dar kartą arba spauskite ENTER, kad baigti." << endl;
        }
    }

    cout << "Įveskite egzamino rezultatą: ";
    while(true)
    {
        if (!(cin >> A.rez)) // tikrina ar ivestas sveikas skaicius, kadangi A.rez - int kintamasis
        {
            cin.clear(); // atstato console input flag'a, jei ivestis buvo bloga.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas egzamino rezultatas turi būti sveikasis skaičius nuo 1 iki 10!" << std::endl;
            continue;
        }
        if (A.rez < 1 || A.rez > 10) // tikrina ar ivestas skaicius maziau uz 1 arba daugiau uz 10, jei salyga tenkinama, pradedama nauja ciklo iteracija
        {    
            A.rez=0;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // isvalo console ivesti, iki ivesties didziausio simboliu skaiciaus streamsize max is numeric limits funkcijos is limits bibliotekos arba naujos eilutes simbolio
            cout << "Įvestas egzamino rezultatas turi būti nuo 1 iki 10!" << std::endl;
            continue;
        }
        break;
    }
    cout << std::endl;
    return A;
}