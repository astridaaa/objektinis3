/*2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". 
Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. 
Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau,
 tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.*/

#include "strategija.h"


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
        konteinerisVector studentai, nesimokantys;
        vykdomaPrograma2(rusiavimasPagal, studentai, nesimokantys);
    }
    else if (konteineriuTipas == 2) {
        konteinerisDeque studentai, nesimokantys;
        vykdomaPrograma2(rusiavimasPagal, studentai, nesimokantys);
    }
    else{
        konteinerisList studentai, nesimokantys;
        vykdomaPrograma2(rusiavimasPagal, studentai, nesimokantys);
    }
}