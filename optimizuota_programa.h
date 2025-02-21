#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <fstream>
// pakeist ctime i chromo
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::isalpha;
using std::isdigit;
using std::isspace;
using std::numeric_limits;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// v0.2 includai
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <cpuid.h>

int meniu;

int paz;
struct Stud
{
    string vardas, pavarde;
    int egzaminas;
    vector<int> nd;
    double BalasGalutinisMed;
    double BalasGalutinisVid;
};

bool tinkamas_char(string vardas)
{
    for (char a : vardas)
    {
        if (isalpha(a) == false || isspace(a) == true)
        {
            return false;
        }
    }
    return true;
}
bool tinkamas_int(int skaicius)
{
    while (skaicius > 10 || skaicius < 0)
    {
        if (skaicius == 0)
        {
            break;
        }
        return false;
    }
    return true;
}
double galutinismed(Stud studentas)
{
    double med;
    sort(studentas.nd.begin(), studentas.nd.end());
    if (studentas.nd.size() % 2 == 0)
    {
        med = (studentas.nd[studentas.nd.size() / 2 - 1] + studentas.nd[studentas.nd.size() / 2]) / 2;
    }
    else
    {
        med = studentas.nd[round(studentas.nd.size() / 2) - 1];
    }
    return round((0.4 * med + 0.6 * studentas.egzaminas) * 100) / 100;
}

double galutinisvid(Stud studentas)
{
    double vidurkis;
    double suma{0.0};
    for (size_t ss = 0; ss < studentas.nd.size(); ss++)
    {
        suma += studentas.nd[ss];
    }

    vidurkis = suma / studentas.nd.size();
    return round((0.4 * vidurkis + 0.6 * studentas.egzaminas) * 100) / 100;
}
void pazymiu_ivedimas(Stud &studentas)
{
    bool stop1 = false;
    cout << "Įveskite studento pažymius (-į), baigę įveskite 0" << endl;
    do
    {
        int paz;
        cin >> paz;
        while (tinkamas_int(paz) == false)
        {
            cout << "Įveskite teisingą pažymį" << endl;
            cin >> paz;
        }

        if (paz == 0)
        {
            stop1 = true;
        }
        else
            studentas.nd.push_back(paz);
    } while (!stop1);
}

void paz_gener(Stud &studentas)
{
    int A = rand() % 10 + 2;
    for (int i = 0; i < A; i++)
    {
        int P = rand() % 10 + 1;
        cout << endl;
        cout << P << endl;
        studentas.nd.push_back(P);
    }
    cout << endl;
}
Stud vardai(Stud &studentas)
{
    int vsuma = 0;
    string F, m, n;

    int lytis = rand() % 100 + 1;
    vector<string> Vmasyvas;
    vector<string> Pmasyvas;
    ifstream f("vardai_moteru.txt");
    ifstream l("vardai_vyru.txt");
    while (getline(f, F))
    {
        vsuma += 1;
    }
    int C = rand() % vsuma;
    int W = rand() % vsuma;
    f.clear();
    f.seekg(0, ios::beg);
    if (lytis % 2 == 0)
    {
        for (int i = 0; i < vsuma; i++)
        {
            f >> m >> n;
            Vmasyvas.push_back(m);
            Pmasyvas.push_back(n);
        }
        f.close();
        studentas.vardas = Vmasyvas[C];
        studentas.pavarde = Pmasyvas[W];
        return studentas;
    }
    else
    {
        for (int y = 0; y < vsuma; y++)
        {
            l >> m >> n;
            Vmasyvas.push_back(m);
            Pmasyvas.push_back(n);
        }
        l.close();
        studentas.vardas = Vmasyvas[C];
        studentas.pavarde = Pmasyvas[W];
        return studentas;
    }
}
void duomenu_ivedimas(vector<Stud> &studentai)
{
    bool stop;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do
    {
        Stud studentas;

        if (meniu == 1 || meniu == 2)
        {
            cout << "Įveskite studento vardą, baigę įveskite 'stop'" << endl;
            getline(cin, studentas.vardas);
            while (tinkamas_char(studentas.vardas) == false)
            {
                cout << "Įveskite tinkamą vardą" << endl;
                getline(cin, studentas.vardas);
            }
            if (studentas.vardas == "stop")
            {
                stop = true;
                break;
            }

            cout << "Įveskite studento pavardę" << endl;
            getline(cin, studentas.pavarde);
            while (tinkamas_char(studentas.pavarde) == false)
            {
                cout << "Įveskite tinkamą pavardę" << endl;
                getline(cin, studentas.pavarde);
            }
            cout << "Įveskite egzamino balą" << endl;
            cin >> studentas.egzaminas;
            while (tinkamas_int(studentas.egzaminas) == false)
            {
                cout << "Įveskite teisingą egzamino rezultatą" << endl;
                cin >> studentas.egzaminas;
            }
        }

        if (meniu == 1)
        {
            pazymiu_ivedimas(studentas);
            studentas.BalasGalutinisMed = galutinismed(studentas);
            studentas.BalasGalutinisVid = galutinisvid(studentas);
        }
        else if (meniu == 2)
        {
            paz_gener(studentas);
            studentas.BalasGalutinisMed = galutinismed(studentas);
            studentas.BalasGalutinisVid = galutinisvid(studentas);
        }
        studentai.push_back(studentas);

        cout << "..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!stop);
}

void duomenu_generavimas(vector<Stud> &studentai)
{
    int Q = rand() % 10 + 1;
    for (int i = 0; i < Q; i++)
    {
        Stud studentas;
        vardai(studentas);
        studentas.egzaminas = rand() % 10 + 1;
        paz_gener(studentas);
        studentas.BalasGalutinisMed = galutinismed(studentas);
        studentas.BalasGalutinisVid = galutinisvid(studentas);
        studentai.push_back(studentas);
    }
}

void fileskait(vector<Stud> &studentai)
{
    vector<string> visaeil;
    Stud studentas;
    int pazymys;
    string eilute;
    std::stringstream bufferis;
    ifstream f("kursiokai.txt");
    bufferis << f.rdbuf(); // pointeris i bufferi
    f.close();
    // stringjibanustreamus pasiziuret
    while (bufferis)
    {
        if (!bufferis.eof())
        {
            getline(bufferis, eilute);
            visaeil.push_back(eilute);
        }
        else
            break;
    }
    for (string s : visaeil)
    {

        std::istringstream f(s);
        f >> studentas.vardas >> studentas.pavarde;
        while (f >> pazymys)
        {
            studentas.nd.push_back(pazymys);
        }
        studentas.egzaminas = studentas.nd.back();
        studentas.nd.pop_back();
        studentas.BalasGalutinisVid = galutinisvid(studentas);
        studentas.BalasGalutinisMed = galutinismed(studentas);
        studentai.push_back(studentas);
    }
}
// milijonus su tuo nejasnu vest, updatint random vietoj srand, printf implementint //random device rd
// std::mt19937 64 bits naudot mt(rd()) jeigu nera tai chromo biblioteka naudot
// uniform int distribution<int> dist(1. 11)
//...skaidrese yra fore su dist(mt)

bool PalygintiVardas(Stud stud1, Stud stud2)
{
    return stud1.vardas < stud2.vardas;
}

bool PalygintiPavardes(Stud stud1, Stud stud2)
{
    return stud1.pavarde < stud2.pavarde;
}

bool PalygintiBalaMed(Stud stud1, Stud stud2)
{
    return stud1.BalasGalutinisMed > stud2.BalasGalutinisMed;
}

bool PalygintiBalaVid(Stud stud1, Stud stud2)
{
    return stud1.BalasGalutinisVid > stud2.BalasGalutinisVid;
}

void print(vector<Stud> visi, bool outputFILE, int RusiavimasPagal)
{
    int SkaiciuotiPagal;
    cout << "Galutinis balas skaičiuojamas pagal:" << endl;
    cout << "1 - medianą\n";
    cout << "2 - vidurkį\n";
    cin >> SkaiciuotiPagal;
    std::ostream *out;
    std::ofstream f;
    if (outputFILE)
    {
        f.open("isvedimas.txt");
        out = &f;
    }
    else
        out = &cout;

    if (RusiavimasPagal == 1)
    {
        sort(visi.begin(), visi.end(), PalygintiVardas);
    }
    else if (RusiavimasPagal == 2)
    {
        sort(visi.begin(), visi.end(), PalygintiPavardes);
    }
//pagal mediana
    if (SkaiciuotiPagal == 1)
    {
        if (RusiavimasPagal == 3)
        {
            sort(visi.begin(), visi.end(), PalygintiBalaMed);
        }
        *out << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Med.)\n";
        *out << "----------------------------------------------------" << endl;
        for (Stud j : visi)
        {
            *out << std::setw(15) << std::left << j.pavarde << std::setw(15) << std::left << j.vardas << std::setw(15) << std::fixed << std::setprecision(2) << j.BalasGalutinisMed << endl;
        }
    }
    //skaiciuojam rn pagal vidurki
    else{
        if (RusiavimasPagal == 3){
            sort(visi.begin(), visi.end(), PalygintiBalaVid);
        }
        *out << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)\n";
        *out << "----------------------------------------------------" << endl;
        for (Stud j : visi)
        {
            *out << std::setw(15) << std::left << j.pavarde << std::setw(15) << std::left << j.vardas << std::setw(15) << std::fixed << std::setprecision(2) << j.BalasGalutinisVid << endl;
        }
    }
}