#include <stdio.h>
#include <math.h>

/*
Uloha 5 - Valec
Tibor Pelegrin
2.A 2.sk
*/

//deklaracia funkcii pre podstavu/kruh
float obsah_podstavy(float polomer);
float obvod_podstavy(float polomer);

//deklaracia funkcie pre plast valca/obsah obdlznika
float obsah_plasta(float polomer, float vyska);

//deklaracia funkcie pre objem a povrch valca
float objem_valca(float polomer, float vyska);
float povrch_valca(float polomer, float vyska);

//deklaracia funkcie pre nacitanie a kontrolu rozmerov
float nacitanie_rozmerov(char nazov_rozmeru);
int kontrola_rozmeru(float rozmer);

//deklaracia funkcie pre vypis vyslednych hodnot
void vypis_hodnot(float polomer, float vyska);

//deklaracia konstatny pre hodnotu PI
const float PI = 3.14;

void main(){
	printf("VALEC\n");
	
	//volaie funkcie pre vypis hodnot ktora bude obsahovat hodnoty z funkcii pre nacitanie rozmerov
	vypis_hodnot(nacitanie_rozmerov('r'), nacitanie_rozmerov('v'));
}

//definicia funkcie pre nacitanie rozmerov
float nacitanie_rozmerov(char nazov_rozmeru){
	//lokalna premenna
	float hodnota;
	
	if(nazov_rozmeru == 'r'){
		do{
			printf("Zadaj polomer r : ");
			scanf("%f", &hodnota);	
		}while(kontrola_rozmeru(hodnota)); //volanie funkcie pre kontrolu rozmeru
		return hodnota;
	}
	
	if(nazov_rozmeru == 'v'){
		do{
			printf("Zadaj vysku v : ");
			scanf("%f", &hodnota);
		}while(kontrola_rozmeru(hodnota)); //volanie funkcie pre kontrolu rozmeru
		return hodnota;
	}
}

//definicia funkcie pre kontrolu rozmeru
int kontrola_rozmeru(float rozmer){
	if(rozmer > 0){
		return 0;
	}else{
		printf("Cislo nie je kladne!\n");
		return 1;
	}
}

//definicia funkcii pre podstavu
float obsah_podstavy(float polomer){
	return PI * polomer * polomer;
}

float obvod_podstavy(float polomer){
	return 2 * PI * polomer;
}

//definicia funkcie pre plast
float obsah_plasta(float polomer, float vyska){
	return obvod_podstavy(polomer) * vyska;
}

//definicia funkcii pre objem a povrch valca
float objem_valca(float polomer, float vyska){
	return obsah_podstavy(polomer) * vyska;
}

float povrch_valca(float polomer, float vyska){
	return 2 * obsah_podstavy(polomer) + obsah_plasta(polomer, vyska);
}

//definicia funkcie pre vypis vyslednych hodnot
void vypis_hodnot(float polomer, float vyska){
	printf("\nINFO VALEC\n");
	printf("Obsah podstavy S: %.2f\n", obsah_podstavy(polomer));
	printf("Obvod podstavy O: %.2f\n", obvod_podstavy(polomer));
	printf("Obsah plasta S: %.2f\n", obsah_plasta(polomer, vyska));
	printf("Objem valca V: %.2f\n", objem_valca(polomer, vyska));
	printf("Povrch valca P: %.2f\n", povrch_valca(polomer, vyska));	
}
