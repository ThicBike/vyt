#include <stdio.h>
#include <math.h>

/*
Uloha 8 - Mocnina cisla
Tibor Pelegrin
2.A 2.sk.
*/


float nacitanie_zakladu();
int nacitanie_exponentu();
float vypocet_mocniny(float zaklad, int exponent);

void main(){
	float zaklad = nacitanie_zakladu();
	int exponent = nacitanie_exponentu();
	
	printf("%.3f na %.3d = %.3f", zaklad, exponent, vypocet_macniny(zaklad, exponent));
}

float nacitanie_zakladu(){
	float zaklad;
	
	printf("Zadaj hodnotu zakladu: ");
	scanf("%f", &zaklad);
	
	return zaklad;
}

int nacitanie_exponentu(){
	int exponent;
	
	do{
		printf("Zadaj hodnotu exponentu: ");
		scanf("%d", &exponent);
	}while(exponent <= 0);
	
	return exponent;
}

float vypocet_mocniny(float zaklad, int exponent){
	float vysledok = 1;
	int i;
	
	for(i = 1; i <= exponent; i++){
		vysledok = vysledok * zaklad;
	}
	
	return vysledok;
}
