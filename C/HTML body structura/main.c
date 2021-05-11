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

void hlavicka(FILE *fw);                                                   //deklaracia funkcie na vypis hlavicky v html subore
void vykreslenie_bodov(struct bod a, FILE *fw);                            //deklaracia funkcie na vykreslenie bodov do html suboru
void vypis_nazvu_bodov(FILE *fw, struct bod a);                            //deklaracia funkcie na vypis nazvu bodov do html suboru
void paticka(FILE *fw);                                                    //deklaracia funkcie na vypis paticky v html subore

struct platno_rozmer nacitanie_rozmerov_platna(struct platno_rozmer a);    //deklaracia funkcie na nacitanie rozmerov platna
struct bod nacitanie_suradnic(struct bod a);                               //deklaracia funkcie na nacitanie suradnic bodov
struct bod suradnice_stredu(struct bod a, struct bod b);                   //deklaracia funkcie na zistenie sradnic stredneho bodu

void vypis();                                                              //deklaracia funkcie na vypis informacii

int vzdialenost_dvoch_bodov(struct bod a, struct bod b);
int vzdialenost_od_zaciatku(struct bod a);                                 //deklaracia funkcie na vypocet vzdialenosti bodu od zaciatku

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
	
	
	platno = nacitanie_rozmerov_platna(platno);
	
	prvy_bod = nacitanie_suradnic(prvy_bod);
	druhy_bod = nacitanie_suradnic(druhy_bod);
	
	
	prvy_bod.vz = vzdialenost_od_zaciatku(prvy_bod);
	druhy_bod.vz = vzdialenost_od_zaciatku(druhy_bod);
	
	stred = suradnice_stredu(prvy_bod, druhy_bod);
	
	hlavicka(fw);
	
	vykreslenie_bodov(prvy_bod, fw);
	vykreslenie_bodov(druhy_bod, fw);
	vykreslenie_bodov(stred, fw);
	vypis_nazvu_bodov(fw, prvy_bod);
	vypis_nazvu_bodov(fw, druhy_bod);
	vypis_nazvu_bodov(fw, stred);
	
	paticka(fw);
	
	vypis();
	
	printf("\n\n#### Navstiv subor %s #####", vystup);
	
	return 0;
}

void vykreslenie_bodov(struct bod a, FILE *fw){
	fprintf(fw, "\t\t<circle cx=\"%d\" cy=\"%d\" r=\"4\" stroke=\"blue\" stroke-width=\"1\" fill=\"red\" />\n", a.surX, a.surY);
}

void vypis_nazvu_bodov(FILE *fw, struct bod a){
	fprintf(fw, "\t\t<h4 style=\"margin:0;position:absolute;left:%d;top:%d;\">%c(%d, %d)</h4>\n",a.surX + 20, a.surY, a.meno, a.surX, a.surY);
}

struct bod suradnice_stredu(struct bod a, struct bod b){
	struct bod s;
	
	s.surX = (a.surX + b.surX) / 2;
	s.surY = (a.surY + b.surY) / 2;
	s.meno = 'S';
	
	return s;
} 

int vzdialenost_dvoch_bodov(struct bod a, struct bod b){
	return sqrt(pow((a.surX - b.surX), 2) + pow((a.surY - b.surY), 2));
}

int vzdialenost_od_zaciatku(struct bod a){
	
	return sqrt(pow(a.surX, 2) + pow(a.surY, 2));
}

struct platno_rozmer nacitanie_rozmerov_platna(struct platno_rozmer a){
	
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

void vypis(){
	printf("\nSuradnice 1. bodu: x = %d y = %d", prvy_bod.surX, prvy_bod.surY);
	printf("\nSuradnice 2. bodu: x = %d y = %d", druhy_bod.surX, druhy_bod.surY);
	printf("\nVzdialenost dvoch bodov: %d", vzdialenost_dvoch_bodov(prvy_bod, druhy_bod));
	printf("\n\nSuradnice stredneho bodu = %d %d", stred.surX, stred.surY);
	printf("\n\nVzdialenost od zaciatku 1. bodu: %d", prvy_bod.vz);
	printf("\nVzdialenost od zaciatku 2. bodu: %d", druhy_bod.vz);
}

void hlavicka(FILE *fw){
	fprintf(fw, "<DOCTYPE html>\n");
	fprintf(fw, "<html>\n");
	fprintf(fw, "<body>\n");
	fprintf(fw, "	<svg style=\"border:1px solid black;\" height=\"%d\" width=\"%d\">\n", platno.vyska, platno.sirka);
}

void paticka(FILE *fw){
	fprintf(fw, "	</svg>\n");
	fprintf(fw, "</body>\n");
	fprintf(fw, "</html>\n");
}






