#include "../functions.h"

//realizuotas copy konstruktorius
Stud::Stud(const Stud& studCopy) :
    /*vardas(studCopy.vardas),
    pavarde(studCopy.pavarde),*/
    zmogus(studCopy.getVardas(), studCopy.getPavarde()),
    egzaminas(studCopy.egzaminas),
    nd(studCopy.nd),
    BalasGalutinisVid(studCopy.BalasGalutinisVid),
    balasSuskaiciuotas(studCopy.balasSuskaiciuotas) {}

//realizuotas copy assignment operatorius
Stud& Stud::operator=(const Stud& studCopy){ 
    if(this != &studCopy){ 
        //vardas = studCopy.vardas;
        //pavarde = studCopy.pavarde;
        setVardas(studCopy.getVardas());
        setPavarde(studCopy.getPavarde());
        nd = studCopy.nd;
        egzaminas = studCopy.egzaminas;
        BalasGalutinisVid = studCopy.BalasGalutinisVid;
        balasSuskaiciuotas = studCopy.balasSuskaiciuotas;}
    return *this;
}

//realizuotas move konstruktorius
Stud::Stud(Stud&& studMove) :       //normalu destruktoriu pasidaryti ji iskviesti ir tada tikrinti ar yra lygus 0
    /*vardas(std::move(studMove.vardas)),
    pavarde(std::move(studMove.pavarde)),*/
    zmogus(std::move(studMove)),
    nd(std::move(studMove.nd)),
    egzaminas(std::move(studMove.egzaminas)),
    BalasGalutinisVid(std::move(studMove.BalasGalutinisVid)),
    balasSuskaiciuotas(std::move(studMove.balasSuskaiciuotas)){studMove.clear();}

//realizuotas move assignment operatorius
Stud& Stud::operator=(Stud&& studMove){
    if (this != &studMove) {
        //vardas = std::move(studMove.vardas);
        //pavarde = std::move(studMove.pavarde);
        zmogus::operator=(std::move(studMove));
        nd = std::move(studMove.nd);
        egzaminas = std::move(studMove.egzaminas);
        BalasGalutinisVid = std::move(studMove.BalasGalutinisVid);
        balasSuskaiciuotas = std::move(studMove.balasSuskaiciuotas);
        studMove.clear();
} 
return *this;}

bool tikrinimas(const Stud& s, const Stud& s1){
    if(s.getVardas() == s1.getVardas() && s.getPavarde() == s1.getPavarde() && s.getEgzaminas() == s1.getEgzaminas() && s.getND() == s1.getND()){
        return true;
    }
    else return false;
}

//default constructor test
void constrTest(){
    Stud s, s1;
    if(tikrinimas(s, s1)){cout << std::left << std::setw(31) << "Default konstruktorius" << "| +\n";}
    else cout << std::left << std::setw(31) << "Default konstruktorius"<<"| -\n";
}

//copy constructor test
void copyConstrTest(){
    Stud s("Astrida", "Jablonskytė", 10, {7, 7, 7});
    Stud s1(s); //copy
    if(tikrinimas(s1, s)){
        s.setVardas("Amelija"); //testuojama ar kopijos reiksme nepasikeite pakeitus orginala
        if(!tikrinimas(s1, s)){cout << std::left << std::setw(31)<< "Copy konstruktorius"<<"| +\n";}} 
    else cout<< std::left << std::setw(31) << "Copy konstruktorius" <<"| -\n";
}

//copy assignment test
void copyAssignTest(){
    Stud s1("Monika", "Moceviciute", 9, {8, 8, 8}), s("Astrida", "Jablonskytė", 10, {7, 7, 7});
    s1 = s; //iskvieciamas copy assignment konstruktorius
    if(tikrinimas(s1, s)){
        s.setVardas("Amelija"); //testuojama ar kopijos reiksme nepasikeite pakeitus orginala
        if(!tikrinimas(s1, s)){cout << "Copy assignment operatorius    | +\n";}} 
    else cout << "Copy assignment operatorius | -\n";
}

//move konstruktoriaus test
void moveConstTest(){
    Stud s("Astrida", "Jablonskyte", 10, {7, 7, 7});
    Stud s1(std::move(s));
    s.~Stud();
    if(s1.getVardas() == "Astrida" && s1.getPavarde() == "Jablonskyte" && s1.getEgzaminas() == 10 && s1.getND() == vector<int>{7,7,7}){
        if(s.getVardas().empty() && s.getPavarde().empty() && s.getND().empty() && s.getEgzaminas() ==0 ){ 
            cout << std::left << std::setw(31) << "Move konstruktorius"<<"| +\n";}
        else cout << std::left << std::setw(31)<< "Move konstruktorius"<<"| -\n";
    }else cout << std::left << std::setw(31)<< "Move konstruktorius"<<"| -\n";
}

//move assignment test
void moveAssignTest(){
    Stud s1("Monika", "Moceviciute", 9, {8, 8, 8}), s("Astrida", "Jablonskyte", 10, {7, 7, 7});
    s1 = std::move(s);
    s.~Stud();
    if(s1.getVardas() == "Astrida" && s1.getPavarde() == "Jablonskyte" && s1.getEgzaminas() == 10 && s1.getND() == vector<int>{7,7,7}){
        if(s.getVardas().empty() && s.getPavarde().empty() && s.getND().empty() && s.getEgzaminas() == 0){
           cout << "Move assignment operatorius    | +\n";}
           else cout << "Move assignment operatorius    | -\n";
    }else cout << "Move assignment operatorius    | -\n";
}

//outputo operatorius
std::ostream& operator<<(std::ostream &output, const Stud& studentas){
    output << std::setw(15) << std::left << studentas.pavarde 
    << std::setw(15) << std::left << studentas.vardas 
    << std::setw(15) << std::fixed << std::setprecision(2) << studentas.galutinis() << endl;
    return output;
}

//inputo operatorius 
  std::istream& operator>>(std::istream &input, Stud& studentas){ //naudoti ifstreama
    int paz;
    input >> studentas.vardas >> studentas.pavarde;
    while(input >> paz){
        studentas.nd.push_back(paz);}

    studentas.egzaminas = studentas.nd.back();
    studentas.nd.pop_back();
    studentas.galutinis();
    return input;
}

//inputo testas
void inputTest(){
    Stud stud;
    vector<int> nd{7,8,9};
    std::istringstream ss("Astrida Jablonskyte 7 8 9 10");
    ss>>stud;
    if(stud.getVardas() == "Astrida" && stud.getPavarde() == "Jablonskyte" && stud.getND() == nd && stud.getEgzaminas() == 10)
    {cout << std::left << std::setw(31) << "Ivesties operatorius" << "| +\n"; }
    else cout << std::left << std::setw(31) << "Ivesties operatorius" << "| -\n";
}

//outputo testas
void outputTest(){
    Stud studentas("Astrida", "Jablonskyte", 10, {10, 10, 10});
    std::stringstream outputTestas, output;
    outputTestas<<std::setw(15)<<std::left<<"Jablonskyte"<<std::setw(15)<<std::left<<"Astrida"<<std::setw(15)<<std::fixed<<std::setprecision(2)<<10.00<<endl;
    output<<studentas;
    if(outputTestas.str() == output.str()){cout << std::left << std::setw(31) << "Isvesties operatorius" << "| +\n";}
    else cout << std::left << std::setw(31) << "Isvesties operatorius" << "| -\n";
}

//destruktoriaus testas
void destructorTest(){
    Stud* studentas = new Stud();
    for(int i = 2; i < 7; i++){studentas->setND(i);}
    studentas->~Stud();
    if (studentas->getND().empty()){cout << std::left << std::setw(31) << "Destruktorius" << "| +\n";}
    else cout << std::left << std::setw(31) << "Destruktorius" << "| -\n";
    operator delete(studentas); 
}

void konstruktoriuTest(){
    cout << "...\n";
    constrTest();
    copyConstrTest();
    copyAssignTest();
    moveConstTest();
    moveAssignTest();
    inputTest();
    outputTest();
    destructorTest();
}

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

/*double galutinis(Stud studentas, int PagalSkaiciavimas)
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
}*/

void pazymiu_ivedimas(Stud &studentas, string& ss){
    studentas.removeND();
    bool stop1 = false;
    cout << "Iveskite studento pazymius (-i), baige iveskite 0" << endl;
    do
    {
        while (true)
        {
            try
            {
                int paz;
                cin>>paz;
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
                if (paz == 0)
                {
                    stop1 = true;
                }
                else
                    ss += std::to_string(paz) + " ";
                break;
            }
            catch (const char *masyvas)
            {
                cout << masyvas << endl;
            }
        }

    } while (!stop1);
}

void paz_gener(Stud &studentas, string& ss)
{
    int A = rand() % 10 + 2;
    for (int i = 0; i < A; i++)
    {
        int P = rand() % 10 + 1;
        ss += std::to_string(P) + " ";
    }
    cout << endl;
}

Stud vardai(Stud &studentas, string& ss)
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
        ss += Vmasyvas[C] + " " + Pmasyvas[W] + " ";
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
        ss += Vmasyvas[C] + " " + Pmasyvas[W] + " ";
        return studentas;
    }
}

void duomenu_ivedimas(vector<Stud> &studentai, int meniu)
{

    string fullLine;
    int egzaminas;
    bool stop;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string vardas, pavarde;
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
                    getline(cin, vardas);
                    if (tinkamas_char(vardas) == false)
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
            if (vardas == "stop"){
                stop = true;
                break;
            }
            cout << "Iveskite studento pavarde" << endl;
            while (true)
            {
                try
                {
                    getline(cin, pavarde);
                    if (tinkamas_char(pavarde) == false)
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
                    cin>>egzaminas;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw "Iveskite skaiciu";
                    }
                    if (tinkamas_int(egzaminas) == false)
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

            fullLine = vardas + " " + pavarde + " "; 
        }
        if (meniu == 1)
        {
            pazymiu_ivedimas(studentas, fullLine);
        }
        else if (meniu == 2)
        {
            paz_gener(studentas, fullLine);
        }

        fullLine += std::to_string(egzaminas) + " ";
        
        std::istringstream ss(fullLine);
        ss>>studentas; 
        studentai.push_back(studentas); 
        cout << "..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!stop);
}

void duomenu_generavimas(vector<Stud> &studentai)
{
    int Q = rand() % 10 + 1;
    for (int i = 0; i < Q; i++)
    {string fullLine;
        Stud studentas;
        vardai(studentas, fullLine);
        paz_gener(studentas, fullLine);
        fullLine += std::to_string(rand() % 10 + 1);
        std::istringstream ss(fullLine);
        cout << fullLine;
        ss>>studentas;
        studentai.push_back(studentas);
    }
}

string filePasirinkimas()
{
    system("for /r %A in (*.txt) do @echo %~nxA >> temp.txt");
    ifstream f;
    string eilute;
    int pasirinkimuSUM = 0;
    int pasirinkimas;
    vector<string> txtfiles;
    vector<string> nenorimiFiles = {"isvedimas.txt", "vardai_moteru.txt", "vardai_vyru.txt", "temp.txt", "Pirmunai1000.txt", "Pirmunai10000.txt", "Pirmunai100000.txt", "Pirmunai1000000.txt", "Pirmunai10000000.txt", "Nesimokantys1000.txt", "Nesimokantys10000.txt", "Nesimokantys100000.txt", "Nesimokantys1000000.txt", "Nesimokantys10000000.txt"};

    f.open("temp.txt");

    while (getline(f, eilute))
    {

        eilute.pop_back();
        if (std::find(nenorimiFiles.begin(), nenorimiFiles.end(), eilute) == nenorimiFiles.end())
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

bool PalygintiVardas(const Stud &stud1, const Stud &stud2)
{
    return stud1.getVardas() < stud2.getVardas();
}

bool PalygintiPavardes(const Stud &stud1, const Stud &stud2)
{
    return stud1.getPavarde() < stud2.getPavarde();
}

bool PalygintiKategorijas(const Stud &stud1, const Stud &stud2){
    return stud1.galutinisBalas() > stud2.galutinisBalas();
}

void printCases(vector<Stud> visi, bool outputFILE, int RusiavimasPagal)
{
    int SkaiciuotiPagal;
    cout << "Galutinis balas skaiciuojamas pagal:" << endl;
    cout << "1 - mediana\n";
    cout << "2 - vidurki\n";
    cin >> SkaiciuotiPagal;
    std::ostream *out;
    std::ofstream f;
    f.open("isvedimas.txt");

    if (outputFILE){
        out = &f;}
    else{
        out = &cout;}

    if (RusiavimasPagal == 1){
        sort(visi.begin(), visi.end(), PalygintiVardas);
    }
    else if (RusiavimasPagal == 2){
        sort(visi.begin(), visi.end(), PalygintiPavardes);
    }
    // pagal mediana
    if (SkaiciuotiPagal == 1)
    {
        if (RusiavimasPagal == 3)
        {
            sort(visi.begin(), visi.end(), PalygintiKategorijas);
        }
        *out << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Med.)\n";
        *out << "----------------------------------------------------" << endl;
        for (Stud& j : visi)
        {
            //cout<<studentas; => NEVEIKIA GALUTINIO BALO SKAICIAVIMAS
            //*out << std::setw(15) << std::left << j.getPavarde() << std::setw(15) << std::left << j.getVardas() << std::setw(15) << std::fixed << std::setprecision(2) << j.galutinis() << endl;
            *out<<j;
        }
    }
    // skaiciuojam rn pagal vidurki
    else
    {
        if (RusiavimasPagal == 3)
        {
            sort(visi.begin(), visi.end(), PalygintiKategorijas);
        }
        *out << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)\n";
        *out << "----------------------------------------------------" << endl;
        for (Stud& j : visi)
        {
            *out << j;
            //*out << std::setw(15) << std::left << j.getPavarde() << std::setw(15) << std::left << j.getVardas() << std::setw(15) << std::fixed << std::setprecision(2) << j.galutinis() << endl;
        }
    }
}

void print(vector<Stud> visi, bool outputFILE, int RusiavimasPagal){
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
        else if (RusiavimasPagal == 3)
        {
            sort(visi.begin(), visi.end(), PalygintiKategorijas);
        }
        *out << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Med.)\n";
        *out << "----------------------------------------------------" << endl;
        for (Stud& j : visi)
        {*out << j;}
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
    int pazSk = dist(mt);
    auto start = std::chrono::high_resolution_clock::now();
    BufferisTest << std::setw(16) << std::left << "Vardas" << std::setw(16) << std::left << "Pavarde" << std::setw(16) << std::left;
    for (int j = 0; j <= pazSk; j++)
    {
        if (j != pazSk)
        {
            BufferisTest << "ND" + std::to_string(j + 1) << std::setw(16) << std::left;
        }
        else
            BufferisTest << "EG rez." << endl;
    }
    for (int i = 1; i <= StudSkaicius; i++)
    {
        BufferisTest << std::setw(16) << std::left << "Vardas" + std::to_string(i) << std::setw(16) << std::left << "Pavarde" + std::to_string(i) << std::setw(16) << std::left;
        for (int j = 0; j <= pazSk; j++)
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

