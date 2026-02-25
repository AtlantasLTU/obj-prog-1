#include "io.h"

using std::cout;
using std::cin;
using std::endl;

int menu()
{
    return gautiSkaiciu("Pasirinkite programos eigą (1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - skaityti studentus iš failo, 5 - testavimas su failais, 6 - baigti darbą): ", 1, 6);
}

int failoPasirinkimas()
{
    return gautiSkaiciu("Pasirinkite failą, iš kurio skaityti\n1 - kursiokai.txt,\n2 - studentai10000.txt,\n3 - studentai100000.txt,\n4 - studentai1000000.txt\n", 1, 4);
}

int rusiavimoPasirinkimas()
{
    return gautiSkaiciu("Pasirinkite pagal ką rūšiuoti: \n1 - vardą (A->Ž),\n2 - vardą (Ž->A),\n3 - pavardę (A->Ž),\n4 - pavardę (Ž->A),\n5 - galutinį pažymį didėjančiai (1->10),\n6 - galutinį pažymį mažėjančiai (10->1),\n", 1, 6);
}

int testavimoPasirinkimas()
{
    return gautiSkaiciu("Kiek kartų testuoti skaitymą iš failo? (1-100):", 1, 100);
}

bool medianosUzklausa()
{
    return gautiPatvirtinima("Skaičiuoti tik medianas? Jei ne, tai galutinis rezultatas bus skaičiuojamas su vidurkiu");
}

bool failoUzklausa()
{
    return gautiPatvirtinima("Ar išvesti į terminalą? Jei ne, tai bus išvedama į rezultatai.txt failą");
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
            char t = std::tolower(static_cast<unsigned char>(ivestis[0])); // ivesti vercia i mazaja | to lower tikisi unsigned char arba EOF pagal standarta, static_cast keicia char interpretavima i unsigned char.
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

void isvestis(const std::vector<Studentas> &A, bool medianos, bool failas)
{
    std::ostringstream out;
    out << std::left << std::setw(20) << "Vardas" << std::setw(21) << "Pavardė" << "Galutinis (Vid.) / Galutinis (Med.)\n";
    out << std::string(75, '-') << "\n";
    for(const Studentas &X : A)
    {
        int vardoPlotis = 20 + lietuviskosRaides(X.vardas);
        int pavardesPlotis = 20 + lietuviskosRaides(X.pavarde);
        
        out << std::setw(vardoPlotis) << X.vardas << std::setw(pavardesPlotis) << X.pavarde;
        if (medianos)
        {
            out << std::setprecision(2) << std::fixed << std::setw(19) << "x.xx" << X.galutinisMed << "\n";
        }
        else
        {
            out << std::setprecision(2) << std::fixed << std::setw(19) << X.galutinisVid << "y.yy\n";
        }
    }
    if(failas){
        std::ofstream fout("rezultatai.txt");
        fout << out.str();
        fout.close();
    } else {
        cout << out.str();
    }
}

// apskaiciuoti kiek string su lietuviskomis raidemis sudaro baitu, kadangi viena lietuviska raide - 2 baitai, o ne 1 baitas. Kitaip sakant vardas Ąžuolas turi 7 raides, o jį sudaro 8 baitai, o setw mato baitus, tai jei setw(20), tai jis pridės 12 tusciu tarpu, o ne 13.
int lietuviskosRaides(const std::string& eilute) {
    int simboliuKiekis = 0;
    for (char c : eilute) {
        // jei baitas neprasideda su 10xxxxxx, tai naujas simbolis
        if ((c & 0xC0) != 0x80) { // paprastas ASCII simbolis prasideda su 0, keliu baitu pvz lietuviskos raides prasideda su 11 arba 111 arba 1111, priklausomai nuo kodavimo | 0xC0 = 11000000, 0x80 = 10000000. & (AND) bit'u operacija atranda ar c prasideda su 0 ar 1. antras, trecias ar ketvirtas baitas UTF-8 kodavime visad prasides su 10xxxxxx
            simboliuKiekis++;
        }
    }
    // grazinam trukstama isvesties ploti.
    return eilute.length() - simboliuKiekis;
}

/* void isvedimas(const std::vector<Studentas> &A, bool failas)
{
    std::ostringstream out;
    out << std::left << std::setw(20) << "Vardas" << std::setw(21) << "Pavardė" << "Galutinis (Vid.) / Galutinis (Med.)\n";
    out << std::string(75, '-') << "\n";
    for(const Studentas &X : A)
    {
        out << std::setw(20) << X.vardas << std::setw(21) << X.pavarde << std::setprecision(2) << std::fixed << std::setw(19) << X.galutinisVid << X.galutinisMed << "\n";
    }
    if(failas){
        std::ofstream fout("rezultatai.txt");
        fout << out.str();
        fout.close();
    } else {
        cout << out.str();
    }
} */

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
    {
        return std::isdigit(simbolis) || std::isspace(simbolis);
    });
}

std::vector<Studentas> skaitymasIsFailo(std::string failoPavadinimas, int &ndKiekis, int rezervas){
    std::vector<Studentas> studentai;
    studentai.reserve(rezervas);
    std::string eil;
    std::string t="";

    std::ifstream open_f(failoPavadinimas);

    std::getline(open_f, eil);
    std::istringstream antraste(eil);
    antraste >> t >> t;
    while(antraste >> t){
        if(t == "Egz." || t == "Egzaminas") break;
        ndKiekis++;
    }

    std::string vardas, pavarde;
    int paz;
    
    while (open_f >> vardas >> pavarde) {
        Studentas studentas;
        studentas.vardas = std::move(vardas); //std::move - vardas istrinamas is atminties, t.y. string vardas tampa "", ir tai kas buvo jame dabar priklauso studento strukturos vardui. Paprastai tariant: nedaroma kopija, o vardas priskiriamas studentas.vardas su std::move; taip susitaupo laiko
        studentas.pavarde = std::move(pavarde);
        // uzkomentuotas kodas parodo, kad po std::move dingsta string vardas esantis string, nes jis perkeltas i studentas.vardas
        // cout << "vardas: " << vardas << "\n";

        for(int i = 0; i < ndKiekis; i++){
            open_f >> paz;
            studentas.nd.push_back(paz);
        }
        open_f >> studentas.rez;

        studentai.push_back(std::move(studentas));
    }

    open_f.close();
    return studentai;
}

void skaiciavimas(std::vector<Studentas> &A, bool medianos, int ndKiekis){
    if(medianos)
    {
        for(Studentas &X : A){
            X.galutinisMed = galutinisMedF(X, ndKiekis);
        }
    }
    else
    {
        for(Studentas &X : A){
            X.galutinisVid = galutinisVidF(X, ndKiekis);
        }
    }
}

void skaiciavimas(std::vector<Studentas> &A, bool medianos){
    if(medianos)
    {
        for(Studentas &X : A){
            X.galutinisMed = galutinisMed(X);
        }
    }
    else
    {
        for(Studentas &X : A){
            X.galutinisVid = galutinisVid(X);
        }
    }
}

void rusiavimasSkirstymas(std::vector<Studentas> &studentai, int rPasirinkimas, bool medianos){
    switch(rPasirinkimas){
        case 1:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.vardas < B.vardas;
            });
            break;
        }
        case 2:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.vardas > B.vardas;
            });
            break;
        }
        case 3:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.pavarde < B.pavarde;
            });
            break;
        }
        case 4:
        {
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &A, const Studentas &B){
                return A.pavarde > B.pavarde;
            });
            break;
        }
        case 5:
        {
            std::sort(studentai.begin(), studentai.end(), [medianos](const Studentas &A, const Studentas &B){
                if(medianos) return A.galutinisMed < B.galutinisMed;
                return A.galutinisVid < B.galutinisVid;
            });
            break;
        }
        case 6:
        {
            std::sort(studentai.begin(), studentai.end(), [medianos](const Studentas &A, const Studentas &B){
                if(medianos) return A.galutinisMed > B.galutinisMed;
                return A.galutinisVid > B.galutinisVid;
            });
            break;
        }
        default:
        {
            break;
        }
    }
}