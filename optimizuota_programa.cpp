#include "optimizuota_programa.h" 
//pirmas ranka ivedinejant veikia
//antras veikia
//trecias veikia
 int main(){
    srand(time(NULL));
    vector<Stud> visi;
    cout << "Pasirinkite: 1 - duomenys įvedinėjami ranka, 2 - pažymiai generuojami, 3 - generuojami visi studentų duomenys, 4 - duomenys nuskaitomi iš failo, 5 - baigti programą" << endl;
    cin >> meniu;
    switch (meniu)
    {
    case 1 :{
    duomenu_ivedimas(visi);
    print(visi, false, 4);
    break;}

    case 2 : {
    duomenu_ivedimas(visi);
    print(visi, false, 4);
    break;}

    case 3 : {
  
    duomenu_generavimas(visi);
    print(visi, false, 4);
    
    break;}

    case 4:{  
        int printinimas;
        int rusiavimas;
        //nuskaito is kursioku failo, pirmas stulpas vardas, antras pavarde, visi kiti like i nd ir paskutinis i egza
        fileskait(visi);
        cout << "Duomenis išvesti terminale - 1, duomenis isvesti faile - 2" << endl;
        cin >> printinimas;
        cout << "Duomenys rūšiuojami pagal: \n";
        cout << "1 - vardai abėcėlės tvarka\n";
        cout << "2 - pavardės abėcėlės tvarka\n";
        cout << "3 - galutiniai balai mažėjimo tvarka\n";
        cin >> rusiavimas;
        if(printinimas == 1){
            print(visi, false, rusiavimas);
        }
        else print(visi, true, rusiavimas);
        break;
    }
    case 5:{
    return 0;  
    }
    }
}




