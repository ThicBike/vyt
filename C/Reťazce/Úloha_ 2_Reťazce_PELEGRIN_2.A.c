#include <stdio.h>
#include <stdlib.h>

/*
Uloha 2 - Retazce
Tibor Pelegrin
2.A 2.sk.
*/

//deklaracia a inicializacia konstanty pre velkost retazca
const int VELKOSTRETAZCA = 51;

//deklaracia funkcie pre nacitanie retazca
void nacitanie_retazca(char text[]);

//deklaracia funkcie pre zistenie velkosti retazca
int velkost_retazca(char text[]);

//deklaracia funkcie pre vypis retazca odzadu
void vypis_odzadu(char text[]);

//deklaracia funkcie pre pocitanie jednotlivych znakov v retazci
void pocitanie_znakov(char text[]);

void main(){
	//lokalna premenna
	char text[VELKOSTRETAZCA];
	
	//volanie funkcii
	nacitanie_retazca(text);
	vypis_odzadu(text);
	pocitanie_znakov(text);
}

//definicia funkcie pre nacitanie retazca
void nacitanie_retazca(char text[]){
	//lokalna premenna
	int i;
	
	printf("Zadaj vetu ktora ma najviac %d znakov: ", VELKOSTRETAZCA - 1);
	fgets(text, VELKOSTRETAZCA, stdin); //nacitanie vety do retazca

	printf("\nPocet znakov: %d", velkost_retazca(text)); //vypis a volanie funkcie pre zistenie velkosti retazca
}

//definicia funkcie pre zistenie velkost retazca
int velkost_retazca(char text[]){
	//lokalne premenne
	int i, pocet_znakov = 0;
	
	//cyklus zvysuje hodnotu poctu znakov o 1 az kym retazec nie je na konci
	for(i = 0; text[i] != '\0' ; i++){
		pocet_znakov++;
	}
	
	return pocet_znakov - 1;
}

//definicia funkcie pre
void vypis_odzadu(char text[]){
	//lokalne premenne
	int i, pocet_znakov;
	
	pocet_znakov = velkost_retazca(text);
	printf("\nVeta odzadu:");
	
	//cyklus ktory vypise retazec odzadu
	for(i = pocet_znakov; i >= 0; i--){
		printf("%c", text[i]);
	}
}

//definicia funkcie pre
void pocitanie_znakov(char text[]){
	//lokalne premenne
	int i, j, znaky;
	
	printf("\nPocet jednotlivych znakov: \n");
	
	//v prvom fore i predstavuje pismeno abecedy, v druhom fore ho porovnava s pismenami z retazca, ak sa pismeno z 
	//retazca rovna pismenu ktore je pod premennou i tak pocet znakov vo vete tohto pismena sa zvysi o 1, na konci
	//sa vypisu len tie pismena ktore su v retazci aspon raz
	for(i = 'a'; i <= 'z'; i++){
		znaky = 0;
		for(j = 0; text[j] != '\0'; j++){
			if(text[j] == i) znaky++;
		}
		if(znaky > 0) printf("%c: %d\n", i, znaky);
	}
}
	

	
	

	
