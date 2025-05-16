#ifndef strategija_h
#define strategija_h
#include "../vectorClass/vector.h"

bool PalygintiVardas(const Stud &stud1, const Stud &stud2);
bool PalygintiPavardes(const Stud &stud1, const Stud &stud2);
bool PalygintiKategorijas(const Stud &stud1, const Stud &stud2);

template <typename konteineris>
void nuskaitymasFile(string filePavadinimas, double &visasLaikas, konteineris &studentai)//cia pakeisti
{
    double laikas = 0.0;
    Vector<string> visaeil;
    int pazymys;
    string eilute;
    string eilute1;
    ifstream f;
    std::stringstream bufferis;
    f.open(filePavadinimas);
    for (int i = 0; i < 3; i++)
    {
        studentai.clear();
        bufferis.clear();
        bufferis.str("");
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

        for (const string& s : visaeil)
        {
            string var, pav; 
            Stud studentas; 
            std::istringstream f(s);
            f >> var >> pav;
            studentas.setVardas(var);
            studentas.setPavarde(pav);
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
        if (i != 0)
        {
            laikas += diff.count();
        }
    }

    visasLaikas += (laikas / 2);
    cout << "Failo nuskaitymas vidutiniskai truko: " << laikas / 2 << "s" << endl;
    visaeil.clear();
    if constexpr (!std::is_same_v<konteineris, std::list<Stud>>)
    {
        studentai.shrink_to_fit();
    }

    visaeil.clear();
}

template <typename konteineris>
void studentuIsskirstymas(konteineris &studentai, double &visasLaikas, konteineris &pirmunai, konteineris &nesimokantys)
{
    double laikasProgramos = 0.0;

    for (int i = 0; i < 3; i++)
    {
        auto start1 = std::chrono::high_resolution_clock::now();
        for (Stud& j : studentai)
        {
            if (j.galutinisBalas() >= 5)
            {
                pirmunai.push_back(j);
            }
            else
                nesimokantys.push_back(j);
        }
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        if (i != 0)
        {
            laikasProgramos += diff1.count();
        }
        if (i != 2)
        {
            pirmunai.clear();
            nesimokantys.clear();
        }
        if constexpr (std::is_same_v<konteineris, vector<Stud>> || std::is_same_v<konteineris, deque<Stud>>)
        {
            pirmunai.shrink_to_fit();
            nesimokantys.shrink_to_fit();
        }
    }
    visasLaikas += (laikasProgramos / 2);
    cout << "Studentu isskirstymas i dvi grupes vidutiniskai truko: " << laikasProgramos / 2 << "s" << endl;
}

template <typename konteineris>
void studentuRusiavimas(int &rusiavimasPagal, konteineris &pirmunai, konteineris &nesimokantys, double &visasLaikas)
{
    double time = 0.0;
    if constexpr (std::is_same_v<konteineris, std::list<Stud>>)
    {
        for (int i = 0; i < 3; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();

            std::thread t1([&]()
                           {
                if (rusiavimasPagal == 1) pirmunai.sort(PalygintiVardas);
                else if (rusiavimasPagal == 2) pirmunai.sort(PalygintiPavardes);
                else if (rusiavimasPagal == 3) pirmunai.sort(PalygintiKategorijas);
                else cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl; });

            std::thread t2([&]()
                           {
                if (rusiavimasPagal == 1) nesimokantys.sort(PalygintiVardas);
                else if (rusiavimasPagal == 2) nesimokantys.sort(PalygintiPavardes);
                else if (rusiavimasPagal == 3) nesimokantys.sort(PalygintiKategorijas);
                else cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl; });

            t1.join();
            t2.join();

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            if (i != 0)
            {
                time += diff.count();
            }
        }
        cout << "Elementu rusiavimas vidutiniskai truko: " << time / 2 << "s" << endl;
        visasLaikas += (time / 2);
    }
    else
    {
        for (int j = 0; j < 3; j++)
        {
            auto start = std::chrono::high_resolution_clock::now();

            std::thread t1([&]()
                           {
                if(rusiavimasPagal == 1) std::sort(pirmunai.begin(), pirmunai.end(), PalygintiVardas);
                else if(rusiavimasPagal == 2) std::sort(pirmunai.begin(), pirmunai.end(), PalygintiPavardes);
                else if(rusiavimasPagal == 3) std::sort(pirmunai.begin(), pirmunai.end(), PalygintiKategorijas);
                else cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl; });

            std::thread t2([&]()
                           {
                if(rusiavimasPagal == 1) std::sort(nesimokantys.begin(), nesimokantys.end(), PalygintiVardas);
                else if(rusiavimasPagal == 2) std::sort(nesimokantys.begin(), nesimokantys.end(), PalygintiPavardes);
                else if(rusiavimasPagal == 3) std::sort(nesimokantys.begin(), nesimokantys.end(), PalygintiKategorijas);
                else cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl; });

            t1.join();
            t2.join();

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difference = end - start;
            if (j != 0)
            {
                time += difference.count();
            }
        }
        cout << "Elementu rusiavimas vidutiniskai truko: " << time / 2 << "s" << endl;
        visasLaikas += (time / 2);
    }
}

template <typename konteineris>
void testavimasPrint(konteineris &studentai, konteineris &pirmunai, konteineris &nesimokantys, int a)
{
    string FILEMOK = "Pirmunai" + std::to_string(a) + ".txt";
    string FILENESIMOK = "Nesimokantys" + std::to_string(a) + ".txt";
    std::stringstream buferis;
    std::ofstream f, F;

    f.open(FILEMOK, ios::app);
    f.clear();
    buferis << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Galutinis (Vid.)\n";
    buferis << "----------------------------------------------------" << endl;
    for (Stud& j : studentai)//PAKEICIAU IS PIRMUNU I STUDENTUS
    {
        buferis << std::setw(16) << std::left << j.getPavarde() << std::setw(16) << std::left << j.getVardas() << std::setw(16) << std::fixed << std::setprecision(2) << j.galutinisBalas() << endl;
    }

    f << buferis.rdbuf();
    buferis.str("");
    buferis.clear();
    f.close();
    F.open(FILENESIMOK, ios::app);
    F.clear();
    buferis << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Galutinis (Vid.)\n";
    buferis << "----------------------------------------------------" << endl;
    for (Stud& j : nesimokantys)
    {
        buferis << std::setw(16) << std::left << j.getPavarde() << std::setw(16) << std::left << j.getVardas() << std::setw(16) << std::fixed << std::setprecision(2) << j.galutinisBalas() << endl;
    }

    F << buferis.rdbuf();
    F.close();
}

template <typename konteineris>
void vykdomaPrograma(int &rusiavimasPagal, konteineris &studentai, konteineris &pirmunai, konteineris &nesimokantys){
    for (int a = 1000; a <= 10000000; a *= 10)
    {
        studentai.clear();
        nesimokantys.clear();
        pirmunai.clear();
        double visasLaikas = 0.0;
        string testavimoFile = "Strategijos\\Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
        cout << "...\n"
             << std::to_string(a) + ".txt" << endl;
        nuskaitymasFile(testavimoFile, visasLaikas, studentai);
        studentuIsskirstymas(studentai, visasLaikas, pirmunai, nesimokantys);
        studentuRusiavimas(rusiavimasPagal, pirmunai, nesimokantys, visasLaikas);
        // testavimasPrint(studentai, pirmunai, nesimokantys, a);
        cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
    }
}

template <typename konteineris>
void studentuRusiavimas2(int rusiavimasPagal, konteineris &studentai, double &visasLaikas, double &rusiavimoLaikas)
{
    auto start = std::chrono::high_resolution_clock::now();
    if constexpr (std::is_same_v<konteineris, std::list<Stud>>)
        studentai.sort(PalygintiKategorijas);
    else
        sort(std::execution::par, studentai.begin(), studentai.end(), PalygintiKategorijas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;

    cout << "Studetus rusiuoja: " << difference.count() << endl;
    visasLaikas += difference.count();
    rusiavimoLaikas += difference.count();
}

template <typename konteineris>
void studentuIsskirstymas2(konteineris &studentai, double &visasLaikas, konteineris &nesimokantys, double &rusiavimoLaikas)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto it = studentai.end();

    while (true)
    {
        --it; // nes pointina ne i galutini elementa, bet i adresa po galutinio elemento
        if (it->galutinisBalas() < 5)
        {
            nesimokantys.push_back(*it);
            studentai.pop_back();
        }
        else
            break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    if constexpr (std::is_same_v<konteineris, std::vector<Stud>> ||
                  std::is_same_v<konteineris, std::deque<Stud>>)
    {
        studentai.shrink_to_fit();
    }
    cout << "Studentus vidutiniskai skirste i dvi grupes: " << difference.count() << "s" << endl;
    visasLaikas += difference.count();
    auto start2 = std::chrono::high_resolution_clock::now();
    if constexpr (std::is_same_v<konteineris, std::list<Stud>>)
    {
        nesimokantys.sort(PalygintiKategorijas);
    }
    else
    {
        sort(std::execution::par, nesimokantys.begin(), nesimokantys.end(), PalygintiKategorijas);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference2 = end2 - start2;
        cout << "Nesimokanciu konteinerio rusiavimas truko: " << difference2.count() << "s" << endl;
        cout << "Bendras rusiavimo laikas: " << rusiavimoLaikas + difference2.count() << "s" << endl;
        visasLaikas += difference2.count();
    }
}

template <typename konteineris>
void vykdomaPrograma2(int rusiavimasPagal, konteineris &studentai, konteineris &nesimokantys)
{
    for (int a = 1000; a <= 10000000; a *= 10)
    {
        studentai.clear();
        nesimokantys.clear();
        double visasLaikas = 0.0;
        string testavimoFile = "Strategijos\\Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
        cout << "...\n"
             << std::to_string(a) + ".txt" << endl;
        double rusiavimoLaikas = 0.0;
        nuskaitymasFile(testavimoFile, visasLaikas, studentai);
        studentuRusiavimas2(rusiavimasPagal, studentai, visasLaikas, rusiavimoLaikas);
        studentuIsskirstymas2(studentai, visasLaikas, nesimokantys, rusiavimoLaikas);
        // testavimasPrint(studentai, nesimokantys, nesimokantys, a);
        cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
    }
}

template <typename konteineris>
void studentuSkirstymas3(konteineris &studentai, konteineris &nesimokantys, double &visasLaikas)
{
    nesimokantys.clear();
    auto start = std::chrono::high_resolution_clock::now();
    auto it = std::partition(studentai.begin(), studentai.end(), [](Stud &studentas){ return studentas.galutinisBalas() >= 5; });
    nesimokantys.resize(std::distance(it, studentai.end()));
    std::copy(it, studentai.end(), nesimokantys.begin());
    studentai.erase(it, studentai.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Studentu skirstymas i dvi grupes truko: " << diff.count() << "s" << endl;
    visasLaikas += diff.count();
}

template <typename konteineris>
void StudentuRusiavimas3(konteineris &Studentai, konteineris &nesimokantys, double &visasLaikas, int RusiuotiPagal)
{
    if constexpr (std::is_same_v<konteineris, std::list<Stud>>)
    {
        auto start = std::chrono::high_resolution_clock::now();

        if (RusiuotiPagal == 1) 
            Studentai.sort(PalygintiVardas);
        else if (RusiuotiPagal == 2) 
            Studentai.sort(PalygintiPavardes);
        else if (RusiuotiPagal == 3) 
            Studentai.sort(PalygintiKategorijas);
        else 
            cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl;

        if (RusiuotiPagal == 1) 
            nesimokantys.sort(PalygintiVardas);
        else if (RusiuotiPagal == 2) 
            nesimokantys.sort(PalygintiPavardes);
        else if (RusiuotiPagal == 3) 
            nesimokantys.sort(PalygintiKategorijas);
        else 
            cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl;

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Studentu rusiavimas uztruko: " << diff.count() << endl;
        visasLaikas += diff.count();
    }
    else
    {
        auto start = std::chrono::high_resolution_clock::now();

        if (RusiuotiPagal == 1) 
            std::sort(Studentai.begin(), Studentai.end(), PalygintiVardas);
        else if (RusiuotiPagal == 2) 
            std::sort(Studentai.begin(), Studentai.end(), PalygintiPavardes);
        else if (RusiuotiPagal == 3) 
            std::sort(Studentai.begin(), Studentai.end(), PalygintiKategorijas);
        else 
            cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl;

        if (RusiuotiPagal == 1) 
            std::sort(nesimokantys.begin(), nesimokantys.end(), PalygintiVardas);
        else if (RusiuotiPagal == 2) 
            std::sort(nesimokantys.begin(), nesimokantys.end(), PalygintiPavardes);
        else if (RusiuotiPagal == 3) 
            std::sort(nesimokantys.begin(), nesimokantys.end(), PalygintiKategorijas);
        else 
            cout << "Elementu rusiavimas vidutiniskai truko: 0.000s" << endl;

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout << "Studentu rusiavimas uztruko: " << difference.count() << "s" << endl;
        visasLaikas += difference.count();
    }
}

template <typename konteineris>
void vykdomaPrograma3(int rusiavimasPagal, konteineris &studentai, konteineris &nesimokantys)
{
    for (int a = 1000; a <= 10000000; a *= 10)
    {
        studentai.clear();
        nesimokantys.clear();
        double visasLaikas = 0.0;
        string testavimoFile = "Strategijos\\Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
        cout << "...\n" << std::to_string(a) + ".txt" << endl;
        double rusiavimoLaikas = 0.0;
        nuskaitymasFile(testavimoFile, visasLaikas, studentai);
        studentuSkirstymas3(studentai, nesimokantys, visasLaikas);
        StudentuRusiavimas3(studentai, nesimokantys, visasLaikas, rusiavimasPagal);
        //testavimasPrint(studentai, nesimokantys, nesimokantys, a);
        //print(studentai, nesimokantys, rusiavimasPagal, a);
        cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
    }
    //konstruktoriuTest();
}

inline void paleistiStrategija3(){
    int konteineriuTipas;
    int rusiavimasPagal;
    cout << "Programa testuojama su:\n";
    cout << "1 | vector tipo konteineriu\n";
    cout << "2 | deque tipo konteineriu\n";
    cout << "3 | list tipo konteineriu\n";
    while (true)
    {   try
        {   cin >> konteineriuTipas;
            if (cin.fail())
            {   cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Iveskite skaiciu";
                break;}
            else if (konteineriuTipas > 3 || konteineriuTipas < 1)
                {throw "Neteisingas pasirinkimas, iveskite skaiciu 1-3";
                break;}
            break;
        }
        catch (const char *masyvas)
        {cout << masyvas << endl;}
    }
    cout << "Studentus rusiuoti pagal:\n";
    cout << "1 | Vardus\n";
    cout << "2 | Pavardes\n";
    cout << "3 | Galutini bala\n";
    cout << "4 | Duomenu nerusiuoti\n";
    while (true)
    {   try
        {   cin >> rusiavimasPagal;
            if (cin.fail())
            {   cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Iveskite skaiciu";
                break;}
            else if (rusiavimasPagal > 4 || rusiavimasPagal < 1)
                {throw "Neteisingas pasirinkimas, iveskite skaiciu 1-4";
                break;}
            break;
        }
        catch (const char *masyvas)
        {cout << masyvas << endl;}
    }

    if (konteineriuTipas == 1) {
        //konteinerisVector studentai, nesimokantys; std::vector
        Vector<Stud> studentai;
        Vector<Stud> nesimokantys;
        vykdomaPrograma3(rusiavimasPagal, studentai, nesimokantys);
    }
    else if (konteineriuTipas == 2) {
        konteinerisDeque studentai, nesimokantys;
        vykdomaPrograma3(rusiavimasPagal, studentai, nesimokantys);
    }
    else{
        konteinerisList studentai, nesimokantys;
        vykdomaPrograma3(rusiavimasPagal, studentai, nesimokantys);
    }
}

inline void paleistiStrategija2(){
    int konteineriuTipas;
    int rusiavimasPagal;
    cout << "Programa testuojama su:\n";
    cout << "1 | vector tipo konteineriu\n";
    cout << "2 | deque tipo konteineriu\n";
    cout << "3 | list tipo konteineriu\n";
    while (true)
    {   try
        {   cin >> konteineriuTipas;
            if (cin.fail())
            {   cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Iveskite skaiciu";
                break;}
            else if (konteineriuTipas > 3 || konteineriuTipas < 1)
                {throw "Neteisingas pasirinkimas, iveskite skaiciu 1-3";
                break;}
            break;
        }
        catch (const char *masyvas)
        {cout << masyvas << endl;}
    }
    cout << "Studentus rusiuoti pagal:\n";
    cout << "1 | Vardus\n";
    cout << "2 | Pavardes\n";
    cout << "3 | Galutini bala\n";
    cout << "4 | Duomenu nerusiuoti\n";
    while (true)
    {   try
        {   cin >> rusiavimasPagal;
            if (cin.fail())
            {   cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Iveskite skaiciu";
                break;}
            else if (rusiavimasPagal > 4 || rusiavimasPagal < 1)
                {throw "Neteisingas pasirinkimas, iveskite skaiciu 1-4";
                break;}
            break;
        }
        catch (const char *masyvas)
        {cout << masyvas << endl;}
    }

    if (konteineriuTipas == 1) {
        konteinerisVector studentai, nesimokantys;
        vykdomaPrograma2(rusiavimasPagal, studentai, nesimokantys);
    }
    else if (konteineriuTipas == 2) {
        konteinerisDeque studentai, nesimokantys;
        vykdomaPrograma2(rusiavimasPagal, studentai, nesimokantys);
    }
    else{
        konteinerisList studentai, nesimokantys;
        vykdomaPrograma2(rusiavimasPagal, studentai, nesimokantys);
    }
}

inline void paleistiStrategija1(){
    int konteineriuTipas;
    int rusiavimasPagal;
    cout << "Programa testuojama su:" << endl;
    cout << "1 | vector tipo konteineriu" << endl;
    cout << "2 | deque tipo konteineriu" << endl;
    cout << "3 | list tipo konteineriu" << endl;
    while (true)
    {   try
        {   cin >> konteineriuTipas;
            if (cin.fail())
            {   cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Iveskite skaiciu";
                break;}
            else if (konteineriuTipas > 3 || konteineriuTipas < 1)
                {throw "Neteisingas pasirinkimas, iveskite skaiciu 1-3";
                break;}
            break;
        }
        catch (const char *masyvas)
        {cout << masyvas << endl;}
    }

    cout << "Studentus rusiuoti pagal:" << endl;
    cout << "1 | Vardus\n";
    cout << "2 | Pavardes\n";
    cout << "3 | Galutini bala\n";
    cout << "4 | Duomenu nerusiuoti\n";
    while (true)
    {   try
        {   cin >> rusiavimasPagal;
            if (cin.fail())
            {   cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Iveskite skaiciu";
                break;}
            else if (rusiavimasPagal > 4 || rusiavimasPagal < 1)
                {throw "Neteisingas pasirinkimas, iveskite skaiciu 1-4";
                break;}
            break;
        }
        catch (const char *masyvas)
        {cout << masyvas << endl;}
    }

    if (konteineriuTipas == 1) {
        konteinerisVector studentai, pirmunai, nesimokantys;
       vykdomaPrograma(rusiavimasPagal, studentai, pirmunai, nesimokantys);
    }
    else if (konteineriuTipas == 2) {
        konteinerisDeque studentai, pirmunai, nesimokantys;
       vykdomaPrograma(rusiavimasPagal, studentai, pirmunai, nesimokantys);
    }
    else{
        konteinerisList studentai, pirmunai, nesimokantys;
        vykdomaPrograma(rusiavimasPagal, studentai, pirmunai, nesimokantys);
    }
}
#endif