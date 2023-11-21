#include "my_lib.h"

void vector1c(string pavadinimas, string naujas1, string naujas2) {
    ifstream inputfile(pavadinimas);
    ofstream outputfile1(naujas1);
    ofstream outputfile2(naujas2);
    vector<Studentas> mokiniai;

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
        Studentas Laik;
        string vardas, pavarde;
        iss >> vardas >> pavarde;
        Laik.setVardas(vardas);
        Laik.setPavarde(pavarde);
        int nd;
        vector<int> temp;
        while (iss >> nd) {
            temp.push_back(nd);
        }
        vector<int> pazymiai(temp.begin(), prev(temp.end()));
        Laik.setPazymiai(pazymiai);
        Laik.setEgzaminas(temp.back());
        auto end_line_read = high_resolution_clock::now(); 

        auto start_calc = high_resolution_clock::now(); 
        Laik.galBalas(mediana2);
        auto end_calc = high_resolution_clock::now(); 

        mokiniai.push_back(move(Laik));

        read_duration += duration_cast<microseconds>(end_line_read - start_line_read);
        calc_duration += duration_cast<microseconds>(end_calc - start_calc);
    }

    sort(mokiniai.begin(), mokiniai.end(), PagalRez);

    for (const auto& Laik : mokiniai) {
        auto start_write = high_resolution_clock::now(); 
        if (Laik.galBalas(mediana2) < 5) {
            outputfile2 << Laik.vardas() << " " << Laik.pavarde() << "   " << Laik.galBalas(mediana2) << endl;
        }
        else {
            outputfile1 << Laik.vardas() << " " << Laik.pavarde() << "   " << Laik.galBalas(mediana2) << endl;
        }
        auto end_write = high_resolution_clock::now(); 
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