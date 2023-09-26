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
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int i = 0;
		while (true) {
			try {
				int k;
				string input;
				cout << "Iveskite " << i + 1 << " pazymi: ";
				getline(cin, input);
				if (input.empty()) {
					cout << "Daugiau pazymiu ivesta nebuvo\n";
					break;
				}
				stringstream ss(input);
				if (!(ss >> k)) {
					cout << "Failed to convert input to integer, breaking loop.\n";
					break;
				}
				Laik.paz.push_back(k);
				i++;
			}
			catch (const std::exception& e) {
				cout << "Caught exception: " << e.what() << '\n';
				break;
			}
		}
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

