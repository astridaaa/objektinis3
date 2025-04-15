
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "main.h"

bool tinkamas_char(string vardas);
bool tinkamas_int(int skaicius);
//double galutinis(Stud studentas, int PagalSkaiciavimas);
void pazymiu_ivedimas(Stud &studentas);
void paz_gener(Stud &studentas);
Stud vardai(Stud &studentas);
void duomenu_ivedimas(vector<Stud> &studentai, int meniu);
void duomenu_generavimas(vector<Stud> &studentai);
void printCases(vector<Stud> visi, bool outputFILE, int RusiavimasPagal);
void konstruktoriuTest();
string filePasirinkimas();

template <typename konteineris>
void fileskait(konteineris &studentai, bool a, string filePav, double &BendrasLaikas)
{
    double visasLaikas = 0.0;
    vector<string> visaeil;
    int pazymys;
    string eilute;
    string eilute1;
    ifstream f;
    std::stringstream bufferis;
    string testuojamasFile;
    if (a == false){
        testuojamasFile = filePasirinkimas();
    }
    if (a == true){
        testuojamasFile = filePav;
    }
    cout << "...\n";
    cout << testuojamasFile << endl;

    if (testuojamasFile != "kursiokai.txt"){
        testuojamasFile = "Strategijos\\Tyrimo_files\\" + testuojamasFile;
    }

    while (true)
    {
        try
        {
            f.open(testuojamasFile);
            if (!f)
            {
                throw "Failo atidaryti nepavyko";
            }
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
            testuojamasFile = filePasirinkimas();

            continue;
        }
    }
    int iteracijos;
    (testuojamasFile == "kursiokai.txt") ? iteracijos = 0 : iteracijos = 2;
    for (int i = 0; i <= iteracijos; i++)
    {
        studentai.clear();
        bufferis.str("");
        bufferis.clear();
        auto start = std::chrono::high_resolution_clock::now();
        bufferis << f.rdbuf();
        f.close();
        getline(bufferis, eilute1);
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

        for ( string s : visaeil)
        {
            string vardas, pavarde;
            Stud studentas;
            std::istringstream f(s);
            f>>vardas>>pavarde;
            studentas.setVardas(vardas);
            studentas.setPavarde(pavarde);
            while (f >> pazymys)
            {
                studentas.setND(pazymys);
            }
            studentas.setEgzaminas(studentas.grazintiPaskutini());
            studentas.removeLast();
            studentas.galutinis();
            studentai.push_back(studentas);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        if (i != 0){
            visasLaikas += diff.count();
        }
        if (testuojamasFile != "kursiokai.txt" && a == false)
        {
            cout << i + 1 << " iteracija: " << std::fixed << std::setprecision(3) << diff.count() << "s" << endl;
        }
    }
    if (testuojamasFile != "kursiokai.txt")
    {

        if (a == false)
        {
            cout << "Programos vidutinis vykdymo laikas: " << std::fixed << std::setprecision(3) << visasLaikas / 2 << "s" << endl;
        }
        if (a == true)
        {
            cout << "Nuskaitymas is failo vidutiniskai truko: " << std::fixed << std::setprecision(3) << visasLaikas / 2 << "s" << endl;
            BendrasLaikas += (visasLaikas / 2);
        }
    }
}

double GeneruotiFiles(int StudSkaicius);
bool PalygintiVardas(const Stud &stud1, const Stud &stud2);
bool PalygintiPavardes(const Stud &stud1, const Stud &stud2);
bool PalygintiKategorijas(const Stud &stud1, const Stud &stud2);

template <typename konteineris>
void PrintVektorius(konteineris &nesimokantys, konteineris &pirmunai, int a, int RusiavimasPagal, double &BendrasLaikas)
{
    string FILEMOK = "Pirmunai" + std::to_string(a) + ".txt";
    string FILENESIMOK = "Nesimokantys" + std::to_string(a) + ".txt";
    std::stringstream buferis;
    std::ofstream f, F;
    f.open(FILEMOK);

    if (RusiavimasPagal == 1)
    {
        double LaikasRusiavimo = 0.0;
        for (int t = 0; t < 3; t++)
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            if constexpr (std::is_same_v<konteineris, vector<Stud>> || std::is_same_v<konteineris, deque<Stud>>){
                sort(nesimokantys.begin(), nesimokantys.end(), PalygintiVardas);
                sort(pirmunai.begin(), pirmunai.end(), PalygintiVardas);}
            else{
                nesimokantys.sort(PalygintiVardas);
                pirmunai.sort(PalygintiVardas);}

            auto t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difft = t2 - t1;
            if (t != 0){
                LaikasRusiavimo += difft.count();}
        }

        cout << "Rusiavimas vidutiniskai uztruko: " << LaikasRusiavimo / 2 << "s" << endl;
        BendrasLaikas += (LaikasRusiavimo / 2);
    }
    else if (RusiavimasPagal == 2){
        double LaikasRusiavimo = 0.0;
        for (int t = 0; t < 3; t++){
            auto t1 = std::chrono::high_resolution_clock::now();
            if constexpr (std::is_same_v<konteineris, vector<Stud>> || std::is_same_v<konteineris, deque<Stud>>){
                sort(nesimokantys.begin(), nesimokantys.end(), PalygintiPavardes);
                sort(pirmunai.begin(), pirmunai.end(), PalygintiPavardes);
            }
            else{
                nesimokantys.sort(PalygintiPavardes);
                pirmunai.sort(PalygintiPavardes);
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difft = t2 - t1;
            if (t != 0){
                LaikasRusiavimo += difft.count();}
        }
        cout << "Rusiavimas vidutiniskai uztruko: " << LaikasRusiavimo / 2 << "s" << endl;
        BendrasLaikas += (LaikasRusiavimo / 2);
    }
    else if (RusiavimasPagal == 3){
        double LaikasRusiavimo = 0.0;
        for (int t = 0; t < 3; t++){
            auto t1 = std::chrono::high_resolution_clock::now();
            if constexpr (std::is_same_v<konteineris, vector<Stud>> || std::is_same_v<konteineris, deque<Stud>>){
                sort(nesimokantys.begin(), nesimokantys.end(), PalygintiKategorijas);
                sort(pirmunai.begin(), pirmunai.end(), PalygintiKategorijas);
            }
            else
            {
                nesimokantys.sort(PalygintiKategorijas);
                pirmunai.sort(PalygintiKategorijas);
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difft = t2 - t1;
            if (t != 0){
                LaikasRusiavimo += difft.count();
            }
        }
        cout << "Rusiavimas vidutiniskai uztruko: " << LaikasRusiavimo / 2 << "s" << endl;
        BendrasLaikas += (LaikasRusiavimo / 2);
    }
    else if (RusiavimasPagal == 4){
        cout << "Rusiavimas uztruko: 0.000 s" << endl;
    }

    double IsvedimoLaikas = 0.0;
    for (int k = 0; k < 2; k++){
        auto start2 = std::chrono::high_resolution_clock::now();
        buferis << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Galutinis (Vid.)\n";
        buferis << "----------------------------------------------------" << endl;
        for (Stud j : pirmunai)
        {
            buferis << std::setw(16) << std::left << j.getPavarde() << std::setw(16) << std::left << j.getVardas() << std::setw(16) << std::fixed << std::setprecision(2) << j.galutinisBalas() << endl;
        }
        f << buferis.rdbuf();
        buferis.str("");
        buferis.clear();
        f.close();
        pirmunai.clear();
        f.open(FILENESIMOK);
        buferis << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Galutinis (Vid.)\n";
        buferis << "----------------------------------------------------" << endl;
        for (Stud j : nesimokantys)
        {
            buferis << std::setw(16) << std::left << j.getPavarde() << std::setw(16) << std::left << j.getVardas() << std::setw(16) << std::fixed << std::setprecision(2) << j.galutinisBalas() << endl;
        }
        f << buferis.rdbuf();
        f.close();
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;
    }
    nesimokantys.clear();
}

template <typename konteineris>
void vectorIdejimas(int studSkaicius, konteineris &pirmunai, konteineris &nesimokantys, double &BendrasLaikas, konteineris &studentaiTest)
{
    string file = "Studentai" + std::to_string(studSkaicius) + ".txt";
    studentaiTest;
    fileskait(studentaiTest, true, file, BendrasLaikas);
    double visasLaikas1 = 0.0;
    for (int c = 0; c < 2; c++)
    {
        auto start1 = std::chrono::high_resolution_clock::now();
        for ( Stud& j : studentaiTest)
        {
            if (j.galutinisBalas() >= 5)
            {
                pirmunai.push_back(j);
            }
            else
                nesimokantys.push_back(j);
        }
        auto end1 = std::chrono::high_resolution_clock::now();
        studentaiTest.clear();
        std::chrono::duration<double> diff1 = end1 - start1;
        visasLaikas1 += diff1.count();
    }
    if constexpr (std::is_same_v<konteineris, vector<Stud>> || std::is_same_v<konteineris, deque<Stud>>)
    {
        pirmunai.shrink_to_fit();
        nesimokantys.shrink_to_fit();
    }

    cout << "Duomenu isskirstymas i dvi grupes vidutiniskai trunka: " << visasLaikas1 / 2 << "s\n";
    BendrasLaikas += visasLaikas1 / 2;
}

template <typename konteineris>
void tyrimai(int pasirinkimasTyrimo, konteineris &pirmunai, konteineris &nesimokantys, konteineris &studentaiTest)
{
    if (pasirinkimasTyrimo == 1)
    {
        for (int a = 1000; a <= 10000000; a *= 10)
        {
            cout << "Studentai" << a << ".txt\n";
            double laikas = 0.0;
            for (int i = 0; i < 2; i++)
            {
                double s = GeneruotiFiles(a);
                cout << i + 1 << " iteracija: " << s << "s" << endl;
                laikas += s;
            }
            cout << "Studentai" << a << ".txt vidutiniskai generuoja: " << laikas / 2 << "s" << endl;
            cout << "...\n";
        }
    }
    else if (pasirinkimasTyrimo == 2)
    {
        int RusiavimasPagal;
        cout << "Studentus rusiuoti pagal: 1 - vardus, 2 - pavardes, 3 - galutini bala, 4 - duomenu nerusiuoti\n";
        while (true){
            try
            {
                cin >> RusiavimasPagal;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw "Neteisingas pasirinkimas, iveskite skaiciu 1-4";
                    break;
                }
                else if (RusiavimasPagal > 4 || RusiavimasPagal < 1){
                    throw "Neteisingas pasirinkimas, iveskite skaiciu 1-4";
                    break;
                }
                break;
            }
            catch (const char *masyvas){
                cout << masyvas << endl;}
        }
        for (int a = 1000; a <= 10000000; a *= 10)
        {
            double BendrasVidLaikas = 0.0;
            vectorIdejimas(a, pirmunai, nesimokantys, BendrasVidLaikas, studentaiTest);
            PrintVektorius(nesimokantys, pirmunai, a, RusiavimasPagal, BendrasVidLaikas);
            cout << "Visos programos vykdymo laikas: ";
            cout << BendrasVidLaikas << "s" << endl;
            cout << endl;
        }
    }
}
#endif