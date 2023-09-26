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

struct studentas {
	string vard, pav;
	vector <int> paz;
	int egz;
	float vgrez;
	float mgrez;
};

void stud();
double mediana(vector<int> vekt);
float vidurkis(vector<int> vekt);
vector <int> random(int n);