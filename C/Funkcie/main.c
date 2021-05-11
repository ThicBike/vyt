#include <stdio.h>
#include <math.h>

/*
Tibor Pelegrin
2.A 2.Sk.
Úloha-funkcie
*/

float obvod(float a, float b);
float obsah(float a, float b);
float uhlopriecka(float a, float b);
float nacitanie_strany(char nazov_strany);
void vypis(float a, float b);
void main();

void main(){
	vypis(nacitanie_strany('B'), nacitanie_strany('A'));
}
	
float nacitanie_strany(char nazov_strany){
	float strana;
	
	do{
		printf("Zadaj stranu %c v obdlzniku : ", nazov_strany);
		scanf("%f",&strana);
	
		if(strana <= 0) printf("Zle zadana hodnota!\n");	
	
	}while(strana <= 0);
	
	return strana;
}

float obvod(float a, float b){
	return 2 * a + 2 * b;
}	

float obsah(float a, float b){
	return a * b;
	
}float uhlopriecka(float a, float b){
	return sqrt(a * a + b * b);
}	
	
void vypis(float a, float b){
	printf("Obvod : %.2f\n",obvod(a, b));
	printf("Obsah : %.2f\n",obsah(a, b));
	printf("Uhlopriecka : %.2f",uhlopriecka(a, b));
}

