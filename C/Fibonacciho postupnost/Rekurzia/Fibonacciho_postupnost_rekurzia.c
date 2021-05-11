//==========================//
//		Tibor Pelegrin		//
//			3.A 2.sk		//
//	Fibonacciho postupnost  //
//         Rekurzia         //
//==========================//

#include <stdio.h>
#include <stdlib.h>

int fibonacciho_cislo(int cislo);
int nacitanie_cisla();
void vypis(int cislo, FILE *fw);

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
	
	printf("\nHotovo! Navstiv subor %s.", vystup);
	
	fclose(fr);	
	fclose(fw);
	
	return 0;
}

int fibonacciho_cislo(int n){
	
	if(n < 2){
		return n;
	}else{
		return fibonacciho_cislo(n - 1) + fibonacciho_cislo(n - 2);
	}
}

void vypis(int cislo, FILE *fw){
	int i;
	
	fprintf(fw, "F %d = %d\n", cislo, fibonacciho_cislo(cislo));
	fprintf(fw, "Fibonacciho postupnost %d = ", cislo);
	
	for(i = 0; i <= cislo; i++){
		fprintf(fw, "%d ", fibonacciho_cislo(i));
	}
}

int nacitanie_cisla(){
	int cislo;
	do{
		printf("Zadaj kladne cislo: ");
		scanf("%d", &cislo);
		if(cislo < 0) printf("Cislo musi byt kladne!\nOpakuj zadanie cisla!\n");
	}while(cislo < 0);
		
	return cislo;	
}
