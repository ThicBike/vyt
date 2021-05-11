//==========================//
//		Tibor Pelegrin		//
//			3.A 2.sk		//
//	     Praca s polom      //
//          Pointer         //
//==========================//

#include <stdio.h>
#include <stdlib.h>

const int VELKOST_POLA = 5;
const int TRUE = 1;
const int FALSE = 0;

void nacitanie_pola(int cisla[], int velkost);
void moznosti(int cisla[], int velkost);
int kontrola_volby(char volba);
int pokracovanie();

int maximum_pola(int cisla[], int velkost);
int minimum_pola(int cisla[], int velkost);
int priemer_pola(int cisla[], int velkost);
int sucet_pola(int cisla[], int velkost);

int main() {
	int cisla[VELKOST_POLA];
	
	nacitanie_pola(cisla, VELKOST_POLA);
	
	moznosti(cisla, VELKOST_POLA);
	
	printf("\n\n######     Dovidenia!     ######");
	
	return 0;
}

void nacitanie_pola(int cisla[], int velkost){
	int cislo;
	int i;
	
	for(i = 0; i < velkost; i++){
		printf("Zadaj %d. hodnotu v poli: ", i + 1);
		scanf("%d", (cisla + i));
	}
}

void moznosti(int cisla[], int velkost){
	char volba;
	
	do{
		printf("\nPre zistenie maxima v poli stlac m/M\n");
		printf("Pre zistenie minima v poli stlac n/N\n");
		printf("Pre zistenie priemeru cisel v poli stlac p/P\n");
		printf("Pre zistenie suctu cisel v poli stlac s/S\n");
		
		do{
			printf("\nTvoja volba: ");
			getchar();
			volba = getchar();
		}while(kontrola_volby(volba) == TRUE);
		
		switch(volba){
			case 'm':
			case 'M':
				printf("\nMaximum v poli je: %d\n", maximum_pola(cisla, velkost));
				break;
				
			case 'n':
			case 'N':
				printf("\nMinimum v poli je: %d\n", minimum_pola(cisla, velkost));
				break;
			
			case 'p':
			case 'P':
				printf("\nPriemer v poli je: %d\n", priemer_pola(cisla, velkost));
				break;
				
			case 's':
			case 'S':
				printf("\nSucet v poli je: %d\n", sucet_pola(cisla, velkost));
				break;
		}	
	}while(pokracovanie() == TRUE);
	
}

int kontrola_volby(char volba){
	if(volba == 'm' || volba == 'M' || volba == 'n' || volba == 'N' || volba == 'p' || volba == 'P' || volba == 's' || volba == 'S'){
		return FALSE;
	}else{
		printf("\nZle zadany znak!\nOpakuje zadanie znaku!\n\n");
	}
	
	return TRUE;
}

int pokracovanie(){
	char volba;
	printf("\nChces pokracovat ? Yes(y/Y)		No(n/N)\n");
	
	do{
		printf("Tvoja volba: ");
		getchar();
		volba = getchar();
		if(volba != 'y' && volba != 'Y' && volba != 'n' && volba != 'N') printf("\nZle zadany znak!\nOpakuje zadanie znaku!\n\n");	
	}while(volba != 'y' && volba != 'Y' && volba != 'n' && volba != 'N');
	
	if(volba == 'y' || volba == 'Y'){
		return TRUE;
	}else{
		return FALSE;
	}
}

int maximum_pola(int cisla[], int velkost){
	int i = 0;
	int max = *cisla;
	
	for(i = 1; i < velkost; i++){
		if(max < *(cisla + i)) max = *(cisla + i);
	}
	
	return max;
}

int minimum_pola(int cisla[], int velkost){
	int i = 0;
	int min = *cisla;
	
	for(i = 1; i < velkost; i++){
		if(min > *(cisla + i)) min = *(cisla + i);
	}
	
	return min;
}

int priemer_pola(int cisla[], int velkost){
	return sucet_pola(cisla, velkost) / velkost;
}

int sucet_pola(int cisla[], int velkost){
	int sucet = 0;
	int i;
	
	for(i = 0; i < velkost; i++){
		sucet += *(cisla + i);
	}
	
	return sucet;
}



