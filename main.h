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


/*struct Stud
{
    string vardas, pavarde;
    int egzaminas;
    vector<int> nd;
    double BalasGalutinisVid;
};*/

class Stud{
    private:
        string vardas, pavarde;
        int egzaminas;
        vector<int> nd;
        double BalasGalutinisVid;
        bool balasSuskaiciuotas;
    public:
        Stud() : vardas(""), pavarde(""), egzaminas(0), nd{}, BalasGalutinisVid(0), balasSuskaiciuotas(false) {};
        ~Stud() {};

        void setVardas(const string& var){vardas=var;}
        void setPavarde(const string& pav){pavarde=pav;}
        void setEgzaminas(const int& egz){egzaminas=egz;}
        void setBalasGalutinisVid(const double& Balas){BalasGalutinisVid=Balas; balasSuskaiciuotas = true;}
        void setND(int paz){nd.push_back(paz);}
      
        string getVardas() const {return vardas;}
        string getPavarde() const {return pavarde;}
        int getEgzaminas() const {return egzaminas;}
        double galutinisBalas() const {return BalasGalutinisVid;}
        const std::vector<int>& getND() const {return nd;}
        const int& grazintiPaskutini() const {return nd.back();}
        void removeLast(){nd.pop_back();}
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

using konteinerisVector = std::vector<Stud>;
using konteinerisList = std::list<Stud>;
using konteinerisDeque = std::deque<Stud>;

#endif