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
#include <chrono>
#include <list>


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
using std::srand;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::microseconds;
using std::list;
using std::next;
using std::is_same_v;
using std::find;
using std::find_if;
using std::search;
using std::copy;
using std::remove;
using std::remove_if;
using std::remove_copy;
using std::remove_copy_if;
using std::transform;
using std::partition;
using std::stable_partition;


struct studentas {
	string vard, pav;
	vector <int> paz;
	int egz;
	float vgrez;
	float mgrez;
	string vert;
};
struct studentas2 {
	string vard, pav;
	list <int> paz;
	int egz;
	float vgrez;
	float mgrez;
	string vert;
};

struct studentas3 {
	string vard, pav;
	vector <int> paz;
	int egz;
	float vgrez;
	float mgrez;
	string vert;
};

std::ostream& operator<<(std::ostream& os, const studentas3& s);

template<typename T>
double mediana2(T vekt)
{
    size_t size = vekt.size();

    if (size == 0)
    {
        return 0;  
    }
    else
    {
        if constexpr (is_same_v<T, vector<typename T::value_type>>) 
        {
            sort(vekt.begin(), vekt.end());
        } 
        else if constexpr (is_same_v<T, list<typename T::value_type>>) 
        {
            vekt.sort();
        }

        if (size % 2 == 0)
        {
            auto it = next(vekt.begin(), size / 2 - 1);
            return static_cast<double>(*it + *(++it)) / 2;
        }
        else
        {
            return *next(vekt.begin(), size / 2);
        }
    }
}



int nuskaitymas();
double mediana(vector<int> vekt);
float vidurkis(vector<int> vekt);
vector <int> random(int n);
bool pagalvarda(const studentas& a, const studentas& b);
bool pagalrez(const studentas& a, const studentas& b);
bool pagalrez2(const studentas2& a, const studentas2& b);
bool rezultatas(const studentas& a);
void generatorius(int x, string pavadinimas);
void skirstymas(string pavadinimas, string naujas1, string naujas2);
void skirstymas2(string pavadinimas, string naujas1, string naujas2);
void nskirstymas(string pavadinimas, string naujas1);
void nskirstymas2(string pavadinimas, string naujas1);
void nskirstymasv(string pavadinimas, string naujas1);
bool rezultatas3(const studentas3& a);
bool pagalrez3(const studentas3& a, const studentas3& b);