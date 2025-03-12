#include "functions.h"
//reikes arba su templates arba padaryt tris naujus files ir tsg i folderius sudeti strategijas!!!!!
int main()
{

    int meniu;
    int paz;
    string testavimui;
    srand(time(NULL));
    vector<Stud> visi;
    int rusiavimas;
    cout << "Pasirinkite: 1 - duomenys ivedinejami ranka, 2 - pazymiai generuojami, 3 - generuojami visi studentu duomenys, 4 - duomenys nuskaitomi is failo, 5 - atlikti 1 tyrima/ generuoti files, 6 - atlikti 2 tyrima, 7 - baigti programa" << endl;
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
            else if (meniu > 7 || meniu < 1)
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
        print(visi, false, 4);
        break;
    }

    case 2:
    {
        duomenu_ivedimas(visi, meniu);
        print(visi, false, 4);
        break;
    }

    case 3:
    {
        duomenu_generavimas(visi);
        print(visi, false, 4);
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
            print(visi, false, rusiavimas);
        }
        else
            print(visi, true, rusiavimas);
        break;
    }
    case 5:
    {
        tyrimai(1);
        break;
    }
    case 6:
    {
        tyrimai(2);
        break;
    }
    case 7:
    {
        return 0;
    }
    }
}