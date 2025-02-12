#include "programa.h"

main()
{
    srand(time(NULL));
    cout << "Pasirinkite: 1 - duomenys įvedinėjami ranka, 2 - pažymiai generuojami, 3 - generuojami visi studentų duomenys, 4 - baigti" << endl;
    cin >> meniu;

    for (int i = 0; i < rand() % 5 + 1; i++)
    {   
        Stud stud{};
        cout << "Įveskite studento vardą" << endl;
        getline(cin, stud.vardas);

        while(tinkamas(stud.vardas) == false){
            cout << "Įveskite tinkamą vardą" << endl;
            getline(cin, stud.vardas);
            
        }
    
        cout << "Įveskite studento pavardę" << endl;
        getline(cin, stud.pavarde);

        while(tinkamas(stud.pavarde) == false){
            cout << "Įveskite tinkamą pavardę" << endl;
            getline(cin, stud.pavarde);
        }

        int a = (rand() % 4 + 2);
        cout << "Įveskite " << a << " studento pažymius (-į)" << endl;
        for (int i = 0; i < a; i++)
        {
            cin >> paz;
            while (paz > 10 || paz < 1)                 
            {
                cout << "Įveskite rezultatą skalėje 1-10" << endl;
                cin >> paz;
            }
            stud.NDrez.push_back(paz);
        }

        cout << "Įveskite studento egzamino pažymį" << endl;
        cin >> stud.EGrez;
        while (stud.EGrez > 10 || stud.EGrez < 1)
        {
            cout << "Įveskite rezultatą skalėje 1-10" << endl;
            cin >> stud.EGrez;
        }
        cout << "..." << endl;

        VISIstud.push_back(stud);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    if (meniu == 4)
    {
        return EXIT_SUCCESS;
    }

    cout << setw(15) << left << "Pavardė" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis (Vid.) / Galutinis (Med.)\n";
    cout << "------------------------------------------------------------" << endl;

    for (Stud j : VISIstud)
    {
        cout << setw(15) << left << j.pavarde << setw(15) << left << j.vardas << setw(15) << fixed << setprecision(2) << galutinis(j) << endl;
    }
}