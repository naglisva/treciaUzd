#include "my_lib.h"

int main() {
	generatorius(1000, "pirmas.txt");
	skirstymas("pirmas.txt","pirmasS.txt");
	generatorius(10000, "antras.txt");
	skirstymas("antras.txt", "asntrasS.txt");
	generatorius(100000, "trec.txt");
	skirstymas("trec.txt", "trecS.txt");
	generatorius(1000000, "ketv.txt");
	skirstymas("ketv.txt", "ketvS.txt");
	generatorius(10000000, "penkt.txt");
	skirstymas("penkt.txt", "penktS.txt");
}