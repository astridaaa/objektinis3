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

class zmogus{
    protected:
        string vardas;
        string pavarde;
    public:
        zmogus() : vardas(""), pavarde("") {}
        zmogus(const string& var, const string& pav) : vardas(var), pavarde(pav) {}
        virtual ~zmogus() { vardas = ""; pavarde="";}

        virtual void setVardas(const string& var) = 0;
        virtual void setPavarde(const string& pav) = 0;

        string getVardas()const{return vardas;}
        string getPavarde()const{return pavarde;}

        //Move constructor
        zmogus(zmogus&& z): vardas(std::move(z.vardas)), pavarde(std::move(z.pavarde)) {}

        //Move assignment operator
        zmogus& operator=(zmogus&& z) {
        if (this != &z) {
            vardas = std::move(z.vardas);
            pavarde = std::move(z.pavarde);}
        return *this;}
};


class Stud : public zmogus{
    private:
        //string vardas, pavarde;
        int egzaminas;
        vector<int> nd;
        mutable double BalasGalutinisVid;
        mutable bool balasSuskaiciuotas;
    public:
        Stud() : zmogus("", ""), egzaminas(0), nd{}, BalasGalutinisVid(0), balasSuskaiciuotas(false) {}; //konstruktorius defaultinis
        Stud(const string& vrd, const string& pvrd, int egzam, const vector<int>& namud): zmogus(vrd, pvrd), 
        egzaminas(egzam), nd(namud), BalasGalutinisVid(0), balasSuskaiciuotas(false) {}
    
        /*Stud(const Stud& studCopy); //copy konstruktorius
        Stud& operator=(const Stud& studCopy); //copy assignment
        Stud(Stud&& studMove); //move konstruktorius
        Stud& operator=(Stud&& studMove); //move assignment */

        /**copy konstruktorius*/
        Stud(const Stud& studCopy) :
        zmogus(studCopy.getVardas(), studCopy.getPavarde()),
        egzaminas(studCopy.egzaminas),
        nd(studCopy.nd),
        BalasGalutinisVid(studCopy.BalasGalutinisVid),
        balasSuskaiciuotas(studCopy.balasSuskaiciuotas) {}



        /**copy assignment operatorius*/
        Stud& operator=(const Stud& studCopy){ 
            if(this != &studCopy){ 
                setVardas(studCopy.getVardas());
                setPavarde(studCopy.getPavarde());
                nd = studCopy.nd;
                egzaminas = studCopy.egzaminas;
                BalasGalutinisVid = studCopy.BalasGalutinisVid;
                balasSuskaiciuotas = studCopy.balasSuskaiciuotas;}
            return *this;
        }

        /**move konstruktorius*/
        Stud(Stud&& studMove) :    
        zmogus(std::move(studMove)),
        nd(std::move(studMove.nd)),
        egzaminas(std::move(studMove.egzaminas)),
        BalasGalutinisVid(std::move(studMove.BalasGalutinisVid)),
        balasSuskaiciuotas(std::move(studMove.balasSuskaiciuotas)){studMove.clear();}

        /**move assignment operatorius*/
        Stud operator=(Stud &&studMove)
        {
            if (this != &studMove)
            {
                zmogus::operator=(std::move(studMove));
                nd = std::move(studMove.nd);
                egzaminas = std::move(studMove.egzaminas);
                BalasGalutinisVid = std::move(studMove.BalasGalutinisVid);
                balasSuskaiciuotas = std::move(studMove.balasSuskaiciuotas);
                studMove.clear();
            }
            return *this;
        }

        
        void clear(){nd.clear(); egzaminas=0; BalasGalutinisVid=0;balasSuskaiciuotas=false;}   
        ~Stud()override{clear();} //destruktorius
        
        //setteriai
        void setVardas(const string& var)override{vardas=var;}
        void setPavarde(const string& pav)override{pavarde=pav;}
        void setEgzaminas(const int& egz){egzaminas=egz;}
        void setBalasGalutinisVid(const double& Balas){BalasGalutinisVid=Balas; balasSuskaiciuotas = true;}
        void setND(int paz){nd.push_back(paz);}
      
        //getteriai
        int getEgzaminas() const {return egzaminas;}
        int getPaz(int i) const {return nd[i];} 
        const vector<int>& getND() const {return nd;}
        double galutinisBalas() const {return BalasGalutinisVid;}
        int pazKiekis() const {return nd.size();}
        const int& grazintiPaskutini() const {return nd.back();}
        void removeLast(){nd.pop_back();}
        void removeND(){nd.clear();};
        
        /**galutinio balo skaiciavimo metodas*/
        double galutinis() const{
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
        //lygybes operatorius testavimui
        bool operator==(const Stud &s) const{
            if(getVardas()==s.getVardas() && getPavarde()==s.getPavarde() && getEgzaminas()==s.getEgzaminas()
            && getND()== s.getND()){return true;}
        else return false;
        }
        //nelygybes operatorius testavimui
        bool operator!=(const Stud &s)const{
            if(getVardas()!= s.getVardas() || getPavarde()!=s.getPavarde() || getEgzaminas()!= s.getEgzaminas()
            || getND()!=s.getND()){return true;}
        else return false;
        }
        
        friend std::ostream& operator<<(std::ostream &output, const Stud& studentas);
        friend std::istream& operator>>(std::istream &input, Stud& studentas);
    };
                
using konteinerisVector = std::vector<Stud>;
using konteinerisList = std::list<Stud>;
using konteinerisDeque = std::deque<Stud>;

#endif
