#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct bod{
		int surX;
		int surY;
		int vz;
		char meno;
} prvy_bod, druhy_bod, stred;

struct platno_rozmer{
	int sirka;
	int vyska;
} platno;

void hlavicka(FILE *fw);
void vykreslenie_bodov(struct bod a, FILE *fw);
void paticka(FILE *fw);

struct platno_rozmer nacitanie_platna(struct platno_rozmer a);
struct bod nacitanie_suradnic(struct bod a);
void suradnice_stredu();

int vzdialenost_od_zaciatku(struct bod a);

int main(int argc, char *argv[]) {
	FILE *fw;
	
	char vystup[100];
	
	prvy_bod.meno = 'A';
	druhy_bod.meno = 'B';
	
	do{
		printf("Zadaj vystupny subor: ");
		scanf("%s", vystup);
		
		fw = fopen(vystup, "w");
		if(fw == NULL) printf("Subor sa nenasiel!\n");
	}while(fw == NULL);
	
	
	platno = nacitanie_platna(platno);
	
	prvy_bod = nacitanie_suradnic(prvy_bod);
	druhy_bod = nacitanie_suradnic(druhy_bod);
	
	
	prvy_bod.vz = vzdialenost_od_zaciatku(prvy_bod);
	druhy_bod.vz = vzdialenost_od_zaciatku(druhy_bod);
	
	suradnice_stredu();
	
	hlavicka(fw);
	
	vykreslenie_bodov(prvy_bod, fw);
	vykreslenie_bodov(druhy_bod, fw);
	vykreslenie_bodov(stred, fw);
	
	paticka(fw);
	
	
	printf("\nSuradnice 1. bodu: x = %d y = %d", prvy_bod.surX, prvy_bod.surY);
	printf("\nSuradnice 2. bodu: x = %d y = %d", druhy_bod.surX, druhy_bod.surY);
	printf("\n\nSuradnice stredneho bodu = %d %d", stred.surX, stred.surY);
	printf("\n\nVzdialenost od zaciatku 1. bodu: %d", prvy_bod.vz);
	printf("\nVzdialenost od zaciatku 2. bodu:%d", druhy_bod.vz);
	
	
	return 0;
}

void vykreslenie_bodov(struct bod a, FILE *fw){
	fprintf(fw, "<circle cx=\"%d\" cy=\"%d\" r=\"4\" stroke=\"blue\" stroke-width=\"1\" fill=\"red\" />", a.surX, a.surY);
}

void suradnice_stredu(){

	stred.surX = (prvy_bod.surX + druhy_bod.surX) / 2;
	stred.surY = (prvy_bod.surY + druhy_bod.surY) / 2;
} 


int vzdialenost_od_zaciatku(struct bod a){
	
	return sqrt(pow(a.surX, 2) + pow(a.surY, 2));
}

struct platno_rozmer nacitanie_platna(struct platno_rozmer a){
	
	do{
		printf("\nZadaj sirku platna: ");
		scanf("%d", &a.sirka);
		if(a.sirka < 0) printf("\nHodnota musi byt kladna!\n");
	}while(a.sirka < 0);
	
	do{
		printf("Zadaj vysku platna: ");
		scanf("%d", &a.vyska);
		if(a.vyska < 0) printf("\nHodnota musi byt kladna!\n");
	}while(a.vyska < 0);
	
	return a;
}

struct bod nacitanie_suradnic(struct bod a){
	
	do{
		printf("\nZadaj x-ovu suradnicu bodu %c: ", a.meno);
		scanf("%d", &a.surX);
		if(a.surX < 0 || a.surX > platno.sirka) printf("\nHodnota musi byt kladna a zaroven mensia ako sirka platna\n");
	}while(a.surX < 0 || a.surX > platno.sirka);
	
	do{
		printf("Zadaj y-ovu suradnicu bodu %c: ", a.meno);
		scanf("%d", &a.surY);
		if(a.surY < 0 || a.surY > platno.vyska) printf("\nHodnota musi byt kladna a zaroven mensia ako vyska platna!\n");
	}while(a.surY < 0 || a.surY > platno.vyska);
	
	return a;
}

void hlavicka(FILE *fw){
	fprintf(fw, "<DOCTYPE html>\n");
	fprintf(fw, "<html>\n");
	fprintf(fw, "<body>\n");
	fprintf(fw, "	<svg style={background-color:yellow} height=\"%d\" width=\"%d\">\n", platno.vyska, platno.sirka);
}

void paticka(FILE *fw){
	fprintf(fw, "	</svg>\n");
	fprintf(fw, "</body>\n");
	fprintf(fw, "</html>\n");
}






