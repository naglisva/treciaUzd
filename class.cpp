#include "class.h"

Studentas::Studentas(std::istream& is){
    readStudent(is);
}

double Studentas::galBalas(double (*func)(vector<int>) = mediana2<vector<int>>) const {
    vector<int> values = paz_;
    double result = func(values)*0.4 + egz_ *0.6;
    return result;
}

bool PagalRez(const Studentas& a, const Studentas& b) {
	return a.galBalas() < b.galBalas();
}