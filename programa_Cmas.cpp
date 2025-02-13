#include "programa_Cmas.h"

int main()
{
    srand(time(NULL));
    cout << "Pasirinkite: 1 - duomenys įvedinėjami ranka, 2 - pažymiai generuojami, 3 - generuojami visi studentų duomenys, 4 - baigti" << endl;
    cin >> meniu;

    if (meniu == 1)
    {
        do
        {
            Stud stud;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Įveskite studento vardą, baigę įveskite 'stop'" << endl;
            getline(cin, stud.vardas);

            while (tinkamas(stud.vardas) == false)
            {
                cout << "Įveskite tinkamą vardą" << endl;
                getline(cin, stud.vardas);
            }
            if (stud.vardas == "stop")
            {
                stop == true;
                break;
            }

            cout << "Įveskite studento pavardę" << endl;
            getline(cin, stud.pavarde);

            while (tinkamas(stud.pavarde) == false)
            {
                cout << "Įveskite tinkamą pavardę" << endl;
                getline(cin, stud.pavarde);
            }


            stud.EGrez = rand() % 10 + 1;
            NDpazymiai(stud);
            cout << "..." << endl;
            VISIstud.push_back(stud);
        } while (stop != true);
    }
    else if (meniu == 2)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do
        {
            Stud stud;
            cout << "Įveskite studento vardą, baigę įveskite 'stop'" << endl;
            getline(cin, stud.vardas);

            while (tinkamas(stud.vardas) == false)
            {
                cout << "Įveskite tinkamą vardą" << endl;
                getline(cin, stud.vardas);
            }
            if (stud.vardas == "stop")
            {
                stop2 == true;
                break;
            }

            cout << "Įveskite studento pavardę" << endl;
            getline(cin, stud.pavarde);

            while (tinkamas(stud.pavarde) == false)
            {
                cout << "Įveskite tinkamą pavardę" << endl;
                getline(cin, stud.pavarde);
            }
            int A = rand() % 10 + 2;
            for (int i = 0; i < A; i++)
            {
                ND1(stud);
            }

            stud.EGrez = rand() % 10 + 1;
            VISIstud.push_back(stud);
            cout << "..." << endl;
        } while (stop2 != true);
    }

    else if (meniu == 3)
    {
        int K = rand() % 10 + 2;
        for (int j = 0; j < K; j++)
        {

            Stud stud;

            mot(stud);

            int A = rand() % 10 + 2;
            for (int i = 0; i < A; i++)
            {
                ND1(stud);
            }
            stud.EGrez = rand() % 10 + 1;
            VISIstud.push_back(stud);
        }
    }
    if (meniu == 4)
    {
        return 0;
    }

    cout << setw(15) << left << "Pavardė" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis (Vid.) / Galutinis (Med.)\n";
    cout << "------------------------------------------------------------" << endl;

    for (Stud j : VISIstud)
    {
        cout << setw(15) << left << j.pavarde << setw(15) << left << j.vardas << setw(15) << fixed << setprecision(2) << galutinis(j) << endl;
    }
   

}