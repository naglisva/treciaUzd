#include "my_lib.h"


int main() {
	//generatorius(1000,"pirmas.txt");
	//generatorius(10000,"antras.txt");
	//generatorius(100000,"trecias.txt");
	//generatorius(1000000,"ketvirtas.txt");
	//generatorius(10000000,"penktas.txt");
	
	
	cout << "Naudojant sarasa " << endl;
	list1c("pirmas.txt","geri1_l.txt", "blogi1_l.txt");
	list1c("antras.txt", "geri2_l.txt", "blogi2_l.txt");
	list1c("trecias.txt", "geri3_l.txt", "blogi3_l.txt");
	//list1c("ketvirtas.txt", "geri4.txt", "blogi4.txt");
	//list1c("penktas.txt", "geri5.txt", "blogi5.txt");
	cout << endl;

	cout << "Naudojant sarasa, 2 strategija " << endl;
	list2c("pirmas3.txt", "blogi1_l2.txt");
	list2c("antras3.txt", "blogi2_l2.txt");
	list2c("trecias3.txt", "blogi3_l2.txt");
	//list2c("ketvirtas3.txt", "nblogi4l.txt");
	//list2c("penktas3.txt", "nblogi5l.txt");
	cout << endl;

	cout << "Naudojant sarasa, 3 strategija " << endl;
	list3c("pirmas.txt","geri1_l3.txt", "blogi1_l3.txt");
	list3c("antras.txt", "geri2_l3.txt", "blogi2_l3.txt");
	list3c("trecias.txt", "geri3_l3.txt", "blogi3_l3.txt");
	//list3c("ketvirtas.txt", "geri4l.txt", "blogi4l.txt");
	//list3c("penktas.txt", "geri5l.txt", "blogi5l.txt");
	cout << endl;
	
	cout << "Naudojant vektoriu " << endl;
	vector1c("pirmas.txt","geri1_v.txt", "blogi1_v.txt");
	vector1c("antras.txt", "geri2_v.txt", "blogi2_v.txt");
	vector1c("trecias.txt", "geri3_v.txt", "blogi3_v.txt");
	//vector1c("ketvirtas.txt", "geri4v.txt", "blogi4v.txt");
	//vector1c("penktas.txt", "geri5v.txt", "blogi5v.txt");
	cout << endl;

	cout << "Naudojant vektoriu, 2 strategija " << endl;
	vector2c("pirmas2.txt", "blogi1_v2.txt");
	vector2c("antras2.txt", "blogi2_v2.txt");
	vector2c("trecias2.txt", "blogi3_v2.txt");
	//vector2c("ketvirtas2.txt", "nblogi4v.txt");
	//vector2c("penktas2.txt", "nblogi5v.txt");
	cout << endl;

	cout << "Naudojant vektoriu, 3 strategija " << endl;
	vector3c("pirmas4.txt", "geri1_v3.txt");
	vector3c("antras4.txt", "geri2_v3.txt");
	vector3c("trecias4.txt", "geri3_v3.txt");
	//vector3c("ketvirtas4.txt", "nnblogi4v.txt");
	//vector3c("penktas4.txt", "nnblogi5v.txt");
	cout << endl;
}