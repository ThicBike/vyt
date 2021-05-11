#include <stdio.h>
#include <stdlib.h>

const int TRUE = 1;
const int FALSE = 0;

void nacitanie_pola(int *pole, int velkost);
void vypis(int *pole, int velkost);
void moznosti(int *pole, int velkost);
int kontrola_volby(char volba);

int maximum_pola(int *pole, int velkost);
int minimum_pola(int *pole, int velkost);
int priemer_pola(int *pole, int velkost);
int sucet_pola(int *pole, int velkost);

int main() {
	int *pole = NULL;
	int velkost;
	
	printf("Zadaj velkost pola: ");
	scanf("%d", &velkost);
	
	pole = (int *)malloc(velkost * sizeof(int));
	
	if(pole != NULL){
		nacitanie_pola(pole, velkost);
		vypis(pole, velkost);
		moznosti(pole, velkost);
	}else{
		printf("\nAlokacia neprebehla :(");
	}
	
	free(pole);
	
	return 0;
}

void nacitanie_pola(int *pole, int velkost){
	int i;
	
	for(i = 0; i < velkost; i++){
		printf("Zadaj %d. cislo pola: ", i + 1);
		scanf("%d", (pole + i));
	}
}

void vypis(int *pole, int velkost){
	int i;
	printf("\nVypis pola: ");
	for(i = 0; i < velkost; i++){
		printf("%d	", *(pole + i));
	}
}

void moznosti(int *pole, int velkost){
	char volba;
	
	do{
		printf("\n\nm)Maximum\n");
		printf("n)Minimum\n");
		printf("p)Priemer\n");
		printf("s)Sucet\n");
		printf("k)Koniec\n");
		
		do{
			printf("\nTvoja volba: ");
			getchar();
			volba = getchar();
		}while(kontrola_volby(volba) == TRUE);
		
		switch(volba){
			case 'm':
				printf("\nMaximum v poli je: %d\n", maximum_pola(pole, velkost));
				break;
				
			case 'n':
				printf("\nMinimum v poli je: %d\n", minimum_pola(pole, velkost));
				break;
			
			case 'p':
				printf("\nPriemer v poli je: %d\n", priemer_pola(pole, velkost));
				break;
				
			case 's':
				printf("\nSucet v poli je: %d\n", sucet_pola(pole, velkost));
				break;
				
			case 'k':
				printf("\n\n######     Dovidenia!     ######");
				break;
		}	
	}while(volba != 'k');
	
}

int kontrola_volby(char volba){
	if(volba == 'm' || volba == 'n' || volba == 'p' || volba == 's' || volba == 'k'){
		return FALSE;
	}else{
		printf("\nZle zadany znak!\nOpakuje zadanie znaku!\n\n");
	}
	
	return TRUE;
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



