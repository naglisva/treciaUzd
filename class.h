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

bool PagalRez(const Studentas& a, const Studentas& b);