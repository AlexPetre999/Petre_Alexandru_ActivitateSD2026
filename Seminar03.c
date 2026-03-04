#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

void afisareMasina(Masina masina) {
	printf("\nId: %d", masina.id);
	printf("\nNrUsi: %d", masina.nrUsi);
	printf("\nPret: %f", masina.pret);
	printf("\nModel: %s", masina.model);
	printf("\nNumele Soferului: %s", masina.numeSofer);
	printf("\nSerie: %c", masina.serie);
}

void afisareVectorMasini(Masina* masini, int nrMasini) {
	for (int i = 0; i < nrMasini; i++) {
		afisareMasina(masini[i]);
	}
}

void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
	(*nrMasini)++;
	Masina* aux = malloc(sizeof(Masina) * (*nrMasini));
	for (int i = 0; i < (*nrMasini); i++) {
		aux[i] = (*masini)[i];  //shallow copy
	}
	aux[(*nrMasini) - 1] = masinaNoua;
	free(*masini);
	*masini = aux;
}

Masina citireMasinaFisier(FILE* file) {
	char linie[50];
	fgets(linie, 50, file);
	char delimitator[3] = ",\n";
	Masina masina;
	masina.id=atoi(strtok(linie, delimitator));
	masina.nrUsi = atoi(strtok(NULL, delimitator));
	masina.pret = atof(strtok(NULL, delimitator));
	char* model = strtok(NULL, delimitator);
	masina.model = malloc((strlen(model) + 1) * sizeof(char));
	strcpy(masina.model, model);
	
	char* numeSofer = strtok(NULL, delimitator);
	masina.numeSofer = malloc((strlen(numeSofer) + 1) * sizeof(char));
	strcpy(masina.numeSofer);

}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
	//functia primeste numele fisierului, il deschide 
	// si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaFisier()
	//numarul de masini este determinat prin numarul de citiri din fisier
	//ATENTIE - la final inchidem fisierul/stream-ul
	Masina* masini = NULL;
	FILE* file = fopen(numeFisier, "r");
	*nrMasiniCitite = 0;
	while (!feof(file)) {
		adaugaMasinaInVector(&masini, &nrMasiniCitite, citireMasinaFisier(file));
	}
	fclose(file);
	return masini;
}

void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	//este dezalocat intreg vectorul de masini
}

int main() {

	FILE* file = fopen("masini.txt", "r");
	Masina masina = citireMasinaFisier(file);
	afisareMasina();


	Masina* masini;
	int nr = 0;
	masini = citireVectorMasiniFisier("masini.txt", &nr);
	afisareVectorMasini(masini, nr);
	return 0;
}