#include "io.h"

using std::cout;
using std::cin;
using std::endl;

int menu()
{
    return gautiSkaiciu("Pasirinkite programos eigą (1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - skaityti studentus iš failo, 5 - baigti darbą): ", 1, 5);
}

/* int menu()
{
    return gautiSkaiciu("Pasirinkite failą, iš kurio skaityti \n
        (1 - ranką, 
        2 - generuoti tik pažymius, \n
        3 - generuoti studentų vardus, pavardės ir pažymius, \n
        4 - skaityti studentus iš failo, 5 - baigti darbą): ", 1, 5);
} */

bool medianosUzklausa()
{
    return gautiPatvirtinima("Skaičiuoti tik medianas? Jei ne, tai galutinis rezultatas bus skaičiuojamas su vidurkiu");
}

bool gautiPatvirtinima(std::string pranesimas)
{
    std::string ivestis;
    while (true) {
        cout << pranesimas << " (y/n): ";
        
        if (!std::getline(cin, ivestis)) {
            if (cin.eof())
            { //apsauga nuo CTRL+D (linux), CTRL+Z (windows)
                cout << "\nĮvesties pabaiga (EOF). Darbas su programa baigtas.";
                exit(0); // sustabdoma programa
            }
            cin.clear(); // atstatome cin fail flag'a
            continue;
        }

        ivestis.erase(0, ivestis.find_first_not_of(" \t")); // randa pirma simboli kuris nera tarpas arba tabuliacija, tada trina nuo 0-inio indekso iki rasto simbolio.
        ivestis.erase(ivestis.find_last_not_of(" \t") + 1); // randa pirma simboli kuris nera tarpas arba tabuliacija nuo galo ir istrina viska po to

        // ivesties ilgio patikrinimas ir konvertavimas
        if (ivestis.length() == 1) {
            char t = std::tolower(static_cast<unsigned char>(ivestis[0]));
            if (t == 'y') return true;
            if (t == 'n') return false;
        }

        // jei ivestis neteisinga, t.y. nieko nebuvo returninta, tai prompt'ina vartotoja vel ivesti y ar n!
        cout << "Neteisinga įvestis! Prašome įvesti tik 'y' arba 'n'." << endl;
    }
}

std::vector<Studentas> ivestiStudentus()
{
    std::vector<Studentas> studentai;
    while(true)
    {
        Studentas A;
        if(!skaitymas(A))
        {
            break;
        }
        studentai.push_back(A);
    }
    return studentai;
} 

bool skaitymas(Studentas &A)
{
    std::string eilute;
    cout << "Įveskite studento vardą bei pavardę (ENTER - nutraukti įvedimą): ";

        // perskaito eilute ir jei perskaitymas nesekmingas, tai ziuri ar cin.eof, jei taip, tai programa uzbaigiama, jei ne, tai isvalo ivesties stream'o veliaveles ir vel prasoma ivesti
    if (!std::getline(cin, eilute))
    {
        if (cin.eof())
        { //apsauga nuo CTRL+D (linux), CTRL+Z (windows)
            cout << "\nĮvesties pabaiga (EOF). Darbas su programa baigtas.";
            exit(0); // sustabdoma programa
        }
        cin.clear(); // atstatome cin fail flag'a
        return false;
    } // jei enter - iseina
    if(eilute.empty())
    {
        return false;
    }
    while(!studentoVardoPavardesIvestis(A, eilute))
    {
        cout << "Įveskite studento vardą bei pavardę (ENTER - baigti): ";
        if(!std::getline(cin, eilute) || eilute.empty()) return false;
    }
    namuDarbuRezultatuIvestis(A);
    egzaminoRezultatoIvestis(A);
    return true;
}

void isvestis(const std::vector<Studentas> &A, bool medianos)
{
    cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(65) << "-" << std::endl
         << std::setfill(' ');
    for(const Studentas &X : A)
    {
        cout << std::setw(15) << X.vardas << std::setw(15) << X.pavarde << " ";
        if (medianos)
        {
            cout << std::setprecision(2) << std::fixed << std::setw(19) << "x.xx" << galutinisMed(X) << std::endl;
        }
        else
        {
            cout << std::setprecision(2) << std::fixed << std::setw(19) << galutinisVid(X) << "y.yy" << std::endl;
        }
    }
}

bool studentoVardoPavardesIvestis(Studentas &A, std::string& eilute)
{
    std::istringstream iss(eilute);
    std::string vardas, pavarde;
    // įvestį skaidome į du žodžius
    if (!(iss >> vardas >> pavarde))
    {
        cout << "Įveskite vardą ir pavardę (du žodžiai)!" << endl;
        return false;
    }
    // tikriname ar po vardo ir pavardės yra dar žodžių
    std::string ekstra;
    if (iss >> ekstra)
    {
        cout << "Įvesta per daug žodžių — reikia tik vardo ir pavardės!" << endl;
        return false;
    }
    // Jei viskas gerai — saugom
    A.vardas = vardas;
    A.pavarde = pavarde;
    return true;
}

void namuDarbuRezultatuIvestis(Studentas &A)
{
    cout << "Įveskite " << maxNdKiekis << " namų darbų rezultatų." << std::endl;
    while (A.nd.size()<maxNdKiekis)
    {
        int balas = gautiSkaiciu("Įveskite namų darbų rezultatą nuo 1 iki 10 (ENTER - baigti): ", 1, 10, true);
        if (balas == -1) break; 
        A.nd.push_back(balas);
    }

    if(A.nd.size()==maxNdKiekis)
    {
        cout << "Įvestas didžiausias namų darbų rezultatų kiekis" << std::endl;
    }
}

void egzaminoRezultatoIvestis(Studentas &A)
{
    int balas = gautiSkaiciu("Įveskite egzamino rezultatą (1-10): ", 1, 10);
    A.rez = balas;
}

int gautiSkaiciu(std::string pranešimas, int min, int max, bool galiButiTuscia /* = false */)
{
    std::string ivestis;
    while (true) {
        cout << pranešimas;

        if (!std::getline(cin, ivestis)) {
            if (cin.eof()) 
            { //apsauga nuo CTRL+D (linux), CTRL+Z (windows)
                cout << "\nĮvesties pabaiga (EOF). Darbas su programa baigtas.";
                exit(0); // sustabdoma programa
            }
            cin.clear(); // atstato cin veliavele is fail
            continue;
        }

        // ivesties nutraukimas su ENTER
        if (galiButiTuscia && ivestis.empty()) return -1;

        try {
            // 
            if (!arTikSkaicius(ivestis)) throw std::invalid_argument("Ne skaičius");

            int skaicius = std::stoi(ivestis);

            //tikriname ar ivestas skaicius atitinka nuo maziausio leistino iki didziausio leistino
            if (skaicius >= min && skaicius <= max) {
                return skaicius;
            } else {
                cout << "Klaida, skaičius turi būti tarp " << min << " ir " << max << "!" << endl;
            }
        } catch (...) {
            cout << "Klaida, įveskite sveikąjį skaičių!" << endl;
        }
    }
}

bool arTikSkaicius(const std::string& eilute)
{ // jei eilute tuscia grazinama false, std::all_of pereina nuo eilutes.begin() pradzios iki galo eilutes.end() per kiekviena simboli, kiekvienam simboliui jei jis skaicius ar tarpas grazina true, jei tai tiesiog raide - grazinama false ir toliau eilute nebetikrinama
    return !eilute.empty() && 
    std::all_of(eilute.begin(), eilute.end(), [](unsigned char simbolis) 
    { // geriau paaiskint lambda
        return std::isdigit(simbolis) || std::isspace(simbolis);
    });
}

std::vector<Studentas> skaitymasIsFailo(std::string failoPavadinimas){
    std::vector<Studentas> studentai;
    studentai.reserve(1000000);
    std::string eil;
    std::string t="";
    int ndKiekis = 0;

    auto start = std::chrono::high_resolution_clock::now(); 
    auto st=start;
    std::ifstream open_f(failoPavadinimas);

    std::getline(open_f, eil);
    std::stringstream antraste(eil);
    antraste >> t >> t;
    while(antraste >> t){
        if(t == "Egz." || t == "Egzaminas") break;
        ndKiekis++;
    }

    std::string vardas, pavarde;
    int paz;
    
    while (open_f >> vardas >> pavarde) {
        Studentas studentas;
        studentas.vardas = std::move(vardas);
        studentas.pavarde = std::move(pavarde);
    
        studentas.nd.reserve(ndKiekis);
    
        for (int i = 0; i < ndKiekis; i++) {
            open_f >> paz;
            studentas.nd.push_back(std::move(paz));
        }
    
        open_f >> studentas.rez;
    
        studentai.push_back(std::move(studentas));
    }
    open_f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas tiesiai į studentai vektorių užtruko: "<< diff.count() << " s\n";  
    return studentai;
}