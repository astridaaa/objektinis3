/*Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". 
Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). Nesunku pastebėti, 
kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip 
programos veikimo sparta priklauso nuo konteinerio tipo?*/

#include "strategija.h"
#include "../functions.h"


int main(){
    int konteineriuTipas;
    int rusiavimasPagal;
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

    if (konteineriuTipas == 1) {
        vector<Stud> studentai;
        vector<Stud> pirmunai;
        vector<Stud> nesimokantys;
        vykdomaPrograma(rusiavimasPagal, studentai, pirmunai, nesimokantys);
    }
    else if (konteineriuTipas == 2) {
        deque<Stud> studentai;
        deque<Stud> pirmunai;
        deque<Stud> nesimokantys;
        vykdomaPrograma(rusiavimasPagal, studentai, pirmunai, nesimokantys);
    }
    else{
        list<Stud> studentai;
        list<Stud> pirmunai;
        list<Stud> nesimokantys;
        vykdomaPrograma(rusiavimasPagal, studentai, pirmunai, nesimokantys);
    }

    /*if (konteineriuTipas == 1)
    {
    std::vector<Stud> studentai;
    std::vector<Stud> pirmunai;
    std::vector<Stud> nesimokantys;
    for(int a = 1000; a <= 10000000; a *= 10){
        double visasLaikas = 0.0;
        string testavimoFile = "Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
        cout << "...\n" << std::to_string(a) + ".txt" << endl;
        nuskaitymasFile(rusiavimasPagal,testavimoFile, visasLaikas, studentai);
        studentuIsskirstymas(studentai, visasLaikas, pirmunai, nesimokantys);
        studentuRusiavimas(rusiavimasPagal, pirmunai, nesimokantys, visasLaikas);
        //testavimasPrint(studentai, pirmunai, nesimokantys, a);
        cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
    }  
    }
    else if (konteineriuTipas == 2)
    {
    std::deque<Stud> studentai;
    std::deque<Stud> pirmunai;
    std::deque<Stud> nesimokantys;
    for(int a = 1000; a <= 10000000; a *= 10){
        double visasLaikas = 0.0;
        string testavimoFile = "Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
        cout << "...\n" << std::to_string(a) + ".txt" << endl;
        nuskaitymasFile(rusiavimasPagal,testavimoFile, visasLaikas, studentai);
        studentuIsskirstymas(studentai, visasLaikas, pirmunai, nesimokantys);
        studentuRusiavimas(rusiavimasPagal, pirmunai, nesimokantys, visasLaikas);
        //testavimasPrint(studentai, pirmunai, nesimokantys, a);
        cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
    }
    }
    else if( konteineriuTipas == 3){
        std::list<Stud> studentai;
        std::list<Stud> pirmunai;
        std::list<Stud> nesimokantys; 
        for(int a = 1000; a <= 10000000; a *= 10){
            double visasLaikas = 0.0;
            string testavimoFile = "Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
            cout << "...\n" << std::to_string(a) + ".txt" << endl;
            nuskaitymasFile(rusiavimasPagal,testavimoFile, visasLaikas, studentai);
            studentuIsskirstymas(studentai, visasLaikas, pirmunai, nesimokantys);
            studentuRusiavimas(rusiavimasPagal, pirmunai, nesimokantys, visasLaikas);
            //testavimasPrint(studentai, pirmunai, nesimokantys, a);
            cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
        } 
    }
    */

    /*for(int a = 1000; a <= 10000000; a *= 10){
        double visasLaikas = 0.0;
        string testavimoFile = "Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
        cout << "...\n" << std::to_string(a) + ".txt" << endl;
        nuskaitymasFile(rusiavimasPagal,testavimoFile, visasLaikas, studentai);
        studentuIsskirstymas(studentai, visasLaikas, pirmunai, nesimokantys);
        studentuRusiavimas(rusiavimasPagal, pirmunai, nesimokantys, visasLaikas);
        //testavimasPrint(studentai, pirmunai, nesimokantys, a);
        cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
    }*/
}