#include "my_lib.h"


int nuskaitymas() {
	ifstream file("kursiokai.txt.txt");
	vector<studentas> mokiniai;
	studentas Laik;

	if (!file.is_open()) {
		perror(("Klaida atidarant faila " + string("C:/Users/nagli/source/repos/Project1/kursiokai.txt")).c_str());
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
}

