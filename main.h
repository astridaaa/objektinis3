#ifndef main_h
#define main_h

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <cpuid.h>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <filesystem>
#include <random>
#include <filesystem>
#include <deque>
#include <list>
#include <execution>
#include <thread>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::isalpha;
using std::isdigit;
using std::isspace;
using std::numeric_limits;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::deque;
using std::list;

class Stud{
    private:
        string vardas, pavarde;
        int egzaminas;
        vector<int> nd;
        double BalasGalutinisVid;
        bool balasSuskaiciuotas;
    public:
        Stud() : vardas(""), pavarde(""), egzaminas(0), nd{}, BalasGalutinisVid(0), balasSuskaiciuotas(false) {}; //konstruktorius
        ~Stud() {nd.clear();}   //destruktorius

        Stud(const Stud& studCopy/*other*/); //copy konstruktorius
        Stud& operator=(const Stud& studCopy); //copy assignment

        Stud(Stud&& studMove); //move konstruktorius
        Stud& operator=(Stud&& studMove); //move assignment 

        //setteriai
        void setVardas(const string& var){vardas=var;}
        void setPavarde(const string& pav){pavarde=pav;}
        void setEgzaminas(const int& egz){egzaminas=egz;}
        void setBalasGalutinisVid(const double& Balas){BalasGalutinisVid=Balas; balasSuskaiciuotas = true;}
        void setND(int paz){nd.push_back(paz);}
      
        //getteriai
        string getVardas() const {return vardas;}
        string getPavarde() const {return pavarde;}
        int getEgzaminas() const {return egzaminas;}
        int getPaz(int i) const {return nd[i];} 
        double galutinisBalas() const {return BalasGalutinisVid;}
        const std::vector<int>& getND() const {return nd;}
        int pazKiekis() const {return nd.size();}
        const int& grazintiPaskutini() const {return nd.back();}
        void removeLast(){nd.pop_back();}
        void removeND(){nd.clear();};
        //galutinio balo skaiciavimo metodas
        double galutinis() {
            if(!balasSuskaiciuotas){
                double suma = 0;
                double vidurkis;
                if (nd.size() == 1) {
                    vidurkis = nd[0];} 
                    else {
                    for (size_t ss = 0; ss < nd.size(); ss++) {
                        suma += nd[ss];}
                    vidurkis = suma / nd.size();}
                BalasGalutinisVid = round((0.4 * vidurkis + 0.6 * egzaminas) * 100) / 100;
                balasSuskaiciuotas = true; 
            }
            return BalasGalutinisVid;
        }
};

//realizuotas copy konstruktorius
Stud::Stud(const Stud& studCopy) :
    vardas(studCopy.vardas),
    pavarde(studCopy.pavarde),
    egzaminas(studCopy.egzaminas),
    nd(studCopy.nd),
    BalasGalutinisVid(studCopy.BalasGalutinisVid),
    balasSuskaiciuotas(studCopy.balasSuskaiciuotas), {}

//realizuotas copy assignment konstrukorius
Stud& Stud operator=(const Stud& studCopy){ 
    if(this != &studCopy){ //patikrint kad nereiktu be reikalo perrasinet
        vardas = studCopy.vardas;
        pavarde = studCopy.pavarde;
        nd = studCopy.nd;
        egzaminas = studCopy.egzaminas;
        BalasGalutinisVid = studCopy.BalasGalutinisVid;
        balasSuskaiciuotas = studCopy.balasSuskaiciuotas;}
    return *this;//this is a pointer that always points to the current object — the one whose method is being called.
}

//realizuotas move konstruktorius
Stud::Stud(Stud&& studMove) :
    vardas(std::move(studMove.vardas)),
    pavarde(std::move(studMove.pavarde)),
    nd(std::move(studMove.nd)),
    egzaminas(std::move(studMove.egzaminas)),
    BalasGalutinisVid(std::move(studMove.BalasGalutinisVid)),
    balasSuskaiciuotas(std::move(studMove.balasSuskaiciuotas)), {}

//realizuotas move assignment konstruktorius
Stud::Stud& operator=(Stud&& studMove){
    if (this != &studMove) {
        vardas = std::move(studMove.vardas);
        pavarde = std::move(studMove.pavarde);
        nd = std::move(studMove.nd);
        egzaminas = std::move(studMove.egzaminas);
        BalasGalutinisVid = std::move(studMove.BalasGalutinisVid);
        balasSuskaiciuotas = std::move(studMove.balasSuskaiciuotas);
} return *this;}

using konteinerisVector = std::vector<Stud>;
using konteinerisList = std::list<Stud>;
using konteinerisDeque = std::deque<Stud>;

#endif


//copy
//su copy reikia sukurti studento copija ir patikrinti ar visi duomenys sutampa

//su copy assign reikia sukurti studenta3 ir jam pabandyti priskirti pati pirma studenta

//keiciam pradzinius studento duomenis ir ziuirm ar kopijoms all good (visi duomenys neturetu but pasikeite)


//move

//sukuriam studenta kuriam movinam kito pagr studento duomenis, patikrinam ar lygus (neturi but lygus)

//move asssign priskiriam 