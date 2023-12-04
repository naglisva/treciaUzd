#include "my_lib.h"

//test
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
	list2c("pirmas.txt", "blogi1_l2.txt", "blogi1_l2.txt");
	list2c("antras.txt", "blogi2_l2.txt", "blogi2_l2.txt");
	list2c("trecias.txt", "blogi3_l2.txt", "blogi3_l2.txt");
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
	vector2c("pirmas.txt", "blogi1_v2.txt", "geri1_v2.txt");
	vector2c("antras.txt", "blogi2_v2.txt", "geri2_v2.txt");
	vector2c("trecias.txt", "blogi3_v2.txt", "geri3_v2.txt");
	//vector2c("ketvirtas.txt", "blogi4_v2.txt", "geri4_v2.txt");
	//vector2c("penktas.txt", "blogi5_v2.txt", "geri5_v2.txt");
	cout << endl;

	cout << "Naudojant vektoriu, 3 strategija " << endl;
	vector3c("pirmas.txt", "geri1_v3.txt", "blogi1_v3.txt");
	vector3c("antras.txt", "geri2_v3.txt", "blogi2_v3.txt");
	vector3c("trecias.txt", "geri3_v3.txt", "blogi3_v3.txt");
	//vector3c("ketvirtas.txt", "geri4_v3.txt", "blogi4_v3.txt");
	//vector3c("penktas.txt", "geri5_v3.txt", "blogi5_v3.txt");
	cout << endl;
}