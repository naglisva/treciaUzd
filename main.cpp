#include "my_lib.h"

int main() {
	//generatorius(1000,"pirmas.txt");
	//generatorius(10000,"antras.txt");
	//generatorius(100000,"trecias.txt");
	//generatorius(1000000,"ketvirtas.txt");
	//generatorius(10000000,"penktas.txt");
	skirstymas("pirmas.txt","geri1.txt", "blogi1.txt");
	skirstymas("antras.txt", "geri2.txt", "blogi2.txt");
	skirstymas("trecias.txt", "geri3.txt", "blogi3.txt");
	skirstymas("ketvirtas.txt", "geri4.txt", "blogi4.txt");
	skirstymas("penktas.txt", "geri5.txt", "blogi5.txt");
}