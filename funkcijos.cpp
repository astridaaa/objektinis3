#include "Funkciju_aprasai.h"

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

double galutinis(Stud studentas, int PagalSkaiciavimas)
{
    if (PagalSkaiciavimas == 0)
    {
        double med;
        if (studentas.nd.size() == 1)
        {
            med = studentas.nd[0];
        }

        else if (studentas.nd.size() % 2 == 0)
        {
            sort(studentas.nd.begin(), studentas.nd.end());
            med = (studentas.nd[studentas.nd.size() / 2 - 1] + studentas.nd[studentas.nd.size() / 2]) / 2;
        }
        else
        {
            med = studentas.nd[round(studentas.nd.size() / 2) - 1];
        }
        return round((0.4 * med + 0.6 * studentas.egzaminas) * 100) / 100;
    }
    else
    {
        double vidurkis;
        double suma{0.0};
        if (studentas.nd.size() == 1)
        {
            vidurkis = studentas.nd[0];
        }
        else
        {
            for (size_t ss = 0; ss < studentas.nd.size(); ss++)
            {
                suma += studentas.nd[ss];
            }

            vidurkis = suma / studentas.nd.size();
        }
        return round((0.4 * vidurkis + 0.6 * studentas.egzaminas) * 100) / 100;
    }
}

void pazymiu_ivedimas(Stud &studentas)
{
    bool stop1 = false;
    cout << "Iveskite studento pazymius (-i), baige iveskite 0" << endl;
    do
    {
        while (true)
        {
            try
            {
                int paz;
                cin >> paz;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw "Neteisingas ivestas skaicius";
                }
                if (tinkamas_int(paz) == false)
                {
                    throw "Neteisingai ivestas skaicius";
                }
                if (paz == 0 && studentas.nd.empty())
                {
                    throw "Iveskite bent viena pazymi";
                }
                if (paz == 0)
                {
                    stop1 = true;
                }
                else
                    studentas.nd.push_back(paz);
                break;
            }
            catch (const char *masyvas)
            {
                cout << masyvas << endl;
            }
        }

    } while (!stop1);
}

void paz_gener(Stud &studentas)
{
    int A = rand() % 10 + 2;
    for (int i = 0; i < A; i++)
    {
        int P = rand() % 10 + 1;
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

void duomenu_ivedimas(vector<Stud> &studentai, int meniu)
{
    bool stop;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do
    {
        Stud studentas;
        if (meniu == 1 || meniu == 2)
        {
            cout << "Iveskite studento varda, baige iveskite 'stop'" << endl;

            while (true)
            {
                try
                {
                    getline(cin, studentas.vardas);
                    if (tinkamas_char(studentas.vardas) == false)
                    {
                        cin.clear();
                        throw "Neteisingai ivedete studento varda";
                    }
                    break;
                }
                catch (const char *masyvas)
                {
                    cout << masyvas << endl;
                }
            }
            if (studentas.vardas == "stop")
            {
                stop = true;
                break;
            }
            cout << "Iveskite studento pavarde" << endl;
            while (true)
            {
                try
                {
                    getline(cin, studentas.pavarde);
                    if (tinkamas_char(studentas.pavarde) == false)
                    {
                        cin.clear();
                        throw "Neteisingai ivedete studento pavarde";
                    }
                    break;
                }
                catch (const char *masyvas)
                {
                    cout << masyvas << endl;
                }
            }
            cout << "Iveskite egzamino bala" << endl;
            while (true)
            {
                try
                {
                    cin >> studentas.egzaminas;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw "Iveskite skaiciu";
                    }
                    if (tinkamas_int(studentas.egzaminas) == false)
                    {
                        throw "Iveskite teisinga pazymi";
                    }
                    break;
                }
                catch (const char *masyvas)
                {
                    cout << masyvas << endl;
                }
            }
        }
        if (meniu == 1)
        {
            pazymiu_ivedimas(studentas);
        }
        else if (meniu == 2)
        {
            paz_gener(studentas);
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
        studentai.push_back(studentas);
    }
}

string filePasirinkimas()
{
    system("dir /b *.txt > temp.txt");
    ifstream f;
    string eilute;
    int pasirinkimuSUM = 0;
    int pasirinkimas;
    vector<string> txtfiles;
    vector<string> nenorimiFiles = {"isvedimas.txt", "vardai_moteru.txt", "vardai_vyru.txt", "temp.txt", "Studentai10000000.txt", "Pirmunai1000.txt", "Pirmunai10000.txt", "Pirmunai100000.txt", "Pirmunai1000000.txt", "Pirmunai10000000.txt", "Nesimokantys1000.txt", "Nesimokantys10000.txt", "Nesimokantys100000.txt", "Nesimokantys1000000.txt", "Nesimokantys10000000.txt"};
    f.open("temp.txt");

    while (true)
    {
        try
        {
            if (!f)
            {
                throw "Failo atidaryti nepavyko";
            }
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
            return 0;
        }
    }

    while (getline(f, eilute))
    {
        bool pasikartojantis;
        for (int a = 1; a <= nenorimiFiles.size(); a++)
        {
            if (eilute != nenorimiFiles[a - 1])
            {
                pasikartojantis = false;
            }
            else
            {
                pasikartojantis = true;
                break;
            }
        }
        if (!pasikartojantis)
        {
            txtfiles.push_back(eilute);
        }
    }
    f.close();
    system("del temp.txt");
    int a = 1;

    for (int i = 0; i < txtfiles.size(); i++)
    {
        cout << txtfiles[i] << " |" << i + 1 << " pasirinkimas" << endl;
        pasirinkimuSUM += 1;
    }
    cout << "Pasirinkite file: " << endl;
    while (true)
    {
        try
        {
            cin >> pasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Neteisingas pasirinkimas";
            }
            if (pasirinkimas > pasirinkimuSUM || pasirinkimas < 1)
            {
                throw "Neteisingas pasirinkimas";
            }
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
        }
    }

    return txtfiles[pasirinkimas - 1];
}

void fileskait(vector<Stud> &studentai, bool a, string filePav, double &BendrasLaikas)
{
    double visasLaikas = 0.0;
    vector<string> visaeil;
    Stud studentas;
    int pazymys;
    string eilute;
    string eilute1;
    ifstream f;
    std::stringstream bufferis;
    string testuojamasFile;
    if (a == false)
    {
        testuojamasFile = filePasirinkimas();
    }
    if (a == true)
    {
        testuojamasFile = filePav;
    }
    cout << "...\n";
    cout << testuojamasFile << endl;
    f.open(testuojamasFile); 
    while (true)
    {
        try
        {
            if (!f)
            {
                throw "Failo atidaryti nepavyko";
            }
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
            std::terminate();
        }
    }
    int iteracijos;
    if(testuojamasFile == "kursiokai.txt") ? iteracijos = 0 : iteracijos = 1;
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
        visasLaikas += diff.count();
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
            BendrasLaikas += visasLaikas / 2;
        }
    }
}

bool PalygintiVardas(Stud &stud1, Stud &stud2)
{
    return stud1.vardas < stud2.vardas;
}

bool PalygintiPavardes(Stud &stud1, Stud &stud2)
{
    return stud1.pavarde < stud2.pavarde;
}

bool PalygintiBalaMed(Stud &stud1, Stud &stud2)
{
    return galutinis(stud1, 0) > galutinis(stud2, 0);
}

bool PalygintiBalaVid(Stud &stud1, Stud &stud2)
{
    return galutinis(stud1, 1) > galutinis(stud2, 1);
}

bool PalygintiKategorijas(Stud &stud1, Stud &stud2)
{
    return stud1.BalasGalutinisVid > stud2.BalasGalutinisVid;
}

void print(vector<Stud> visi, bool outputFILE, int RusiavimasPagal)
{
    int SkaiciuotiPagal;
    cout << "Galutinis balas skaiciuojamas pagal: 1 - mediana, 2 - vidurkis" << endl;
    while (true)
    {
        try
        {
            int sk;
            cin >> sk;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Neteisingas pasirinkimas, iveskite skaiciu 1 arba 2";
            }
            if (sk != 1 && sk != 2)
            {
                throw "Neteisingas pasirinkimas, iveskite skaiciu 1 arba 2";
            }
            SkaiciuotiPagal = sk;
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
        }
    }

    std::ostream *out;
    std::ofstream f;
    f.open("isvedimas.txt");

    while (true)
    {
        try
        {
            if (!f)
            {
                throw "Nepavyko atidaryti failo";
            }
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
            return 0;
        }
    }

    if (outputFILE)
    {
        out = &f;
    }
    else
    {
        out = &cout;
    }
    if (RusiavimasPagal == 1)
    {
        sort(visi.begin(), visi.end(), PalygintiVardas);
    }
    else if (RusiavimasPagal == 2)
    {
        sort(visi.begin(), visi.end(), PalygintiPavardes);
    }
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
            *out << std::setw(15) << std::left << j.pavarde << std::setw(15) << std::left << j.vardas << std::setw(15) << std::fixed << std::setprecision(2) << galutinis(j, 0) << endl;
        }
    }
    else
    {
        if (RusiavimasPagal == 3)
        {
            sort(visi.begin(), visi.end(), PalygintiBalaVid);
        }
        *out << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)\n";
        *out << "----------------------------------------------------" << endl;
        for (Stud j : visi)
        {
            *out << std::setw(15) << std::left << j.pavarde << std::setw(15) << std::left << j.vardas << std::setw(15) << std::fixed << std::setprecision(2) << galutinis(j, 1) << endl;
        }
    }
}

double GeneruotiFiles(int StudSkaicius)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    string FileName = "Studentai" + std::to_string(StudSkaicius) + ".txt";
    std::stringstream BufferisTest;
    std::ofstream f;
    f.open(FileName);

    while (true)
    {
        try
        {
            if (!f)
            {
                throw "Nepavyko atidaryti failo";
            }
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
            return 0;
        }
    }

    int pazSk = dist(mt);
    auto start = std::chrono::high_resolution_clock::now(); 
    BufferisTest << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left;
    for (int j = 1; j <= pazSk; j++)
    {
        if (j != pazSk)
        {
            BufferisTest << "ND" + std::to_string(j) << std::setw(16) << std::left;
        }
        else
            BufferisTest << "EG rez." << endl;
    }
    // duomenys generuojami
    for (int i = 1; i <= StudSkaicius; i++)
    {
        BufferisTest << std::setw(16) << std::left << "Vardas" + std::to_string(i) << std::setw(16) << std::left << "Pavarde" + std::to_string(i) << std::setw(16) << std::left;
        for (int j = 1; j <= pazSk; j++)
        {
            BufferisTest << dist(mt) << std::setw(16) << std::left;
        }
        if (i != StudSkaicius)
        {
            BufferisTest << endl;
        }
    }
    f << BufferisTest.rdbuf();
    f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    return diff.count();
}

void vectorIdejimas(int studSkaicius, vector<Stud> &pirmunai, vector<Stud> &nesimokantys, double &BendrasLaikas)
{
    string file = "Studentai" + std::to_string(studSkaicius) + ".txt";
    vector<Stud> studentaiTest; 
    fileskait(studentaiTest, true, file, BendrasLaikas);

    double visasLaikas1 = 0.0;
    for (int c = 0; c < 2; c++)
    { 
        auto start1 = std::chrono::high_resolution_clock::now();
        for (Stud j : studentaiTest)
        {
            if (j.BalasGalutinisVid >= 5)
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
    cout << "Duomenu isskirstymas i dvi grupes vidutiniskai trunka: " << visasLaikas1 / 2 << "s\n";
    BendrasLaikas += visasLaikas1 / 2;
}

void PrintVektorius(vector<Stud> nesimokantys, vector<Stud> pirmunai, int a, int RusiavimasPagal, double &BendrasLaikas)
{
    string FILEMOK = "Pirmunai" + std::to_string(a) + ".txt";
    string FILENESIMOK = "Nesimokantys" + std::to_string(a) + ".txt";
    std::stringstream buferis;
    std::ofstream f, F;
    f.open(FILEMOK);

    while (true)
    {
        try
        {
            if (!f)
            {
                throw "Nepavyko atidaryti file";
            }
            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
            return 0;
        }
    }

    if (RusiavimasPagal == 1)
    {
        double LaikasRusiavimo = 0.0;
        for (int t = 0; t < 2; t++)
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            sort(nesimokantys.begin(), nesimokantys.end(), PalygintiVardas);
            sort(pirmunai.begin(), pirmunai.end(), PalygintiVardas);
            auto t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difft = t2 - t1;
            LaikasRusiavimo += difft.count();
        }

        cout << "Rusiavimas vidutiniskai uztruko: " << LaikasRusiavimo / 2 << "s" << endl;
        BendrasLaikas += LaikasRusiavimo / 2;
    }
    else if (RusiavimasPagal == 2)
    {
        double LaikasRusiavimo = 0.0;
        for (int t = 0; t < 2; t++)
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            sort(nesimokantys.begin(), nesimokantys.end(), PalygintiPavardes);
            sort(pirmunai.begin(), pirmunai.end(), PalygintiPavardes);
            auto t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difft = t2 - t1;
            LaikasRusiavimo += difft.count();
        }
        cout << "Rusiavimas vidutiniskai uztruko: " << LaikasRusiavimo / 2 << "s" << endl;
        BendrasLaikas += LaikasRusiavimo / 2;
    }
    else if (RusiavimasPagal == 3)
    {
        double LaikasRusiavimo = 0.0;
        for (int t = 0; t < 2; t++)
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            sort(nesimokantys.begin(), nesimokantys.end(), PalygintiKategorijas);
            sort(pirmunai.begin(), pirmunai.end(), PalygintiKategorijas);
            auto t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difft = t2 - t1;
            LaikasRusiavimo += difft.count();
        }

        cout << "Rusiavimas vidutiniskai uztruko: " << LaikasRusiavimo / 2 << "s" << endl;
        BendrasLaikas += LaikasRusiavimo / 2;
    }
    else if (RusiavimasPagal == 4)
    {

        cout << "Rusiavimas uztruko: 0.000 s" << endl;
    }

    double IsvedimoLaikas = 0.0;
    for (int k = 0; k < 2; k++)
    {
        auto start2 = std::chrono::high_resolution_clock::now();
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

        f.open(FILENESIMOK);
        buferis << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Galutinis (Vid.)\n";
        buferis << "----------------------------------------------------" << endl;
        for (Stud j : nesimokantys)
        {
            buferis << std::setw(16) << std::left << j.pavarde << std::setw(16) << std::left << j.vardas << std::setw(16) << std::fixed << std::setprecision(2) << j.BalasGalutinisVid << endl;
        }

        f << buferis.rdbuf();
        f.close();
        auto end2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff2 = end2 - start2;
        IsvedimoLaikas += diff2.count();
    }

    cout << "Failus vidutiniskai uztruko isvesti: " << IsvedimoLaikas / 2 << "s" << endl;
    BendrasLaikas += IsvedimoLaikas / 2;
}

void tyrimai(int pasirinkimasTyrimo)
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
        cin >> RusiavimasPagal;

        for (int a = 1000; a <= 10000000; a *= 10)
        {
            double BendrasVidLaikas = 0.0;
            vector<Stud> pirmunai;
            vector<Stud> nesimokantys;
            vectorIdejimas(a, pirmunai, nesimokantys, BendrasVidLaikas);
            PrintVektorius(nesimokantys, pirmunai, a, RusiavimasPagal, BendrasVidLaikas);
            cout << "Visos programos vykdymo laikas: ";
            cout << BendrasVidLaikas << endl;
            cout << endl;
        }
    }
}
