/*2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį:
 "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai
  konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau, 
  tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.*/

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

    if (konteineriuTipas == 1)
    {
        std::vector<Stud> studentai;
        std::vector<Stud> nesimokantys;
    }
    else if (konteineriuTipas == 2)
    {
        std::deque<Stud> studentai;
        std::deque<Stud> nesimokantys;
    }
    else if (konteineriuTipas == 3)
    {
        std::list<Stud> studentai;
        std::list<Stud> nesimokantys;
    }
    else
    {
        cout << "Pasirinkite teisinga konteinerio tipa!" << endl;
    }

    for(int a = 1000; a <= 10000000; a *= 10){
        double visasLaikas = 0.0;
        string testavimoFile = "Tyrimo_files\\Studentai" + std::to_string(a) + ".txt";
        cout << "...\n" << std::to_string(a) + ".txt" << endl;
        nuskaitymasFile(rusiavimasPagal,testavimoFile, visasLaikas, studentai);
        //studentuIsskirstymas(studentai, visasLaikas, pirmunai, nesimokantys);
        //studentuRusiavimas(rusiavimasPagal, pirmunai, nesimokantys, visasLaikas);
        
        //testavimasPrint(studentai, pirmunai, nesimokantys, a);
        cout << "Bendras programos vykdymo laikas: " << visasLaikas << "s" << endl;
    }
    
}