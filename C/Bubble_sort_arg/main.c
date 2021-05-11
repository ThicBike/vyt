//	Tibor Pelegrin 
//  3.A
//  Bubble sort arg

#include <stdio.h>
#include <stdlib.h>

const int TRUE = 1;
const int FALSE = 0;

void bubble_sort(int *cisla, int velkost);
void vypis(int *cisla, int velkost);
void vypis_do_suboru(int *cisla, int velkost, FILE *fw);

void nacitanie_cisel(FILE *fr, int *velkost, int *cisla);
char nacitanie_vstupu();
char nacitanie_vystupu();

int main(int argc, char *argv[]) {
	FILE *fr;
	FILE *fw;
	
	int *cisla;
	char vstup[100];
	char vystup[100];
	int velkost = 0;
	int i;
	char znak;
	
	if(argc == 3){
		fr = fopen(argv[1], "r");
		fw = fopen(argv[2], "w");
	}
	
	if(argc != 3 || fr == NULL || fw == NULL){
		printf("Problem so subormi!\nOpakuj zadanie suborov!\n");
		
		do{
			printf("\nZadaj vstupny subor: ");
			scanf("%s", vstup);
			
			fr = fopen(vstup, "r");
			if(fr == NULL) printf("Subor sa nenasiel!\n");
		}while(fr == NULL);
		
		do{
			printf("Zadaj vystupny subor: ");
			scanf("%s", vystup);
			
			fw = fopen(vystup, "w");
			if(fw == NULL) printf("Subor sa nevytvoril!\n");
		}while(fw == NULL);
	}

	while((znak = fgetc(fr)) != EOF){
		if(znak == '\n') velkost++;
	}
	
	cisla = (int *)malloc((velkost) * sizeof(int));
	
	fclose(fr);
	
	do{
		fr = fopen(vstup, "r");
		if(fr == NULL) fr = fopen(argv[1], "r");
	}while(fr == NULL);
	
	for(i = 0; i < velkost; i++){
		fscanf(fr, "%d", (cisla + i));
	}
	
	bubble_sort(cisla, velkost);
	
	vypis_do_suboru(cisla, velkost, fw);
	
	
	printf("\n\n\nNavstiv vystupny subor.");
	printf("\n\n####  Program ukonceny  ####");
	
	return 0;
}

void bubble_sort(int *cisla, int velkost){
	int i, j;
	int buffer, vymena = TRUE, pocet_prechodov = 0;
	
	printf("\n\n##### BUBBLE SORT #####\n");
	
	printf("\nPociatocne pole: ");
	vypis(cisla, velkost);
	
	while(vymena){
		vymena = FALSE;
		pocet_prechodov++;
		for(i = 0, j = 1; i < velkost - 1; i++, j++){
			if(*(cisla + i) > *(cisla + j)){
				vymena = TRUE;
				
				buffer = *(cisla + i);
				*(cisla + i) = *(cisla + j);
				*(cisla + j) = buffer;
			}
		}
		printf("\n\nPrechod polom: %d\n", pocet_prechodov);
		printf("Pole: ");
		vypis(cisla, velkost);
	}
}

void vypis_do_suboru(int *cisla, int velkost, FILE *fw){
	int i;
	
	for(i = 0; i < velkost; i++){
		fprintf(fw, "%d ", *(cisla + i));
	}
}

void vypis(int *cisla, int velkost){
	int i;
	
	for(i = 0; i < velkost; i++){
		printf("%d ", *(cisla + i));
	}
}







