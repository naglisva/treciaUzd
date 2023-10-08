#include "my_lib.h"
/*
int nuskaitymas() {
	ifstream file("kursiokai.txt.txt");
	vector<studentas> mokiniai;
	studentas Laik;

	if (!file.is_open()) {
		perror(("Klaida atidarant faila " + string("kursiokai.txt.txt")).c_str());
		exit(EXIT_FAILURE);
	}

	if (!file) {
		cout << "Nepavyko atidaryti failo";
		return 1;
	}

	string dummyLine;
	getline(file, dummyLine);
	while (file >> Laik.pav >> Laik.vard) {
		string line;
		getline(file, line);
		istringstream iss(line);
		int nd;
		vector<int> temp;
		while (iss >> nd) {
			temp.push_back(nd);
		}
		for (int i = 0; i < temp.size() - 1; i++) {
			Laik.paz.push_back(temp[i]);
		}
		Laik.egz = temp.back();
		Laik.mgrez = mediana(Laik.paz)*0.6 + Laik.egz*0.4;
		mokiniai.push_back(Laik);
		Laik.paz.clear();
	}

	file.close();

	sort(mokiniai.begin(), mokiniai.end(), pagalvarda);

	printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis(Med.)");
	printf("|--------------------|--------------------|--------------------|\n");
	for (auto& a : mokiniai)
		printf("|%20s|%20s|%20.2f|\n", a.vard.c_str(), a.pav.c_str(), a.mgrez);
	printf("|--------------------|--------------------|--------------------|\n");

	return 0;
}*/

void generatorius(int x, string pavadinimas) {
	srand(time(nullptr));
	ofstream file(pavadinimas);

	for (int n = 1; n <= x; ++n) {
		file << "vard(" << n << ") pav(" << n << ")";
		for (int i = 0; i < 8; ++i) {
			file << "  " << (rand() % 10 + 1);
		}
		file << "\n";
	}

	file.close();
}


void skirstymas(string pavadinimas, string naujas) {
	ifstream inputfile(pavadinimas);
	ofstream outputfile(naujas);
	vector<studentas> mokiniai;
	mokiniai.reserve(10000001);

	string line;
	while (getline(inputfile, line)) {
		istringstream iss(line);
		studentas Laik;
		iss >> Laik.pav >> Laik.vard;
		int nd;
		vector<int> temp;
		while (iss >> nd) {
			temp.push_back(nd);
		}
		for (int i = 0; i < temp.size() - 1; i++) {
			Laik.paz.push_back(temp[i]);
		}
		Laik.egz = temp.back();
		Laik.mgrez = mediana(Laik.paz) * 0.4 + Laik.egz * 0.6;
		if (Laik.mgrez < 5) {
			Laik.vert = "blogai";
		}
		else {
			Laik.vert = "gerai";
		}
		mokiniai.push_back(move(Laik));
	}

	for (auto& mok : mokiniai) {
		outputfile << mok.pav << " " << mok.vard << " ";
		for (auto& paz : mok.paz) {
			outputfile << paz << " ";
		}
		outputfile << mok.egz << " " << mok.vert << endl;
	}
}