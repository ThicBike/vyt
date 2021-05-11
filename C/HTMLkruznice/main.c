#include <stdio.h>
#include <stdlib.h>

void hlavicka(FILE *fw, int vyska, int sirka);
void paticka(FILE *fw);

int nacitanie_platna(char v_s);
int nacitanie_polomeru(int vyska, int sirka);

int kruznica(int polomer, FILE *fw, int vyska, int sirka);



int main(){
	FILE *fw = fopen("kruznica.html", "w");
	
	if(fw != NULL){
		int vyskaP = nacitanie_platna('v');
		int sirkaP = nacitanie_platna('s');
		
		hlavicka(fw, vyskaP, sirkaP);
		
		kruznica(nacitanie_polomeru(vyskaP, sirkaP), fw, vyskaP, sirkaP);

		paticka(fw);
	}
	return 0;
}

void hlavicka(FILE *fw, int vyska, int sirka){
	fprintf(fw, "<DOCTYPE html>\n");
	fprintf(fw, "<html>\n");
	fprintf(fw, "<body>\n");
	fprintf(fw, "	<svg height=\"%d\" width=\"%d\">\n", vyska, sirka);
}

int nacitanie_platna(char v_s){
	int hodnota;
	if(v_s == 'v'){
		do{
			printf("Zadaj vysku platna : ");
			scanf("%d", &hodnota);
			if(hodnota <= 0) printf("Vyska musi byt kladna!\nOpakuj zadanie vysky!\n");
		}while(hodnota <= 0);
	}
	
	if(v_s == 's'){
		do{
			printf("Zadaj sirku platna : ");
			scanf("%d", &hodnota);
			if(hodnota <= 0) printf("Sirka musi byt kladna!\nOpakuj zadanie sirky!\n");
		}while(hodnota <= 0);
	}
	
	return hodnota;
}

void paticka(FILE *fw){
	fprintf(fw, "	</svg>\n");
	fprintf(fw, "</body>\n");
	fprintf(fw, "</html>\n");
}

int nacitanie_polomeru(int vyska, int sirka){
	int polomer;
	
	do{
		printf("Zadaj polomer kruznice : ");
		scanf("%d", &polomer);
		if(polomer <= 0) printf("Polomer musi byt kladny!\nOpakuj zadanie polomeru!\n");
		if(polomer * 2 > vyska || polomer * 2 > sirka) printf("Polomer je prilis velky, kruznica sa nezmesti na platno!\n");
	}while(polomer <= 0 || polomer * 2 > vyska || polomer * 2 > sirka);
	
	return polomer;
}

int kruznica(int polomer, FILE *fw, int vyska, int sirka){
	
	if(polomer >= 10){
		fprintf(fw, "			<circle cx=\"%d\" cy=\"%d\" r=%d fill=\"none\" stroke-width= \"2\" stroke=\"green\" />\n", sirka / 2, vyska / 2, polomer);
		kruznica(polomer - 10, fw, vyska, sirka);
	}
	
	//return polomer;
}






