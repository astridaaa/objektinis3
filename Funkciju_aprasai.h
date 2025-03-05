#include "optimizuota_programa.h"

bool tinkamas_char(string vardas);

bool tinkamas_int(int skaicius);

double galutinis(Stud studentas, int PagalSkaiciavimas);

void pazymiu_ivedimas(Stud &studentas);

void paz_gener(Stud &studentas);

Stud vardai(Stud &studentas);

void duomenu_ivedimas(vector<Stud> &studentai, int meniu);

void duomenu_generavimas(vector<Stud> &studentai);

void fileskait(vector<Stud> &studentai, bool a, string filePav, double &BendrasLaikas);

bool PalygintiVardas(Stud &stud1, Stud &stud2);

bool PalygintiPavardes(Stud &stud1, Stud &stud2);

bool PalygintiBalaMed(Stud &stud1, Stud &stud2);

bool PalygintiBalaVid(Stud &stud1, Stud &stud2);

bool PalygintiKategorijas(Stud &stud1, Stud &stud2)

void print(vector<Stud> visi, bool outputFILE, int RusiavimasPagal);

string filePasirinkimas();

double GeneruotiFiles(int StudSkaicius); 

void tyrimai(int pasirinkimasTyrimo);

void PrintVektorius(vector<Stud> nesimokantys, vector<Stud> pirmunai, int a, int RusiavimasPagal, double &BendrasLaikas);

void vectorIdejimas(int studSkaicius, vector<Stud> &pirmunai, vector<Stud> &nesimokantys, double &BendrasLaikas);