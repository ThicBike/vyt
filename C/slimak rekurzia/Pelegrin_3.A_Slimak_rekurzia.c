//==========================//
//		Tibor Pelegrin		//
//			3.A 2.sk		//
//	         Slimak         //
//          Rekurzia        //
//==========================//

#include <stdio.h>
#include <stdlib.h>

void hlavicka(FILE *fw, int platno);
void paticka(FILE *fw);

int nacitanie_platna();
int nacitanie_rozmeru_slimaka(int platno);
int nacitanie_zvacsovania();

void slimak(int rozmer, FILE *fw, int x1, int y1, int x2, int y2, int n, int zvacsenie);

int main(){
	FILE *fw;
	
	char vystup[50];
	
	do{
		printf("Zadaj vystupny subor: ");
		scanf("%s", &vystup);
		fw = fopen(vystup, "w");
		if(fw == NULL) printf("Subor sa nevytvoril!\n");
	}while(fw == NULL);
	
	int platno = nacitanie_platna();
	int zvacsenie = nacitanie_zvacsovania(platno);
	hlavicka(fw, platno);
	
	slimak(nacitanie_rozmeru_slimaka(platno), fw, platno / 2, platno / 2, platno / 2, platno / 2, zvacsenie, zvacsenie);

	paticka(fw);

	printf("\nSlimak dosiel do ciela!\nNavstiv %s", vystup);
	
	return 0;
}

void hlavicka(FILE *fw, int platno){
	fprintf(fw, "<DOCTYPE html>\n");
	fprintf(fw, "<html>\n");
	fprintf(fw, "<body>\n");
	fprintf(fw, "	<svg height=\"%d\" width=\"%d\">\n", platno, platno);
}

int nacitanie_platna(){
	int rozmer;
	
	do{
		printf("Zadaj stranu stvorcoveho platna : ");
		scanf("%d", &rozmer);
		if(rozmer <= 0) printf("Rozmer platna musi byt kladny!\nOpakuj nacitanie strany platna!\n");
	}while(rozmer <= 0);
	
	return rozmer;
}

void paticka(FILE *fw){
	fprintf(fw, "	</svg>\n");
	fprintf(fw, "</body>\n");
	fprintf(fw, "</html>\n");
}

int nacitanie_rozmeru_slimaka(int platno){
	int rozmer;
	
	do{
		printf("Zadaj dlzku slimaka : ");
		scanf("%d", &rozmer);
		if(rozmer <= 0) printf("Dlzka slimaka musi byt kladna!\nOpakuj nacitanie dlzky slimaka!\n");
		if(rozmer > platno) printf("Slimak sa nezmesti na platno!\nOpakuj nacitanie dlzky slimaka!\n");
	}while(rozmer < 0 || rozmer > platno);
	
	return rozmer;
}

int nacitanie_zvacsovania(){
	int zvacsovanie;
	
	do{
		printf("Zadaj zvacsovanie slimaka : ");
		scanf("%d", &zvacsovanie);
		if(zvacsovanie <= 0) printf("Zvacsovanie musi byt kladne!\nOpakuj nacitanie zvacsovania slimaka!\n");
	}while(zvacsovanie <= 0);
	
	return zvacsovanie;
}

void slimak(int rozmer, FILE *fw, int x1, int y1, int x2, int y2, int n, int zvacsenie){
	if(n <= rozmer){
			x2 = x2 + n;
			fprintf(fw, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:#6C733D;stroke-width:4\" /></line>", x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
			y2 = y2 + n;
			
			fprintf(fw, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:#9DA65D;stroke-width:2\" /></line>", x1, y1, x2, y2);
			n += zvacsenie;
			x1 = x2;
			y1 = y2;
			x2 = x2 - n;	
			
			fprintf(fw, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:#6C733D;stroke-width:4\" /></line>", x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
			y2 = y2 - n;
			
			fprintf(fw, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:#9DA65D;stroke-width:2\" /></line>", x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;

		slimak(rozmer, fw, x1, y1, x2, y2, n + zvacsenie, zvacsenie);
	} 
}











