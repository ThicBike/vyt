#include <stdio.h>
#include <math.h>

/*
Tibor Pelegrin
Uloha 3 - kvader
2.A 2.sk.
*/

//deklaracia funkcii pre kvader
float objemK(float stranaA, float stranaB, float stranaC);
float povrchK(float stranaA, float stranaB, float stranaC);
float uhloprieckaK(float stranaA, float stranaB, float stranaC);

//deklaracia funkcii pre obdlznik
float obsahO(float stranaA, float stranaB);
float uhloprieckaO(float stranaA, float stranaB);

//deklaracia funkcie pre nacitanie stran
float nacitanie_strany(char nazov_strany);

//deklaracia funkcie pre kontrolu rozmeru
int kladne_cislo(float a);

//deklaracia funkcie pre vypis vyslednych hodnot
void vypis(float stranaA, float stranaB, float stranaC);


void main(){
	vypis(nacitanie_strany('C'), nacitanie_strany('B'), nacitanie_strany('A'));
}

//definicia funkcie pre nacitanie stran	
float nacitanie_strany(char nazov_strany){
	//lokalna premenna
	float strana; 
	
	do{
		printf("Zadaj stranu %c v obdlzniku : ", nazov_strany);
		scanf("%f",&strana);	
	}while(kladne_cislo(strana)); //volanie funkcie pre kontrolu rozmeru
	
	return strana;
}

//definicia funkcie pre kontrolu rozmeru
int kladne_cislo(float a){
	if(a <= 0){
		printf("Cislo nie je kladne!\n");
		return 1;
	}else{	 
		return 0;
	}
}

//definicia funkcii pre kvader
float objemK(float stranaA, float stranaB, float stranaC){
	return obsahO(obsahO(stranaA, stranaB), stranaC);
}

float povrchK(float stranaA, float stranaB, float stranaC){
	return 2 * (obsahO(stranaA, stranaB)+ obsahO(stranaA, stranaC) + obsahO(stranaB, stranaC));

}float uhloprieckaK(float stranaA, float stranaB, float stranaC){
	return uhloprieckaO(uhloprieckaO(stranaA, stranaB), stranaC);
}	

//definicia funkcii pre obdlznik
float obsahO(float stranaA, float stranaB){
	return stranaA * stranaB;
}

float uhloprieckaO(float stranaA, float stranaB){
	return sqrt(pow(stranaA, 2) + pow(stranaB, 2));
}

//definicia funkcie pre	vypis vyslednych hodnot
void vypis(float stranaA, float stranaB, float stranaC){
	printf("Objem : %.2f\n",objemK(stranaA, stranaB, stranaC));
	printf("Povrch : %.2f\n",povrchK(stranaA, stranaB, stranaC));
	printf("Uhlopriecka : %.2f",uhloprieckaK(stranaA, stranaB, stranaC));
}
