#include "optimizuota_programa.h" 
 int main(){
    srand(time(NULL));
    vector<Stud> visi;
    cout << "Pasirinkite: 1 - duomenys įvedinėjami ranka, 2 - pažymiai generuojami, 3 - generuojami visi studentų duomenys, 4 - duomenys nuskaitomi iš failo, 5 - baigti programą" << endl;
    cin >> meniu;
    switch (meniu)
    {
    case 1 :{
    duomenu_ivedimas(visi);
    print(visi);
    break;}

    case 2 : {
    duomenu_ivedimas(visi);
    print(visi);
    break;}

    case 3 : {
  
    duomenu_generavimas(visi);
    print(visi);
    
    break;}

    case 4:{  
        int printinimas;
        //nuskaito is kursioku failo, pirmas stulpas vardas, antras pavarde, visi kiti like i nd ir paskutinis i egza
        fileskait(visi);
        cout << "Duomenis išvesti terminale - 1, duomenis isvesti faile - 2" << endl;
        cin >> printinimas;
        if(printinimas == 1){
            print(visi);
        }
        else isvedimas(visi);
        break;
    }
    case 5:{
    return 0;  
    }
    }
}
 


