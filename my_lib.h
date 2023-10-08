#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <valarray>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::size;
using std::exception;
using std::numeric_limits;
using std::streamsize;
using std::stringstream;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::srand;
using std::time;
using std::ofstream;
using std::rand;
using std::move;


struct studentas {
	string vard, pav;
	vector <int> paz;
	int egz;
	float vgrez;
	float mgrez;
	string vert;
};

int nuskaitymas();
double mediana(vector<int> vekt);
float vidurkis(vector<int> vekt);
vector <int> random(int n);
bool pagalvarda(const studentas& a, const studentas& b);
void generatorius(int x, string pavadinimas);
void skirstymas(string pavadinimas, string naujas1, string naujas2);