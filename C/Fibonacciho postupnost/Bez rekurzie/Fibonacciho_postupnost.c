//==========================//
//		Tibor Pelegrin		//
//			3.A 2.sk		//
//	Fibonacciho postupnost	//
//==========================//

#include <stdio.h>
#include <stdlib.h>

int fibonacciho_cislo(int cislo);
void vypis(int cislo, FILE *fw);
int nacitanie_cisla();

int main() {
	
	FILE *fr;
	FILE *fw;
	
	char vstup[50], vystup[50];
	int cislo;
	
	do{
		printf("Zadaj vstupny subor: ");
		scanf("%s", &vstup);
		fr = fopen(vstup, "r");
		if(fr == NULL) printf("Subor sa nenasiel!\n");
	}while(fr == NULL);
	
	do{
		printf("Zadaj vystupny subor: ");
		scanf("%s", &vystup);
		fw = fopen(vystup, "w");
		if(fw == NULL) printf("Subor sa nevytvoril!\n");
	}while(fw == NULL);
	
	
	fscanf(fr, "%d", &cislo);
	
	if(cislo < 0){
		printf("Cislo musi byt kladne!\nOtvor fibonacciho_cislo.txt!");
		
		return 0;
	} 
	
	vypis(cislo, fw);
	
	fclose(fr);
	fclose(fw);
	
	return 0;
}

void vypis(int cislo, FILE *fw){
	int i;
	
	fprintf(fw, "F %d = %d\n", cislo, fibonacciho_cislo(cislo));
	fprintf(fw, "Fibonacciho postupnost = ");
	
	for(i = 0; i <= cislo; i++){
		fprintf(fw, "%d ", fibonacciho_cislo(i));
	}
}


int fibonacciho_cislo(int cislo){
	int cislo1 = 0, cislo2 = 1, x, fibonacciho_cislo;
	int i;
	
	if(cislo <= 1){
		return cislo;
	}else{
		for(i = 1; i < cislo; i++){
		
		fibonacciho_cislo = cislo1 + cislo2;
		
		x = cislo2;
		cislo2 += cislo1;
		cislo1 = x;
		}
	}
	
	return fibonacciho_cislo;
}

/*
int nacitanie_cisla(){
	int cislo;
	
	do{
		printf("Zadaj kladne cislo: ");
		scanf("%d", &cislo);
		if(cislo < 0) printf("Cislo musi byt kladne!\nOpakuj zadanie cisla!\n");
	}while(cislo < 0);
		
	return cislo;	
}
*/
