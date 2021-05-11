#include <stdio.h>
#include <stdlib.h>

void hlavicka(FILE *fw, int platno);
void paticka(FILE *fw);

int nacitanie_platna();
int nacitanie_rozmeru_stvorca(int platno);

int stvorec(int rozmer, FILE *fw, int x, int y, int predosly_rozmer);
void kreslenie(int rozmer, FILE *fw, int x, int y);


int main(){
	FILE *fw = fopen("stvorec.html", "w");
	
	if(fw != NULL){
		int platno = nacitanie_platna();
		int rozmer = nacitanie_rozmeru_stvorca(platno);
		hlavicka(fw, platno);
		
		kreslenie(rozmer, fw, 0, 0);
		stvorec(rozmer / 3, fw, rozmer / 9, rozmer / 9, rozmer / 3);
		

		paticka(fw);
	}
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

int nacitanie_rozmeru_stvorca(int platno){
	int rozmer;
	
	do{
		printf("Zadaj stranu stvorca : ");
		scanf("%d", &rozmer);
		if(rozmer <= 0) printf("Strana stvorca musi byt kladna!\nOpakuj nacitanie strany stvorca!\n");
		if(rozmer > platno) printf("Stvorec sa nezmesti na platno!\nOpakuj nacitanie strany stvorca!\n");
	}while(rozmer <= 0 && rozmer > platno);
	
	return rozmer;
}

int stvorec(int rozmer, FILE *fw, int x, int y, int predosly_rozmer){
	int i, j;
	
	if(rozmer / 3 >= 1){
		predosly_rozmer = rozmer / 3;
		rozmer = rozmer / 3;
		for(i = 0; i < 3; i++){
			y = i * predosly_rozmer + rozmer;
			for(j = 0; j < 3; j++){
				x = j * predosly_rozmer + rozmer;
				if(i != 1 || j != 1){ 
					fprintf(fw, "<rect width=\"%d\" height=\"%d\" x=\"%d\" y=\"%d\" style=\"fill:rgb(255, 255, 255);stroke:rgb(0,0,0)\" />\n", rozmer , rozmer , x, y);	
					stvorec(rozmer, fw, x, y, predosly_rozmer);
				}		
			}	
		}
					
	}

	return rozmer;
}

void kreslenie(int rozmer, FILE *fw, int x, int y){
	fprintf(fw, "<rect width=\"%d\" height=\"%d\" x=\"%d\" y=\"%d\" style=\"fill:rgb(255, 255, 255);stroke:rgb(0,0,0)\" />\n", rozmer, rozmer, x, y);
	fprintf(fw, "<rect width=\"%d\" height=\"%d\" x=\"%d\" y=\"%d\" style=\"fill:rgb(255, 255, 255);stroke:rgb(0,0,0)\" />\n", rozmer / 3, rozmer / 3, rozmer / 3, rozmer / 3);
	
}









