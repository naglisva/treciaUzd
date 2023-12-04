
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
using std::find_if;
using std::move;


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
	string vert_;
    public:
    Studentas() : egz_(0) {}
    Studentas(std::istream& is);
    Studentas(const Studentas& that) : vard_(that.vard_), pav_(that.pav_), paz_(that.paz_), egz_(that.egz_), vert_(that.vert_) {}
    Studentas& operator=(const Studentas& that){
        vard_ = that.vard_;
        pav_ = that.pav_;
        paz_ = that.paz_;
        egz_ = that.egz_;
        vert_ = that.vert_;
        return *this;
    }
    ~Studentas(){
        paz_.clear();
    }

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

class Studentas2 {
    private:
    string vard_, pav_;
	vector <int> paz_;
	int egz_;
	string vert_;
    public:
    Studentas2() : egz_(0) {}
    Studentas2(std::istream& is);
    Studentas2(const Studentas2& that) : vard_(that.vard_), pav_(that.pav_), paz_(that.paz_), egz_(that.egz_), vert_(that.vert_) {}
    Studentas2& operator=(const Studentas2& that){
        vard_ = that.vard_;
        pav_ = that.pav_;
        paz_ = that.paz_;
        egz_ = that.egz_;
        vert_ = that.vert_;
        return *this;
    }
    ~Studentas2(){
        paz_.clear();
    }

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
    friend std::istream& operator>>(std::istream&, Studentas2&);
};

std::ostream& operator<<(std::ostream& os, const Studentas2& s);
std::istream& operator>>(std::istream&, Studentas2&);

class Studentas3 {
    private:
    string vard_, pav_;
	list <int> paz_;
	int egz_;
	string vert_;
    public:
    Studentas3() : egz_(0) {}
    Studentas3(std::istream& is);
    Studentas3(const Studentas3& that) : vard_(that.vard_), pav_(that.pav_), paz_(that.paz_), egz_(that.egz_), vert_(that.vert_) {}
    Studentas3& operator=(const Studentas3& that){
        vard_ = that.vard_;
        pav_ = that.pav_;
        paz_ = that.paz_;
        egz_ = that.egz_;
        vert_ = that.vert_;
        return *this;
    }
    ~Studentas3(){
        paz_.clear();
    }

    inline string vardas() const { return vard_; }
    inline string pavarde() const { return pav_; } 
    inline list<int> pazymiai() const {return paz_;}
    inline int egzaminas() const { return egz_;}
    inline void setVardas(const string& vardas) { vard_ = vardas; }
    inline void setPavarde(const string& pavarde) { pav_ = pavarde; }
    inline void setPazymiai(const list<int>& pazymiai) { paz_ = pazymiai; }
    inline void setEgzaminas(int egzaminas) { egz_ = egzaminas; }
    double galBalas(double (*func)(std::list<int>) = mediana2) const;
    std::istream& readStudent(std::istream&);
};

class Studentas4 {
    private:
    string vard_, pav_;
	list <int> paz_;
	int egz_;
	string vert_;
    public:
    Studentas4() : egz_(0) {}
    Studentas4(std::istream& is);
    Studentas4(const Studentas4& that) : vard_(that.vard_), pav_(that.pav_), paz_(that.paz_), egz_(that.egz_), vert_(that.vert_) {}
    Studentas4& operator=(const Studentas4& that){
        vard_ = that.vard_;
        pav_ = that.pav_;
        paz_ = that.paz_;
        egz_ = that.egz_;
        vert_ = that.vert_;
        return *this;
    }
    ~Studentas4(){
        paz_.clear();
    }

    inline string vardas() const { return vard_; }
    inline string pavarde() const { return pav_; } 
    inline list<int> pazymiai() const {return paz_;}
    inline int egzaminas() const { return egz_;}
    inline void setVardas(const string& vardas) { vard_ = vardas; }
    inline void setPavarde(const string& pavarde) { pav_ = pavarde; }
    inline void setPazymiai(const list<int>& pazymiai) { paz_ = pazymiai; }
    inline void setEgzaminas(int egzaminas) { egz_ = egzaminas; }
    double galBalas(double (*func)(std::list<int>) = mediana2) const;
    std::istream& readStudent(std::istream&);
    friend std::istream& operator>>(std::istream&, Studentas4&);
};

std::ostream& operator<<(std::ostream& os, const Studentas4& s);
std::istream& operator>>(std::istream&, Studentas4&);

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
float vidurkis(vector<int> vekt);
vector <int> random(int n);
void generatorius(int x, string pavadinimas);

bool pagalvarda(const studentas& a, const studentas& b);
bool pagalrez(const studentas& a, const studentas& b);
bool pagalrez3(const studentas3& a, const studentas3& b);
void vector1(string pavadinimas, string naujas1, string naujas2);
void vector2(string pavadinimas, string naujas1);
void vector3(string pavadinimas, string naujas1);
bool rezultatas(const studentas& a);
bool rezultatas3(const studentas3& a);

bool pagalrez2(const studentas2& a, const studentas2& b);
bool pagalrez4(const studentas4& a, const studentas4& b);
void list1(string pavadinimas, string naujas1, string naujas2);
void list2(string pavadinimas, string naujas1);
void list3(string pavadinimas, string naujas1, string naujas2);
bool rezultatas4(const studentas4& a);

bool PagalRez(const Studentas& a, const Studentas& b);
bool PagalRez2(const Studentas2& a, const Studentas2& b);
void vector1c(string pavadinimas, string naujas1, string naujas2);
void vector2c(string pavadinimas, string naujas1, string naujas2);
void vector3c(string pavadinimas, string naujas1, string naujas2);
bool Rezultatas1(const Studentas& a);
bool Rezultatas(const Studentas2& a);

bool PagalRez3(const Studentas3& a, const Studentas3& b);
bool PagalRez4(const Studentas4& a, const Studentas4& b);
void list1c(string pavadinimas, string naujas1, string naujas2);
void list2c(string pavadinimas, string naujas1, string naujas2);
void list3c(string pavadinimas, string naujas1, string naujas2);
bool Rezultatas2(const Studentas4& a);
bool Rezultatas3(const Studentas3& a);