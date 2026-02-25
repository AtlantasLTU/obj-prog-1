#include "random.h"
#include "studVPGen.h"

using std::cout;
using std::cin;
using std::endl;

Studentas skaitymasRandom()
{
    Studentas A;
    gen_map(A);
    namuDarbuRezultataiRandom(A, namuDarbuRezultataiIvestisRandom());
    egzaminoRezultatasRandom(A);
    return A;
}

bool skaitymasRandom(Studentas &A)
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
    namuDarbuRezultataiRandom(A, namuDarbuRezultataiIvestisRandom());
    egzaminoRezultatasRandom(A);
    return true;
}

void egzaminoRezultatasRandom(Studentas &A)
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1,10);
    A.rez = dist(rng);
}

int namuDarbuRezultataiIvestisRandom()
{    
    int N = maxNdKiekis;
    return gautiSkaiciu("Įveskite norimą generuoti namų darbų rezultatų kiekį: ", 0, N);
}

int randomStudentuKiekis()
{    
    int N = 100;
    return gautiSkaiciu("Įveskite norimą generuoti studentų kiekį: ", 0, N);
}

void namuDarbuRezultataiRandom(Studentas &A, int ndKiekis)
{
    static std::mt19937 rng(std::random_device{}()); // static - sukuriama karta ir kad nebutu per naujo kuriamas rng bei seed'inamas
    std::uniform_int_distribution<int> dist(1,10); // skaicius nuo 1 iki 10 isskirstymas, tai jei pvz sugeneruota random skaiciu 12312581 idedame i dist, ji priskiria kazkuriam skaiciui nuo 1 iki 10 imtinai
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
            while(true)
            {
                Studentas A;
                if(!skaitymasRandom(A))
                {
                    break;
                }
                padidintiStudentasMasyva(kiekis, vieta, studentai);
                studentai[kiekis++] = A;
            }
            return studentai;
        }
        case 3:
        {
            kiekis = randomStudentuKiekis();
            delete[] studentai;
            studentai = new Studentas[kiekis];
            for(int i = 0; i < kiekis; i++)
            {
                studentai[i] = skaitymasRandom();
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