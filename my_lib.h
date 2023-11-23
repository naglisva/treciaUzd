
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
using std::ostream_iterator;

struct studentas {
	string vard, pav;
	vector <int> paz;
	int egz;
	float vgrez;
	float mgrez;
	string vert;
};
/*
class Studentas {
    private:
    string vard_, pav_;
	vector <int> paz_;
	int egz_;
	float vgrez_;
	float mgrez_;
	string vert_;
    public:
    Studentas() : egz_(0) {}
    Studentas(std::istream& is);
    inline string vardas() const { return vard_; }
    inline string pavarde() const { return pav_; } 
    double galBalas(double (*) (vector<int>) = mediana2) const;
    std::istream& readStudent(std::istream&);
};
*/

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
class Studentas {
    private:
    string vard_, pav_;
	vector <int> paz_;
	int egz_;
	float vgrez_;
	float mgrez_;
	string vert_;
    public:
    Studentas() : egz_(0) {}
    Studentas(std::istream& is);
    inline string vardas() const { return vard_; }
    inline string pavarde() const { return pav_; } 
    inline vector <int> pazymiai() const {return paz_;}
    inline int egzaminas() const { return egz_;}
    inline void setVardas(const string& vardas) { vard_ = vardas; }
    inline void setPavarde(const string& pavarde) { pav_ = pavarde; }
    inline void setPazymiai(const vector<int>& pazymiai) { paz_ = pazymiai; }
    inline void setEgzaminas(int egzaminas) { egz_ = egzaminas; }
    double galBalas(double (*func)(std::vector<int>) = mediana2) const;
    std::istream& readStudent(std::istream&);
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

struct studentas4 {
	string vard, pav;
	list <int> paz;
	int egz;
	float vgrez;
	float mgrez;
	string vert;
};

std::ostream& operator<<(std::ostream& os, const studentas3& s);
std::ostream& operator<<(std::ostream& os, const studentas4& s);





int nuskaitymas();
double mediana(vector<int> vekt);
float vidurkis(vector<int> vekt);
vector <int> random(int n);
bool pagalvarda(const studentas& a, const studentas& b);
bool pagalrez(const studentas& a, const studentas& b);

bool PagalRez(const Studentas& a, const Studentas& b);

bool pagalrez2(const studentas2& a, const studentas2& b);
bool rezultatas(const studentas& a);
void generatorius(int x, string pavadinimas);
void vector1(string pavadinimas, string naujas1, string naujas2);
void list1(string pavadinimas, string naujas1, string naujas2);
void vector2(string pavadinimas, string naujas1);
void list2(string pavadinimas, string naujas1);
void vector3(string pavadinimas, string naujas1);
void list3(string pavadinimas, string naujas1, string naujas2);
bool rezultatas3(const studentas3& a);
bool pagalrez3(const studentas3& a, const studentas3& b);
bool rezultatas4(const studentas4& a);
bool pagalrez4(const studentas4& a, const studentas4& b);

bool PagalRez(const Studentas& a, const Studentas& b);
void vector1c(string pavadinimas, string naujas1, string naujas2);
void vector2c(string pavadinimas, string naujas1);