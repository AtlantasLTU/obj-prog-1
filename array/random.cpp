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
    return gautiSkaiciu("Įveskite norimą generuoti namų darbų rezultatų kiekį: ", 0, N);
}

int randomStudentuKiekis()
{    
    int N = 100;
    return gautiSkaiciu("Įveskite norimą generuoti studentų kiekį: ", 0, N);
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