#include <stdio.h>
#include <stdlib.h>

const int TRUE = 1;
const int FALSE = 0;
const int ZMENA = 'a' - 'A';

int main(){
	FILE *fr = fopen("basnicka.txt", "r");
	FILE *fw = fopen("zaloha.txt", "w");
	char znak;
	int i;
	
	if(fr != NULL){
	 
		if(fw != NULL){
		
		
		while((znak = fgetc(fr)) != EOF){
			if((znak >= 'a' && znak <= 'z')){
				znak = znak - ZMENA;
			}else if(znak >= 'A' && znak <= 'Z'){
				znak = znak + ZMENA;
			}
		}
		
		fprintf(fw, "%c", znak);
		
		}else{
			printf("Subor sa nevytvoril");
		}
		
		
	}else{
		printf("Subor sa nenasiel alebo sa nevytvoril");
	}
	
	
}


