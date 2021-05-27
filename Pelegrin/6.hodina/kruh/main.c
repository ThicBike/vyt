#include <stdio.h>
#include <stdlib.h>

void hlavicka(FILE *fw);
void paticka(FILE *fw);

int cyrcle(int r);

int main(){
	FILE *fw = fopen("svg.html", "w");
	
	
	if(fw != NULL){
		
		
		int polomer;
		
		do{
			printf("Zadaj polomer : ");
			scanf("%d", &polomer);
			if(polomer <= 0) printf("Zadaj vacsi polomer!\n");
		}while(polomer <= 0);
		
		hlavicka(fw);
		
		//for(i = )
		
		paticka(fw);
	}
	return 0;
}

void hlavicka(FILE *fw){
	fprintf(fw, "<DOCTYPE HTML>\n");
	fprintf(fw, "<html>\n");
	fprintf(fw, "<head>\n");
	fprintf(fw, "\t<svg width=\"300\" height=\"300\">\n");
	fprintf(fw, "\t\t<g fill=\"none\" stroke-width=\"2\" stroke=\"green\">\n");
}

int cyrcle(int polomer){
	
	
	//if( polomer == 0) ;
	if( polomer > 0) polomer = cyrcle(polomer - 10);
	return polomer;
}

void paticka(FILE *fw){
	fprintf(fw, "\t\t</g>\n");
	fprintf(fw, "\t</svg>\n");
	fprintf(fw, "\t</body>\n");
	fprintf(fw, "</html>\n");
}
