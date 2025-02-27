#include "Funkciju_aprasai.h"
// #include "optimizuota_programa.h"

// su sistem dir
// randomiseris

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
    else
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
}

void pazymiu_ivedimas(Stud &studentas)
{
    bool stop1 = false;
    cout << "Iveskite studento pazymius (-i), baige iveskite 0" << endl;
    do
    {
        int paz;
        cin >> paz;
        while (tinkamas_int(paz) == false)
        {
            cout << "Iveskite teisinga pazymi" << endl;
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
            getline(cin, studentas.vardas);
            while (tinkamas_char(studentas.vardas) == false)
            {
                cout << "Iveskite tinkama varda" << endl;
                getline(cin, studentas.vardas);
            }
            if (studentas.vardas == "stop")
            {
                stop = true;
                break;
            }

            cout << "Iveskite studento pavarde" << endl;
            getline(cin, studentas.pavarde);
            while (tinkamas_char(studentas.pavarde) == false)
            {
                cout << "Iveskite tinkama pavarde" << endl;
                getline(cin, studentas.pavarde);
            }
            cout << "Iveskite egzamino bala" << endl;
            cin >> studentas.egzaminas;
            while (tinkamas_int(studentas.egzaminas) == false)
            {
                cout << "Iveskite teisinga egzamino rezultata" << endl;
                cin >> studentas.egzaminas;
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

void fileskait(vector<Stud> &studentai, int testavimas)
{
    double visasLaikas = 0.0;
    vector<string> visaeil;
    Stud studentas;
    int pazymys;
    string eilute;
    ifstream f;
    std::stringstream bufferis;

    if (testavimas == 0)
        f.open("kursiokai.txt");
    else if (testavimas == 1)
        f.open("studentai10000.txt");
    else if (testavimas == 2)
        f.open("studentai100000.txt");
    else if (testavimas == 3)
        f.open("studentai1000000.txt");

    int iteracijos;

    (testavimas == 0) ? iteracijos = 0 : iteracijos = 2;

    for (int i = 0; i <= iteracijos; i++)
    {

        studentai.clear();
        bufferis.str("");
        bufferis.clear();

        auto start = std::chrono::high_resolution_clock::now();
        bufferis << f.rdbuf();
        f.close();
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
            studentai.push_back(studentas);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        visasLaikas += diff.count();
        if (testavimas > 0 && testavimas <= 3)
        {
            cout << i + 1 << " iteracija: " << std::fixed << std::setprecision(3) << diff.count() << "s" << endl;
        }
    }
    if (testavimas > 0 && testavimas <= 3)
    {
        cout << "Programos vidutinis vykdymo laikas: " << std::fixed << std::setprecision(3) << visasLaikas / 3 << "s" << endl;
    }
}

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
    return galutinis(stud1, 0) > galutinis(stud2, 0);
}

bool PalygintiBalaVid(Stud stud1, Stud stud2)
{
    return galutinis(stud1, 1) > galutinis(stud2, 1);
}

void print(vector<Stud> visi, bool outputFILE, int RusiavimasPagal)
{
    int SkaiciuotiPagal;
    cout << "Galutinis balas skaiciuojamas pagal:" << endl;
    cout << "1 - mediana\n";
    cout << "2 - vidurki\n";
    cin >> SkaiciuotiPagal;
    std::ostream *out;
    std::ofstream f;
    f.open("isvedimas.txt");

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

string filePasirinkimas()
{
    system("dir /b *.txt > temp.txt"); //reikia vienos rodykles nes tada ne apendina bet overwritina
    ifstream f;
    string eilute;
    int sumaeil = 0;
    int pasirinkimas;
    vector<string> txtfiles;
    vector<string> nenorimiFiles = {"isvedimas.txt", "vardai_moteru.txt", "vardai_vyru.txt", "temp.txt"}; // temp.txt reikes isdelintint pries dedant i file arba i vektoriu itraukti
    f.open("temp.txt");
    while (getline(f, eilute))
    {   bool pasikartojantis;
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
    cout << "Pasirinkite file: " << endl;
    int a = 1;

    for (int i = 0; i < txtfiles.size(); i++)
    {
        cout << txtfiles[i] << " |" << i+1 << " pasirinkimas" << endl;
    }
    cin >> pasirinkimas;
    return txtfiles[pasirinkimas -1];
    // returna reikes padaryti
}
