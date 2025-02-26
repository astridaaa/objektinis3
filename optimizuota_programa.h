#ifndef optimizuota_programa.h
#define optimizuota_programa.h

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

int meniu;
int paz;
struct Stud
{
    string vardas, pavarde;
    int egzaminas;
    vector<int> nd;
    double BalasGalutinisMed;
    double BalasGalutinisVid;
};
