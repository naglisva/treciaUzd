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

	auto start = high_resolution_clock::now();

    file << "Vardas  Pavarde  Pazymiai" <<endl;

	for (int n = 1; n <= x; ++n) {
		file << "vard(" << n << ") pav(" << n << ")";
		for (int i = 0; i < 8; ++i) {
			file << "  " << (rand() % 10 + 1);
		}
		file << "\n";
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);

	cout << "Faila sukurt uztruko: "
		<< duration.count() << " sek." << endl;

	file.close();
}


void skirstymas(string pavadinimas, string naujas1, string naujas2) {
    ifstream inputfile(pavadinimas);
    ofstream outputfile1(naujas1);
    ofstream outputfile2(naujas2);
    vector<studentas> mokiniai;
    mokiniai.reserve(10000001);

    outputfile2 << "Vardas  Pavarde  Rezultatas" <<endl;
    outputfile1 << "Vardas  Pavarde  Rezultatas" <<endl;
    
    string dummyLine;
	getline(inputfile, dummyLine);

    string line;

    auto start_total = high_resolution_clock::now(); 
    microseconds read_duration(0);
    microseconds calc_duration(0);
    microseconds write_duration(0);

    while (getline(inputfile, line)) {
        auto start_line_read = high_resolution_clock::now(); 
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
        auto end_line_read = high_resolution_clock::now(); 

        auto start_calc = high_resolution_clock::now(); 
        Laik.mgrez = mediana(Laik.paz) * 0.4 + Laik.egz * 0.6;
        auto end_calc = high_resolution_clock::now(); 

        auto start_write = high_resolution_clock::now(); 
        if (Laik.mgrez < 5) {
            outputfile2 << Laik.pav << " " << Laik.vard << "   " << Laik.mgrez << endl;
        }
        else {
            outputfile1 << Laik.pav << " " << Laik.vard << "   " << Laik.mgrez << endl;
        }
        auto end_write = high_resolution_clock::now(); 

        mokiniai.push_back(move(Laik));

        read_duration += duration_cast<microseconds>(end_line_read - start_line_read);
        calc_duration += duration_cast<microseconds>(end_calc - start_calc);
        write_duration += duration_cast<microseconds>(end_write - start_write);
    }

    auto end_total = high_resolution_clock::now(); 

    cout << "Visas eilutes nuskaityt uztruko: "
        << double(read_duration.count())/1000000
        << " sek."
        << endl;
    cout << "Visus rezultatus suskaiciuot uztruko: "
        << double(calc_duration.count())/1000000
        << " sek."
        << endl;
    cout << "Informacija i failus isskirstyt uztruko: "
        << double(write_duration.count())/1000000
        << " sek."
        << endl;
    cout << "Visas procesas uztruko: "
        << double(duration_cast<std::chrono::microseconds>(end_total - start_total).count())/1000000
        << " sek."
        << endl;
}