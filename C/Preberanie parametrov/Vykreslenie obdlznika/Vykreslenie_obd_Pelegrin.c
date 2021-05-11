#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vykreslenie_obdlznika(int sirka, int vyska, char *nazov_suboru);
void nacitanie_argumentov(int *sirka, int *vyska);

int kontrola_kladnosti(int *hodnota);

int main(int argc, char *argv[]) {
	FILE *fw;
	
	int sirka, vyska;
	char vystup[50];
	
	if(argc == 4 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0){
		sirka = atoi(argv[1]);
		vyska = atoi(argv[2]);
		*vystup = *argv[3];
	}else{
		printf("Zle zadane argumenty!\nZadaj argumenty este raz!\n");
		
		nacitanie_argumentov(&sirka, &vyska);
		
		printf("Zadaj vystupny subor: ");
		scanf("%s", vystup);
	}
	
	printf("\nSirka je: %d", sirka);
	printf("\nVyska je: %d", vyska);
	printf("\nNavstiv subor: %s", vystup);
	
	vykreslenie_obdlznika(sirka, vyska, vystup);
	
	return 0;
}

void nacitanie_argumentov(int *sirka, int *vyska){
	do{
		printf("\nZadaj sirku: ");
		scanf("%d", sirka);
		
		if(kontrola_kladnosti(sirka)) printf("\nHodnota musi byt kladna!\nOpakuje nacitanie!\n");
	}while(kontrola_kladnosti(sirka));
	
	do{
		printf("Zadaj vysku: ");
		scanf("%d", vyska);
		
		if(kontrola_kladnosti(vyska)) printf("\nHodnota musi byt kladna!\nOpakuje nacitanie!\n");
	}while(kontrola_kladnosti(vyska));
	
}

int kontrola_kladnosti(int *hodnota){
	if(*hodnota <= 0){
		return 1;
	}else{
		return 0;
	}
}

void vykreslenie_obdlznika(int sirka, int vyska, char *nazov_suboru){
	FILE *fw = fopen(nazov_suboru, "w");
	int i, j;
	
	if(fw == NULL){
		printf("Subor sa nevytvoril :(");
	}else{
		for(i = 1; i <= vyska; i++){
			for(j = 1; j <= sirka; j++){
				if(i == 1 || i == vyska || j == 1 || j == sirka){
					fprintf(fw, "*");
				}else {
					fprintf(fw, " ");
				}
			}
			fprintf(fw, "\n");
		}
	}
	
	fclose(fw);
}




