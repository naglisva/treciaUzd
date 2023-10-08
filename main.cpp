#include "my_lib.h"

int main() {
	generatorius(1000, "pirmas.txt");
	skirstymas("pirmas.txt","geri1.txt", "blogi1.txt");
	generatorius(10000, "antras.txt");
	skirstymas("antras.txt", "geri2.txt", "blogi2.txt");
	generatorius(100000, "trec.txt");
	skirstymas("trec.txt", "geri3.txt", "blogi3.txt");
	generatorius(1000000, "ketv.txt");
	skirstymas("ketv.txt", "geri4.txt", "blogi4.txt");
	generatorius(10000000, "penkt.txt");
	skirstymas("penkt.txt", "geri5.txt", "blogi5.txt");
}