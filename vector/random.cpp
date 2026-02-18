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
        A.nd.push_back(dist(rng));
    }
}

std::vector<Studentas> ivestiStudentusRandom(int pasirinkimas)
{
    std::vector<Studentas> studentai;
    switch(pasirinkimas)
    {
        case 2:
        {
            while(studentoUzklausa())
            {
                    studentai.push_back(skaitymasRandom(pasirinkimas));
            }
            break;
        }
        case 3:
        {
            int studKiekis = randomStudentuKiekis();
            studentai.reserve(studKiekis);
            for(int i = 0; i < studKiekis; i++)
            {
                studentai.push_back(skaitymasRandom(pasirinkimas));
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