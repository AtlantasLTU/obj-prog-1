#include "isvestis.h"
#include "ivestis.h"

int menu()
{
    return gautiSkaiciu("Pasirinkite programos eigą:\n1 - ranką,\n2 - generuoti tik pažymius,\n3 - generuoti studentų vardus, pavardės ir pažymius,\n4 - skaityti studentus iš failo,\n5 - testavimas su failais,\n6 - generuoti failą,\n7 - baigti darbą: ", 1, 7);
}

/* int failoPasirinkimas()
{
    return gautiSkaiciu("Pasirinkite failą, iš kurio skaityti\n1 - kursiokai.txt,\n2 - studentai10000.txt,\n3 - studentai100000.txt,\n4 - studentai1000000.txt\n", 1, 4);
} */

int rusiavimoPasirinkimas()
{
    return gautiSkaiciu("Pasirinkite pagal ką rūšiuoti: \n1 - vardą (A->Ž),\n2 - vardą (Ž->A),\n3 - pavardę (A->Ž),\n4 - pavardę (Ž->A),\n5 - galutinį pažymį didėjančiai (1->10),\n6 - galutinį pažymį mažėjančiai (10->1)\n", 1, 6);
}

int testavimoPasirinkimas()
{
    return gautiSkaiciu("Kiek kartų testuoti skaitymą iš failo? (1-100):", 1, 100);
}

int studentuPasirinkimas()
{
    return gautiSkaiciu("Įveskite norimą generuoti studentų kiekį (1-10000000):", 1, 10000000);
}

int ndPasirinkimas()
{
    return gautiSkaiciu("Įveskite norimą generuoti namų darbų rezultatų kiekį (0-10000000): ", 0, 10000000);
}

bool medianosUzklausa()
{
    return gautiPatvirtinima("Skaičiuoti tik medianas? Jei ne, tai galutinis rezultatas bus skaičiuojamas su vidurkiu");
}

bool failoUzklausa()
{
    return gautiPatvirtinima("Ar išvesti į terminalą? Jei ne, tai bus išvedama į rezultatai.txt failą");
}

void isvestis(const std::vector<Studentas> &A, bool medianos, bool failas, const std::string &failoPavadinimas)
{
    std::string out;
    out += std::format("{:<20}{:<21}Galutinis (Vid.) / Galutinis (Med.)\n", "Vardas", "Pavardė");
    out += std::string(75, '-') + "\n";
    for(const Studentas &X : A)
    {
        if (medianos)
        {
            out += std::format("{:<20}{:<21}{:<19}{:.2f}\n", X.vardas, X.pavarde, "x.xx", X.galutinis);
        }
        else
        {
            out += std::format("{:<20}{:<21}{:<19.2f}y.yy\n", X.vardas, X.pavarde, X.galutinis);
        }
    }
    if(failas){
        std::ofstream fout(failoPavadinimas);
        fout << out;
        fout.close();
    } else {
        std::cout << out;
    }
}

void failoPasirinkimas(int &rezervas, std::string &failoPavadinimas, const std::string& vieta)
{
    std::vector<std::filesystem::directory_entry> failai;
    std::vector<int> rezervai;

    for(auto &failas : std::filesystem::directory_iterator(vieta))
    {
        if(!failas.is_regular_file())
            continue;

        if(failas.path().extension() != ".txt")
            continue;
        
        std::string vardas = failas.path().filename().string();

        if(vardas == "rezultatai.txt" || vardas == "galvociai.txt" || vardas == "vargsiukai.txt")
            continue;

        if(vardas.find("studentai", 0) == 0)
        {
            std::string skaicius = vardas.substr(9, vardas.size() - 9 - 4);

            if(skaicius.empty() || !std::all_of(skaicius.begin(), skaicius.end(), [](unsigned char simbolis)
            {
                return std::isdigit(simbolis);
            }))
            {
                rezervai.push_back(0);
            } 
            else
            {
                rezervai.push_back(std::stoi(skaicius));
            }
        } else {
            rezervai.push_back(0);
        }

        failai.push_back(failas);
    }

    if(failai.empty())
    {
        std::cout << "Nerasta tekstinių failų vietoje: " << vieta << "\n";
    }

    std::cout << "Pasirinkite failą:\n";
    for(int i = 0; i < failai.size(); i++)
    {
        std::cout << (i + 1) << ": " << failai.at(i).path().filename().string() << "\n";
    }

    int pasirinkimas = gautiSkaiciu("Įveskite failo numerį: ", 1, failai.size(), false);

    failoPavadinimas = failai.at(pasirinkimas-1).path().filename().string();
    rezervas = rezervai.at(pasirinkimas-1);
}