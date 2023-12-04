#include "my_lib.h"

void list1c(string pavadinimas, string naujas1, string naujas2) {
    ifstream inputfile(pavadinimas);
    ofstream outputfile1(naujas1);
    ofstream outputfile2(naujas2);
    list<Studentas3> mokiniai;
    list<Studentas3> mokiniai_g;
    list<Studentas3> mokiniai_b;

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
        Studentas3 Laik;
        string vardas, pavarde;
        iss >> vardas >> pavarde;
        Laik.setVardas(vardas);
        Laik.setPavarde(pavarde);
        int nd;
        list<int> temp;
        while (iss >> nd) {
            temp.push_back(nd);
        }
        list<int> pazymiai(temp.begin(), prev(temp.end()));
        Laik.setPazymiai(pazymiai);
        Laik.setEgzaminas(temp.back());
        auto end_line_read = high_resolution_clock::now(); 

        auto start_calc = high_resolution_clock::now(); 
        Laik.galBalas(mediana2);
        auto end_calc = high_resolution_clock::now(); 

        mokiniai.push_back(move(Laik));

        if (Laik.galBalas(mediana2) < 5){
            mokiniai_b.push_back(move(Laik));
        }
        else {
            mokiniai_g.push_back(move(Laik));
        }

        read_duration += duration_cast<microseconds>(end_line_read - start_line_read);
        calc_duration += duration_cast<microseconds>(end_calc - start_calc);
    }


    mokiniai_b.sort(PagalRez3);
    mokiniai_g.sort(PagalRez3);

    auto start_write = high_resolution_clock::now();
    for (const auto& Laik : mokiniai_b) {
        outputfile2 << Laik.vardas() << " " << Laik.pavarde() << "   " << Laik.galBalas(mediana2) << endl;
    }
    for (const auto& Laik : mokiniai_g) {
        outputfile1 << Laik.vardas() << " " << Laik.pavarde() << "   " << Laik.galBalas(mediana2) << endl;
    }
    auto end_write = high_resolution_clock::now(); 
    write_duration += duration_cast<microseconds>(end_write - start_write);

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

void list2c(string pavadinimas, string naujas1, string naujas2) {
    ifstream inputfile(pavadinimas);
    ofstream outputfile1(naujas1);
    ofstream outputfile2(naujas2);
    list<Studentas3> mokiniai;
    list<Studentas3> mokiniai_b;

    outputfile1 << "Vardas  Pavarde  Rezultatas" <<endl;
    outputfile2 << "Vardas  Pavarde  Rezultatas" <<endl;

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
        Studentas3 Laik;
        string vardas, pavarde;
        iss >> vardas >> pavarde;
        Laik.setVardas(vardas);
        Laik.setPavarde(pavarde);
        int nd;
        list<int> temp;
        while (iss >> nd) {
            temp.push_back(nd);
        }
        list<int> pazymiai(temp.begin(), prev(temp.end()));
        Laik.setPazymiai(pazymiai);
        Laik.setEgzaminas(temp.back());
        auto end_line_read = high_resolution_clock::now(); 

        auto start_calc = high_resolution_clock::now(); 
        Laik.galBalas(mediana2);
        auto end_calc = high_resolution_clock::now(); 

        Studentas3 newStudent;
        newStudent = Laik;
        mokiniai.push_back(newStudent);

        read_duration += duration_cast<microseconds>(end_line_read - start_line_read);
        calc_duration += duration_cast<microseconds>(end_calc - start_calc);
    }

    mokiniai.sort(PagalRez3);
    auto it = find_if(mokiniai.begin(), mokiniai.end(), Rezultatas3);
    move(it, mokiniai.end(), std::back_inserter(mokiniai_b));
    mokiniai.erase(it, mokiniai.end());


    auto start_write = high_resolution_clock::now();
    for (const auto& Laik : mokiniai_b) {
        outputfile2 << Laik.vardas() << " " << Laik.pavarde() << "   " << Laik.galBalas(mediana2) << endl;
    }
    for (const auto& Laik : mokiniai) {
        outputfile1 << Laik.vardas() << " " << Laik.pavarde() << "   " << Laik.galBalas(mediana2) << endl;
    }
    auto end_write = high_resolution_clock::now(); 
    write_duration += duration_cast<microseconds>(end_write - start_write);

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

std::ostream& operator<<(std::ostream& os, const Studentas4& s) {
    os << s.pavarde() << " " << s.vardas() << "   " << s.galBalas();
    return os;
}

std::istream& operator>>(std::istream& is, Studentas4& s) {
    std::string line;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::string vardas, pavarde;
        std::list<int> pazymiai;
        int pazymys;

        iss >> vardas >> pavarde;
        s.setVardas(vardas);
        s.setPavarde(pavarde);

        while (iss >> pazymys) {
            pazymiai.push_back(pazymys);
        }

        int egzaminas = pazymiai.back();
        pazymiai.pop_back();
        s.setPazymiai(pazymiai);
        s.setEgzaminas(egzaminas);
    }
    return is;
}

void list3c(string pavadinimas, string naujas1, string naujas2) {
    ifstream inputfile(pavadinimas);
    ofstream outputfile1(naujas1);
    ofstream outputfile2(naujas2);
    list<Studentas4> mokiniai;

    outputfile2 << "Vardas  Pavarde  Rezultatas" <<endl;
    outputfile1 << "Vardas  Pavarde  Rezultatas" <<endl;
    
    string dummyLine;
	getline(inputfile, dummyLine);
    string line;

    auto start_total = high_resolution_clock::now(); 
    microseconds read_duration(0);
    microseconds calc_duration(0);
    microseconds write_duration(0);

    Studentas4 Laik;
    auto start_line_read = high_resolution_clock::now(); 
    while (inputfile >> Laik) {
        auto start_calc = high_resolution_clock::now(); 
        Laik.galBalas(mediana2);
        auto end_calc = high_resolution_clock::now(); 

        mokiniai.push_back(move(Laik));

        calc_duration += duration_cast<microseconds>(end_calc - start_calc);
    }
    auto end_line_read = high_resolution_clock::now(); 
    read_duration += duration_cast<microseconds>(end_line_read - start_line_read);
    mokiniai.sort(PagalRez4);

    auto partition_point = stable_partition(mokiniai.begin(), mokiniai.end(),  Rezultatas2);

    auto start_write = high_resolution_clock::now(); 
    copy(mokiniai.begin(), partition_point, ostream_iterator<Studentas4>(outputfile1, "\n"));
    copy(partition_point, mokiniai.end(), ostream_iterator<Studentas4>(outputfile2, "\n"));
    auto end_write = high_resolution_clock::now(); 
    write_duration += duration_cast<microseconds>(end_write - start_write);

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