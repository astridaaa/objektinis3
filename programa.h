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

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::getline;
using std::ifstream;
using std::ios;
using std::isalpha;
using std::isdigit;
using std::isspace;
using std::left;
using std::numeric_limits;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

struct Stud
{
    string vardas, pavarde;
    int EGrez;
    vector<int> NDrez;
};

int paz;
vector<Stud> VISIstud;
bool stop;
bool stop1;
int meniu;
bool stop2;


double galutinis(Stud stud)
{
    int b = rand() % 11 + 1;
    if (b % 2 == 0)
    {
        double vidurkis;
        double suma = 0;

        for (int p : stud.NDrez)
        {
            suma += p;
        }
        vidurkis = suma / stud.NDrez.size();
        double Gbalas_vid = round((0.4 * vidurkis + 0.6 * stud.EGrez) * 100) / 100;
        return Gbalas_vid;
    }
    else
    {
        double med;
        double Gbalas_med;
        sort(stud.NDrez.begin(), stud.NDrez.end());
        if (stud.NDrez.size() % 2 == 0)
        {
            med = (stud.NDrez[stud.NDrez.size() / 2 - 1] + stud.NDrez[stud.NDrez.size() / 2]) / 2;
        }
        else
        {
            med = stud.NDrez[round(stud.NDrez.size() / 2) - 1];
        }
        Gbalas_med = round((0.4 * med + 0.6 * stud.EGrez) * 100) / 100;
        return Gbalas_med;
    }
}

bool tinkamas(string vardas)
{
    for (char a : vardas)
    {
        if (isalpha(a) == false || isspace(a) == true)
        {
            return false;
        }
        else
            continue;
    }

    return true;
}

Stud mot(Stud &studentas)
{
    int vsuma = 0;
    string F;
    string x, y, m, n;
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
    int lytis = rand() % 100 + 1;
    f.clear(); 
    f.seekg(0, ios::beg);
    if (lytis % 2 == 0)
    {
        for (int i = 0; i < vsuma; i++)
        {
            f >> x >> y;
            Vmasyvas.push_back(x);
            Pmasyvas.push_back(y);
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
        f.close();
        studentas.vardas = Vmasyvas[W];
        studentas.pavarde = Pmasyvas[C];
        return studentas;
    }
}