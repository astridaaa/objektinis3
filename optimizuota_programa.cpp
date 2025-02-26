#include "optimizuota_programa.h"

int main()
{
    srand(time(NULL));
    vector<Stud> visi;
    int rusiavimas;
    cout << "Pasirinkite: 1 - duomenys ivedinejami ranka, 2 - pazymiai generuojami, 3 - generuojami visi studentu duomenys, 4 - duomenys nuskaitomi is failo, 5 - testavimas, 6 - baigti programa" << endl;
    cin >> meniu;
    switch (meniu)
    {
    case 1:
    {
        duomenu_ivedimas(visi);
        print(visi, false, 4);
        break;
    }

    case 2:
    {
        duomenu_ivedimas(visi);
        print(visi, false, 4);
        break;
    }

    case 3:
    {   duomenu_generavimas(visi);
        print(visi, false, 4);
        break;}

    case 4:
    {   int printinimas;
        fileskait(visi, 0);
        cout << "Duomenis isvesti terminale - 1, duomenis isvesti faile - 2" << endl;
        cin >> printinimas;
        cout << "Duomenys rusiuojami pagal: 1 - vardus; 2 - pavardes; 3 - galutinius balus " << endl;
        cin >> rusiavimas;
        if (printinimas == 1)
        {
            print(visi, false, rusiavimas);
        }
        else
            print(visi, true, rusiavimas);
        break;
    }
    case 5:
    {   int testavimas;
        cout << "Testuoti su 1 - 10,000 studentu; 2 - 100,000 studentu; 3 - 1,000,000 studentu" << endl;
        cin >> testavimas;

        fileskait(visi, testavimas);
        print(visi, true, 4);
        break;

    }
    case 6:
    {
        return 0;
    }
    }
}
