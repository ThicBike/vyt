#include <stdio.h>

/*
Uloha 8 - Mocnina cisla
Tibor Pelegrin
2.A 2.sk.
*/

//deklaracia funkcii pre nacitanie hodnoty zakladu a exponentu
float nacitanie_zakladu();
int nacitanie_exponentu();

//deklaracia funkcie pre vypocet mocniny
float vypocet_mocniny(float zaklad, int exponent);

void main(){
	//lokalne premenne ktore maju hodnotu z volanych funkcii pre nacitanie hodnot zakladu a exponentu
	float zaklad = nacitanie_zakladu();
	int exponent = nacitanie_exponentu();
	
	//vypis vypoctu
	printf("%.3f na %d = %.3f", zaklad, exponent, vypocet_mocniny(zaklad, exponent));
}

//definicia funkcie pre nacitanie zakladu
float nacitanie_zakladu(){
	//lokalna premenna
	float zaklad;
	
	//nacitanie zakladu
	printf("Zadaj hodnotu zakladu: ");
	scanf("%f", &zaklad);
	
	return zaklad;
}

//definicia funkcie pre nacitanie exponentu
int nacitanie_exponentu(){
	//lokalna premenna
	int exponent;
	
	//nacitanie kladneho exponentu
	do{
		printf("Zadaj hodnotu exponentu: ");
		scanf("%d", &exponent);
	}while(exponent < 0);
	
	return exponent;
}

//definicia funkcie pre vypocet mocniny
float vypocet_mocniny(float zaklad, int exponent){
	//lokalne premenne
	float vysledok = 1;
	int i;
	
	//cyklus pre vypocet mocniny
	for(i = 1; i <= exponent; i++){
		vysledok = vysledok * zaklad;
	}
	
	return vysledok;
}
