#include <stdio.h>
#include <stdlib.h>



int main() {
	FILE *fr = fopen("cisla.txt", "r");
	FILE *fw = fopen("parne.txt", "w");
	
	
	char znak;
	int pole[6];
	int i = 0, sucet_prvkov = 0;
	
	if(fr != NULL){
		if(fw != NULL){
			
			while(feof(fr) == 0){
				fscanf(fr, "%d", &pole[i]);
				sucet_prvkov += pole[i];
				i++;	
			}
			
			for(i = 0; i < 6; i++){
				if(pole[i] % 2 == 0){
					fprintf(fw, "%d", pole[i]);
				}
			}
			
			fprintf(fw, "\n%d", sucet_prvkov);
		}
	}
	
	fclose(fr);
	fclose(fw);
	
	
	return 0;
}
