#include <stdio.h>
#include <stdlib.h>

int main() {
	char znak, znakx;
	int pocet_riadkov = 0;
	int	pocet_medzier = 0;
	int	pocet_tabelatorov = 0;
	int pocet_znakov = 0;
	int pocet_slov = 0;
	
	FILE *fr = fopen("riekanka.txt", "r");
	
	if(fr != NULL){
		while((znak = fgetc(fr)) != EOF){
			switch(znak){
				case '\n' :
					pocet_riadkov++;
					break;
				case ' ' :
					pocet_medzier++;
					break;
				case '\t' :
					pocet_tabelatorov++;
					break;
				default :
					if((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')) pocet_znakov++;		
			}	
		}
		printf("Pocet riadkov : %d\nPocet medzier : %d\nPocet tabelatorov : %d\nPocet znakov : %d\n", pocet_riadkov, pocet_medzier, pocet_tabelatorov, pocet_znakov);	
	}else{
		printf("Subor sa nenasiel!");
	}
	fclose(fr);
	return 0;
}
