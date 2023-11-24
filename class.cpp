#include "my_lib.h"

#include <string>
#include <vector>


std::istream& Studentas::readStudent(std::istream& is) {
    std::string vardas;
    is >> vardas;
    setVardas(vardas);

    std::string pavarde;
    is >> pavarde;
    setPavarde(pavarde);

    std::vector<int> pazymiai;
    int pazymys;
    while (is >> pazymys) {
        pazymiai.push_back(pazymys);
    }
    setPazymiai(pazymiai);

    int egzaminas = pazymiai.back(); 
    pazymiai.pop_back(); 
    setEgzaminas(egzaminas);

    return is;
}



double Studentas::galBalas(double (*func)(std::vector<int>)) const {
    std::vector<int> values = paz_;
    double result = func(values)*0.4 + egz_ *0.6;
    return result;
}

bool PagalRez(const Studentas& a, const Studentas& b) {
	return a.galBalas() < b.galBalas();
}

std::istream& Studentas2::readStudent(std::istream& is) {
    std::string vardas;
    is >> vardas;
    setVardas(vardas);

    std::string pavarde;
    is >> pavarde;
    setPavarde(pavarde);

    std::vector<int> pazymiai;
    int pazymys;
    while (is >> pazymys) {
        pazymiai.push_back(pazymys);
    }
    setPazymiai(pazymiai);

    int egzaminas = pazymiai.back(); 
    pazymiai.pop_back(); 
    setEgzaminas(egzaminas);

    return is;
}



double Studentas2::galBalas(double (*func)(std::vector<int>)) const {
    std::vector<int> values = paz_;
    double result = func(values)*0.4 + egz_ *0.6;
    return result;
}

bool PagalRez2(const Studentas2& a, const Studentas2& b) {
	return a.galBalas() < b.galBalas();
}

bool Rezultatas(const Studentas2& a) {
	return a.galBalas() >= 5;
}

std::istream& Studentas3::readStudent(std::istream& is) {
    std::string vardas;
    is >> vardas;
    setVardas(vardas);

    std::string pavarde;
    is >> pavarde;
    setPavarde(pavarde);

    std::list<int> pazymiai;
    int pazymys;
    while (is >> pazymys) {
        pazymiai.push_back(pazymys);
    }
    setPazymiai(pazymiai);

    int egzaminas = pazymiai.back(); 
    pazymiai.pop_back(); 
    setEgzaminas(egzaminas);

    return is;
}



double Studentas3::galBalas(double (*func)(std::list<int>)) const {
    std::list<int> values = paz_;
    double result = func(values)*0.4 + egz_ *0.6;
    return result;
}

bool PagalRez3(const Studentas3& a, const Studentas3& b) {
	return a.galBalas() < b.galBalas();
}

std::istream& Studentas4::readStudent(std::istream& is) {
    std::string vardas;
    is >> vardas;
    setVardas(vardas);

    std::string pavarde;
    is >> pavarde;
    setPavarde(pavarde);

    std::list<int> pazymiai;
    int pazymys;
    while (is >> pazymys) {
        pazymiai.push_back(pazymys);
    }
    setPazymiai(pazymiai);

    int egzaminas = pazymiai.back(); 
    pazymiai.pop_back(); 
    setEgzaminas(egzaminas);

    return is;
}



double Studentas4::galBalas(double (*func)(std::list<int>)) const {
    std::list<int> values = paz_;
    double result = func(values)*0.4 + egz_ *0.6;
    return result;
}

bool PagalRez4(const Studentas4& a, const Studentas4& b) {
	return a.galBalas() < b.galBalas();
}

bool Rezultatas2(const Studentas4& a) {
	return a.galBalas() >= 5;
}