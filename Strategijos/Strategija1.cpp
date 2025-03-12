//includas is funkciju main respiratory su ../#
//includas nauju funkciju, kurios su templates startegija.h
//mainas grn

//leidziant linkinti du files nes dabar visas 3 startegijas paleidziu

#include "strategija.h"
#include "../functions.h"
//Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". 
//Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). Nesunku pastebėti, 
//kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip 
//programos veikimo sparta priklauso nuo konteinerio tipo?
int main(){
    double visasLaikas = 0.0;
    int konteineriuTipas;
    int rusiavimasPagal;
    std::vector<Stud> studentai;
    std::vector<Stud> pirmunai;
    std::vector<Stud> nesimokantys;

    cout << "Programa testuojama su:" << endl;
    cout << "1 | vector tipo konteineriu" << endl;
    cout << "2 | deque tipo konteineriu" << endl;
    cout << "3 | list tipo konteineriu" << endl;
    cin >> konteineriuTipas;
    
    cout << "Studentus rusiuoti pagal:" << endl;
    cout << "1 | Vardus\n";
    cout << "2 | Pavardes\n";
    cout << "3 | Galutini bala\n";
    cout << "4 | Duomenu nerusiuoti\n";
    cin >> rusiavimasPagal;
    
    //string testavimoFile = "Tyrimo_files\\" + filePasirinkimas(); //ima is tyrimu aplankalo



    switch (konteineriuTipas)
    {
    case 1:
    {

        for(int a = 1000; a <= 10000000; a *= 10){
            string testavimoFile = "Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
            cout << "...\n" << std::to_string(a) + ".txt" << endl;
        
            
            /*std::vector<Stud> studentai;
            std::vector<Stud> pirmunai;
            std::vector<Stud> nesimokantys;*/
            nuskaitymasFile(rusiavimasPagal,testavimoFile, visasLaikas, studentai);
            studentuIsskirstymas(studentai, visasLaikas, pirmunai, nesimokantys);
            studentuRusiavimas(rusiavimasPagal, pirmunai, nesimokantys, visasLaikas);
            testavimasPrint(studentai, pirmunai, nesimokantys, a);
            cout << "Bendras programos vykdymo laikas" << visasLaikas << "s" << endl;
        }
        
        break;
    }
      
    case 2:
    {
      break;  
    }

    case 3: {

    }

    default:
        cout << "Pasirinkite testavimo konteineri!\n";
    }
    



    //nuskaitymas


   
    //sudedu i konteienri pagal template
    //padarau sorta
    //sudedu i kitus du konteinerius: pirmunus ir nesimokancius


    
    
}