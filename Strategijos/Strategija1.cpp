
#include "strategija.h"


int main(){
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
