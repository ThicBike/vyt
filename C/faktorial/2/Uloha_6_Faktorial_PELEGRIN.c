#include <stdio.h>
#include <math.h>

/*
Uloha 6 - Faktorial
Tibor Pelegrin
2.A 2.sk.
*/

//deklaracia funkcie pre nacitanie hodnotz=y
int nacitanie_kladnej_hodnoty();

//deklaracia funkcie pre vypocet faktorialu
int vypocet_faktorialu(int cislo);

//deklaracia funkcie pre vypis faktorialou
void vypis_faktorialou(int cislo);

void main(){
	//lokalna premenna ktora ma hodnotu z volanej funkcie pre nacitanie hodnoty
	int cislo = nacitanie_kladnej_hodnoty();
	
	vypis_faktorialou(cislo);
}

//definicia funkcie pre nacitanie hodnoty
int nacitanie_kladnej_hodnoty(){
	//lokalna premenna
	int hodnota;
	
	do{
		printf("Zadaj kladne cislo ! : ");
		scanf("%d",&hodnota);
	}while(hodnota < 0);
	return hodnota;
}

//definicia funkcie pre vypocet faktorialu
int vypocet_faktorialu(int cislo){
	//lokalne premenne
	int faktorial = 1, i;

	for(i = 1; i <= cislo; i++){
		faktorial = faktorial * i;
	}
	return faktorial;
}

//definicia funkcie pre vypis faktorialou
void vypis_faktorialou(int cislo){
	//lokalna premenna
	int i;

	for(i = 0; i <= cislo; i++){
		printf("%d! = %d\n", i, vypocet_faktorialu(i));
	}
}

