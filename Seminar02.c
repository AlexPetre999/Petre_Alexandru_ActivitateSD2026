//#include<stdio.h>
//#include<malloc.h>
//
//struct Film {
//	int id;
//	int durata;
//	char* denumire ;
//	float buget;
//	char varstaMinima;
//};
//struct Film initializare(int _id, int _durata, const char* _denumire, float _buget, char _varstMinima) {
//	struct Film s;
//	s.id = _id;
//	s.durata = _durata;
//	s.denumire = malloc((strlen(_denumire) + 1) + sizeof(char));
//	strcpy(s.denumire, _denumire);
//	s.buget = _buget;
//	s.varstaMinima = _varstMinima;
//	return s;
//}
//
//struct Film copyFilm(struct Film s) {
//	return initializare(s.id, s.durata, s.denumire, s.buget, s.varstaMinima);
//}
//
//void afisare(struct Film s) {
//	printf("ID: %d\n", s.id);
//	printf("Nume: %s\n", s.denumire);
//	printf("Durata in minute: %d\n", s.durata);
//	printf("Buget: %.2f\n", s.buget);
//	printf("Varsta minima: %s\n", s.varstaMinima);
//}
//
//void afisareVector(struct Film* vector, int nrElemente) {
//	for (int i = 0; i < nrElemente;i++) {
//		afisare(vector[i]);
//		printf("\n");
//	}
//	
//}
//
//struct Film* copiazaPrimeleNElemente(struct Film* vector, int nrElemente, int nrElementeCopiate) {
//	struct Film* vectorNou = malloc(nrElementeCopiate * sizeof(struct Film));
//	for (int i = 0; i < nrElementeCopiate; i++) {
//		vectorNou[i] = copyFilm(vector[i]);
//	}
//	return vectorNou;
//}
//
//void dezalocare(struct Film** vector, int* nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		free((*vector)[i].denumire);
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrElemente = 0;
//}
//
//void copiazaAnumiteElemente(struct Film* vector, char nrElemente, float bugetMaxim, struct Film** vectorNou, int* dimensiune) {
//	//parametrul prag poate fi modificat in functie de 
//	// tipul atributului ales pentru a indeplini o conditie
//	//este creat un nou vector cu elementele care indeplinesc acea conditie
//	dimensiune = 0;
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].buget < bugetMaxim)
//			(*dimensiune)++;
//	}
//	(*vectorNou) = malloc((*dimensiune) * sizeof(struct Film));
//	int k = 0;
//	for (int i = 0; i < (*dimensiune); i++) {
//		if (vector[i].buget < bugetMaxim) {
//			(*vectorNou)[i] = copyFilm(vector[i]);
//			k++;
//		}
//	}
//}
//
//struct Film getPrimulElementConditionat(struct Film* vector, int nrElemente, const char* numeCautat) {
//	//trebuie cautat elementul care indeplineste o conditie
//	//dupa atributul de tip char*. Acesta este returnat.
//	struct Film s;
//	s.id = -1;
//	for (int i = 0; i < nrElemente; i++) {
//		if (!strcmp(vector[i].denumire, numeCautat))
//			return vector[i];
//	}
//
//	return s;
//}
//	
//
//
//int main() {
//	struct Film f1 = initializare(1, 120, "Dune", 20.6, 14);
//	afisare(f1);
//
//	int nrFilme = 3;
//	struct Film* filme = malloc(nrFilme * sizeof(struct Film));
//	filme[0] = f1;
//	*(filme + 1) = initializare(2, 360, "James Bond", 16, 12);
//	filme[2] = initializare(3, 240, "Star Wars", 50.6, 12);
//
//	afisareVector(filme, nrFilme);
//	int nrFilmeCopiate = 2;
//	struct Film* vectorNou;
//	vectorNou = copiazaPrimeleNElemente(filme, nrFilme, nrFilmeCopiate);
//	printf("\nElemente Copiate : \n");
//	afisareVector(vectorNou, nrFilmeCopiate);
//	dezalocare(&vectorNou, &nrFilmeCopiate);
//	struct Film* vectorIeftin;
//	float prag = 50;
//	int dimIeftin;
//	copiazaAnumiteElemente(filme, 50, prag, &vectorIeftin, &dimIeftin);
//	afisareVector(vectorIeftin, dimIeftin);
//	afisare(getPrimulElementConditionat(filme, nrFilme, "Dune"));
//	dezalocare(&filme, &nrFilme);
//	return 0;
//}