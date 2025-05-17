#include "functions.h"
int main()
{
    bool repeat=true;
    while(repeat){
    int meniu;
    int paz;
    string testavimui;
    vector<Stud> visi;
    srand(time(NULL));
    int rusiavimas;
    cout << "Pasirinkite:"<<endl;
    cout<<" 1 - duomenys ivedinejami ranka"<<endl;
    cout<<" 2 - pazymiai generuojami"<<endl;
    cout<<" 3 - generuojami visi studentu duomenys"<<endl;
    cout<<" 4 - duomenys nuskaitomi is failo"<<endl;
    cout<<" 5 - atlikti 1 tyrima/ generuoti files"<<endl;
    cout<<" 6 - atlikti 2 tyrima"<<endl;
    cout<<" 7 - std::vector ir class Vector push_back() lyginimas"<<endl;
    cout<<" 8 - pirmoji strategija"<<endl;
    cout<<" 9 - antroji strategija"<<endl;
    cout<<" 10 -trecioji strategija"<<endl;
    cout<<" 11 -baigti programa" << endl;
    while (true)
    {
        try
        {
            cin >> meniu;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Neteisingas pasirinkimas, iveskite skaiciu 1-7";
                break;
            }
            else if (meniu > 11 || meniu < 1)
            {
                throw "Neteisingas pasirinkimas, iveskite skaiciu 1-7";
                break;
            }

            break;
        }
        catch (const char *masyvas)
        {
            cout << masyvas << endl;
        }
    }

    switch (meniu)
    {
    case 1:
    {
        duomenu_ivedimas(visi, meniu);
        printCases(visi, false, 4);
        break;
    }

    case 2:
    {
        duomenu_ivedimas(visi, meniu);
        printCases(visi, false, 4);
        break;
    }

    case 3:
    {
        duomenu_generavimas(visi);
        printCases(visi, false, 4);
        break;
    }

    case 4:
    {
        double laik;
        int printinimas;
        fileskait(visi, false, testavimui, laik);
        cout << "Duomenis isvesti terminale - 1, duomenis isvesti faile - 2" << endl;
        while (true)
        {
            try
            {
                cin >> printinimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw "Neteisingas pasirinkimas, iveskite skaiciu 1 arba 2";
                }
                if (printinimas != 1 && printinimas != 2)
                {
                    throw "Neteisingas pasirinkimas, iveskite skaiciu 1 arba 2";
                }
                break;
            }
            catch (const char *masyvas)
            {
                cout << masyvas << endl;
            }
        }
        cout << "Duomenys rusiuojami pagal: 1 - vardus; 2 - pavardes; 3 - galutinius balus; 4 - duomenys nera rusiuojami " << endl;
        while (true)
        {
            try
            {
                cin >> rusiavimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw "Neteisingas pasirinkimas, iveskite skaiciu nuo 1 iki 4";
                }
                if (rusiavimas > 4 || rusiavimas < 1)
                {
                    throw "Neteisingas pasirinkimas, iveskite skaiciu nuo 1 iki 4";
                }
                break;
            }
            catch (const char *masyvas)
            {
                cout << masyvas << endl;
            }
        }
        if (printinimas == 1)
        {
            printCases(visi, false, rusiavimas);
        }
        else
            printCases(visi, true, rusiavimas);
        break;
    }
    case 5:
    {
        konteinerisVector pirmunai;
        konteinerisVector nesimokantys;
        konteinerisVector studentaiTest;
        tyrimai(1, pirmunai, nesimokantys, studentaiTest);
        break;
    }
    case 6:
    {
        int konteinerioTipas;
        cout << "Pasirinkite testuojamo konteinerio tipa:" << endl;
        cout << "1 | vector\n"
             << "2 | deque\n"
             << "3 | list\n";
        cin >> konteinerioTipas;
        if (konteinerioTipas == 1)
        {
            konteinerisVector pirmunai;
            konteinerisVector nesimokantys;
            konteinerisVector studentaiTest;
            tyrimai(2, pirmunai, nesimokantys, studentaiTest);
        }
        if (konteinerioTipas == 2)
        {
            konteinerisDeque pirmunai;
            konteinerisDeque nesimokantys;
            konteinerisDeque studentaiTest;
            tyrimai(2, pirmunai, nesimokantys, studentaiTest);
        }
        if (konteinerioTipas == 3)
        {
            konteinerisList pirmunai;
            konteinerisList nesimokantys;
            konteinerisList studentaiTest;
            tyrimai(2, pirmunai, nesimokantys, studentaiTest);
        }

        break;
}
    case 7:
    {
        pushbackTest();
        break;
    }
    case 8:{paleistiStrategija1();break;}
    
    case 9:{paleistiStrategija2();break;}
 
    case 10:{paleistiStrategija3();break;}

    case 11:{return 0;}
    }
    
}}