#include "my_lib.h"

void stud()
{
	studentas Laik;
	vector <studentas> grupe;
	int z;
	cout << "Kiek studentu?: ";
	cin >> z;
	for (int j = 0; j < z; j++) {
		cout << "Iveskite varda ir pavarde: ";
		cin >> Laik.vard >> Laik.pav;
		cout << "Kiek pazymiu: ";
		int n;
		cin >> n;
		Laik.paz = random(n);
		cout << "Iveskite egzamina: ";
		cin >> Laik.egz;
		Laik.vgrez = vidurkis(Laik.paz)*0.6 + Laik.egz*0.4;
		Laik.mgrez = mediana(Laik.paz) * 0.6 + Laik.egz * 0.4;
		grupe.push_back(Laik);
		Laik.paz.clear();
	}
	printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis(Med.)");
	printf("|--------------------|--------------------|--------------------|\n");
	for (auto& a : grupe)
		printf("|%20s|%20s|%20.2f|\n",a.vard.c_str(),a.pav.c_str(),a.mgrez);
	printf("|--------------------|--------------------|--------------------|\n");
}

