//==========================//
//		Tibor Pelegrin		//
//			3.A 2.sk		//
//     BUBBLE SORT + menu  	//
//==========================//

#include <stdio.h>
#include <stdlib.h>


const int TRUE = 1;
const int FALSE = 0;

int nacitanie_velkosti();
void nacitanie_cisel(int *cisla, int velkost);
int* alokacia(int velkost_pola);

void vypis(int *cisla, int velkost);
void moznosti(int *cisla, int velkost);
int kontrola_volby(char volba);

void bubble_sort(int *cisla, int velkost);
int maximum_pola(int *cisla, int velkost);
int minimum_pola(int *cisla, int velkost);
int priemer_pola(int *cisla, int velkost);
int sucet_pola(int *cisla, int velkost);

int main() {
	int *cisla = NULL;
	int velkost = nacitanie_velkosti();
	
	cisla = alokacia(velkost);
	
	if(cisla == NULL){
		printf("Alokacia neprebehla :(");
		return 0;
	} 
	
	nacitanie_cisel(cisla, velkost);
	printf("\nZadane pole: ");
	vypis(cisla, velkost);
	moznosti(cisla, velkost);
	
	return 0;
}

int nacitanie_velkosti(){
	int cislo;
	
	do{
		printf("Zadaj velkost pola: ");
		scanf("%d", &cislo);
		if(cislo <= 0) printf("\nZadaj kladne cislo!\n");
	}while( cislo <= 0);
	
	return cislo;
}

void nacitanie_cisel(int *cisla, int velkost){
	int i;
	
	for(i = 0; i < velkost; i++){
		printf("Zadaj %d. cislo pola: ", i + 1);
		scanf("%d", (cisla + i));
	}
}

int* alokacia(int velkost_pola){
	int *cisla;
	
	cisla = (int *)malloc(velkost_pola * sizeof(int));
	
	return cisla;
}

void vypis(int *cisla, int velkost){
	int i;
	
	for(i = 0; i < velkost; i++){
		printf("%d ", *(cisla + i));
	}
}

void moznosti(int *cisla, int velkost){
	char volba;
	
	do{
		printf("\n\nm)Maximum\n");
		printf("n)Minimum\n");
		printf("p)Priemer\n");
		printf("s)Sucet\n");
		printf("b)Bubble sort\n");
		printf("k)Koniec\n");
		
		do{
			printf("\nTvoja volba: ");
			getchar();
			volba = getchar();
		}while(kontrola_volby(volba));
		
		switch(volba){
			case 'm':
				printf("\nMaximum v poli je: %d\n", maximum_pola(cisla, velkost));
				break;
				
			case 'n':
				printf("\nMinimum v poli je: %d\n", minimum_pola(cisla, velkost));
				break;
			
			case 'p':
				printf("\nPriemer v poli je: %d\n", priemer_pola(cisla, velkost));
				break;
				
			case 's':
				printf("\nSucet v poli je: %d\n", sucet_pola(cisla, velkost));
				break;
				
			case 'b':
				bubble_sort(cisla, velkost);
				break;
				
			case 'k':
				printf("\n\n######     Dovidenia!     ######");
				break;
		}	
	}while(volba != 'k');
	
}

int kontrola_volby(char volba){
	if(volba == 'm' || volba == 'n' || volba == 'p' || volba == 's' || volba == 'b' || volba == 'k'){
		return FALSE;
	}else{
		printf("\nZle zadany znak!\nOpakuje zadanie znaku!\n\n");
	}
	
	return TRUE;
}

void bubble_sort(int *cisla, int velkost){
	int i, j;
	int buffer, vymena = TRUE, pocet_prechodov = 0;
	
	printf("\n##### BUBBLE SORT #####\n");
	
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
	
	printf("\n\nUsporiadane pole: ");
	vypis(cisla, velkost);
}

int maximum_pola(int *pole, int velkost){
	int i = 0;
	int max = *pole;
	
	for(i = 1; i < velkost; i++){
		if(max < *(pole + i)) max = *(pole + i);
	}
	
	return max;
}

int minimum_pola(int *pole, int velkost){
	int i = 0;
	int min = *pole;
	
	for(i = 1; i < velkost; i++){
		if(min > *(pole + i)) min = *(pole + i);
	}
	
	return min;
}

int priemer_pola(int *pole, int velkost){
	return sucet_pola(pole, velkost) / velkost;
}

int sucet_pola(int *pole, int velkost){
	int sucet = 0;
	int i;
	
	for(i = 0; i < velkost; i++){
		sucet += *(pole + i);
	}
	
	return sucet;
}






