#include <stdio.h>
#include <stdlib.h>

const int TRUE = 1;
const int FALSE = 0;

void bodovanie(int body){
	int i;
	for(i = 1; i <= body; i++){
		printf("*");
	}
}
	
void tabulka(int riadky, int medzery, int tab){
	int i;
	int max = maximum(riadky, medzery, tab);
	
	for(i = max; i >= 1; i--){
		if(riadky >= i){
			printf("	*	");
		}else{
			printf("	 	");
		}
		
		if(medzery >= i){
			printf("	*	");
		}else{
			printf("	 	");
		}
		
		if(tab >= i){
			printf("	*	");
		}else{
			printf("	 	");
		}
		printf("\n");
	}
	
	printf("      Riadky         Medzery         Tabulatory");
}

maximum(int riadky, int medzery, int tab){
	int max = riadky;
	if(max < medzery) max = medzery;
	if(max < tab) max = tab;
	return max;
}

int main() {
	char znak;
	int pocet_riadkov = 0;
	int pocet_medzier = 0;
	int pocet_tabelatorov = 0;
	int pocet_znakov = 0;
	int pocet_slov = 0;
	int somdnu = FALSE;
	
	FILE *fr = fopen("riekanka.txt", "r");
	
	if(fr != NULL){
		while((znak = fgetc(fr)) != EOF){
			putchar(znak);
			
			switch(znak){
				case '\n' :
					pocet_riadkov++;
					somdnu = FALSE;
					break;
				case ' ' :
					pocet_medzier++;
					somdnu = FALSE;
					break;
				case '\t' :
					pocet_tabelatorov++;
					somdnu = FALSE;
					break;
				default :
					if((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')) pocet_znakov++;
					somdnu = TRUE;								
			}
				if(somdnu == FALSE){
					pocet_slov++;
					somdnu = TRUE;
				} 
				
		}	
		
		fclose(fr);
		
		//printf("Pocet riadkov : %d\nPocet medzier : %d\nPocet tabelatorov : %d\nPocet znakov : %d\nPocet slov : %d", pocet_riadkov, pocet_medzier, pocet_tabelatorov, pocet_znakov, pocet_slov);	
		printf("\nRiadky  ");
		bodovanie(pocet_riadkov);
		printf("\nMedzery ");
		bodovanie(pocet_medzier);
		printf("\nTab     ");
		bodovanie(pocet_tabelatorov);
		printf("\nZnaky   ");
		bodovanie(pocet_znakov);
		printf("\nSlova   ");
		bodovanie(pocet_slov);
		printf("\n");
		tabulka(pocet_riadkov, pocet_medzier, pocet_tabelatorov);
	}else{
		printf("Subor sa nenasiel!");
	}
	
	return 0;
}
