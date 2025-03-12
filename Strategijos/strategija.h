
#include "../main.h"
#include "../functions.h"
#include <list>
#include <type_traits>
#include <deque>
using std::deque;
using std::is_same_v;
using std::list;

template <typename konteineris>
void nuskaitymasFile(int duomenuRusiavimas, string filePavadinimas, double &visasLaikas, konteineris &studentai)
{
    double laikas = 0.0;
    std::vector<string> visaeil;
    Stud studentas;
    int pazymys;
    string eilute;
    string eilute1;
    ifstream f;
    int iteracijos = 3;
    std::stringstream bufferis;
    f.open(filePavadinimas);

    for (int i = 0; i < iteracijos; i++)
    {
        studentai.clear();
        bufferis.str("");
        bufferis.clear();
        auto start = std::chrono::high_resolution_clock::now();
        bufferis << f.rdbuf();
        f.close();
        getline(bufferis, eilute1); // praskippina pirma eilute
        while (bufferis){
            if (!bufferis.eof()){
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
            studentas.nd.clear();
            while (f >> pazymys)
            {
                studentas.nd.push_back(pazymys);
            }
            studentas.egzaminas = studentas.nd.back();
            studentas.nd.pop_back();
            studentas.BalasGalutinisVid = galutinis(studentas, 1);
            studentai.push_back(studentas);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        if (i == 1 || i == 2){laikas += diff.count();}
    }
    visasLaikas += laikas / 2;
    cout << "Failo nuskaitymas vidutiniskai truko: " << laikas / 2 << "s" << endl;
    studentai.shrink_to_fit();}

template <typename konteineris>
void studentuIsskirstymas(konteineris &studentai, double &visasLaikas, konteineris &pirmunai, konteineris &nesimokantys)
{    pirmunai.clear();
    nesimokantys.clear();
    double laikasProgramos = 0.0;

    for (int j = 0; j < 3; j++)
    {
        auto start1 = std::chrono::high_resolution_clock::now();
        for (Stud j : studentai)
        {
            if (j.BalasGalutinisVid >= 5)
            {
                pirmunai.push_back(j);
            }
            else
                nesimokantys.push_back(j);
        }
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        if (j != 0){laikasProgramos += diff1.count();}
        if(j != 2){
            pirmunai.clear();
            nesimokantys.clear();
        }
        else{
            pirmunai.shrink_to_fit();
            nesimokantys.shrink_to_fit();
        }
    }
    visasLaikas += laikasProgramos / 2;
    cout << "Studentu isskirstymas i dvi grupes vidutiniskai truko: " << laikasProgramos / 2 <<"s" << endl;
}

template <typename konteineris>
void studentuRusiavimas(int rusiavimasPagal, konteineris &pirmunai, konteineris &nesimokantys, double &visasLaikas)
{
    double programosLaikas = 0.0;
    if constexpr (is_same_v<konteineris, list<typename konteineris::value_type>>) // check ar list
    {
        for (int i = 0; i < 3; i++)
        {   auto start = std::chrono::high_resolution_clock::now();

            if (rusiavimasPagal == 1){
                nesimokantys.sort(PalygintiVardas);
                pirmunai.sort(PalygintiVardas);
            }
            else if (rusiavimasPagal == 2){
                nesimokantys.sort(PalygintiPavardes);
                pirmunai.sort(PalygintiPavardes);
            }
            else if (rusiavimasPagal == 3){
                nesimokantys.sort(PalygintiKategorijas);
                pirmunai.sort(PalygintiKategorijas);
            }
            else{cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl;}
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difference = end - start;
            if (i != 0){programosLaikas += difference.count();}
        }
        cout << "Elementu rusiavimas vidutiniskai truko: " << programosLaikas / 2 << "s"<< endl;
        visasLaikas += programosLaikas / 2;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {   auto start = std::chrono::high_resolution_clock::now();
            if (rusiavimasPagal == 1){
                sort(nesimokantys.begin(), nesimokantys.end(), PalygintiVardas);
                sort(pirmunai.begin(), pirmunai.end(), PalygintiVardas);
            }
            else if (rusiavimasPagal == 2){
                sort(nesimokantys.begin(), nesimokantys.end(), PalygintiPavardes);
                sort(pirmunai.begin(), pirmunai.end(), PalygintiPavardes);
            }
            else if (rusiavimasPagal == 3){
                sort(nesimokantys.begin(), nesimokantys.end(), PalygintiKategorijas);
                sort(pirmunai.begin(), pirmunai.end(), PalygintiKategorijas);
            }
            else
            {cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl;}
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difference = end - start;
            if (i != 0)
            {programosLaikas += difference.count();}
        }
        cout << "Elementu rusiavimas vidutiniskai truko: " << programosLaikas / 2 << "s"<< endl;
        visasLaikas += programosLaikas / 2;
    }
}
template <typename konteineris>
void testavimasPrint(konteineris &studentai, konteineris& pirmunai, konteineris& nesimokantys, int a)
{   
    string FILEMOK = "Pirmunai" + std::to_string(a) + ".txt";
    string FILENESIMOK = "Nesimokantys" + std::to_string(a) + ".txt";
    std::stringstream buferis;
    std::ofstream f, F;

    f.open(FILEMOK, ios::app);
    f.clear();
    buferis << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Galutinis (Vid.)\n";
    buferis << "----------------------------------------------------" << endl;
    for (Stud j : pirmunai)
    {
        buferis << std::setw(16) << std::left << j.pavarde << std::setw(16) << std::left << j.vardas << std::setw(16) << std::fixed << std::setprecision(2) << j.BalasGalutinisVid << endl;
    }
    
    f << buferis.rdbuf();
    buferis.str("");
    buferis.clear();
    f.close();
    F.open(FILENESIMOK, ios::app);
    F.clear();
    buferis << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Galutinis (Vid.)\n";
    buferis << "----------------------------------------------------" << endl;
    for (Stud j : nesimokantys)
    {
        buferis << std::setw(16) << std::left << j.pavarde << std::setw(16) << std::left << j.vardas << std::setw(16) << std::fixed << std::setprecision(2) << j.BalasGalutinisVid << endl;
    }

    F << buferis.rdbuf();
    F.close();
}
