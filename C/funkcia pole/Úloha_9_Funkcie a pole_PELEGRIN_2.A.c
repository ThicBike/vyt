#include <stdio.h>
#include <math.h>

/*
Uloha 9 - Funkcie a pole
Tibor Pelegrin
2.A 2.sk.
*/

//deklaracia a definicia konstatny pre velkost pola
const int POCETCISIEL = 5;

//deklaracia funkcii pre maximum, minimum, priemer a sucet 
float maximum(float cisla[], unsigned int velkost_pola);
float minimum(float cisla[], unsigned int velkost_pola);
float priemer_cisiel(float cisla[], unsigned int velkost_pola);
float sucet_cisiel(float cisla[], unsigned int velkost_pola);

//deklaracia funkcie pre vypis pola
void vypis_pola(float cisla[], unsigned int vekost_pola);

void main(){
	//lokalne premenne
	int velkost_pola = POCETCISIEL, i;
	float cisla[POCETCISIEL];
	char znak;
	
	printf("Zadaj %d cisiel: \n", velkost_pola);
	
	//cyklus pre nacitanie cisel do pola
	for(i = 0; i < velkost_pola; i++){
		printf("Cislo %d: ", i + 1);
		scanf("%f", &cisla[i]);
	}
	
	do{
		vypis_pola(cisla, velkost_pola); //volanie funkcie pre vypis pola
		
		//vypis ponuky
		printf("\n\nPre vypis maxima stlac M\n");
		printf("Pre vypis minima stlac m\n");
		printf("Pre vypis priemeru stlac p\n");
		printf("Pre vypis sucet stlac s\n");
		
		//nacitanie znaku od pouzivatela 
		printf("\nTvoja volba: ");
		getchar();
		znak = getchar();
		
		//kontrola znaku
		while(znak != 'M' && znak != 'm' && znak != 'p' && znak != 's'){
			printf("Zle zadany znak!\n");
			printf("Tvoja volba: ");
			getchar();
			znak = getchar();
		}
		
		switch(znak){
			case 'M':
				printf("Maximum v poli: %.1f\n", maximum(cisla, velkost_pola)); //volanie funkcie pre zistenie max cisla v poli
				break;
			case 'm':
				printf("Minimum v poli: %.1f\n", minimum(cisla, velkost_pola)); //volanie funckie pre zistenie mic cisla v poli
				break;
			case 'p':
				printf("Priemer cisiel: %.1f\n", priemer_cisiel(cisla, velkost_pola)); //volanie funkcie pre vypocet priemeru cisel v poli
				break;
			case 's':
				printf("Sucet cisiel: %.1f\n", sucet_cisiel(cisla, velkost_pola)); //volanie funkcie pre sucet cisel v poli
				break;
		}
		
		//moznost opakovania alebo moznost ukoncenia programu
		printf("\nChces pokracovat ? Yes (y), No (n): ");
		getchar();
		znak = getchar();
		
		//kontrala znaku
		while(znak != 'y' && znak != 'n'){
			printf("Zle zadany znak!\n");
			printf("Chces pokracovat ? Yes (y), No (n): ");
			getchar();
			znak = getchar();
		}
		
		//cyklus sa ukonci po stlaceni n
	}while(znak != 'n');
	
	printf("Dovidenia! :D");
}

//definicia funkcie pre maximum
float maximum(float cisla[], unsigned int velkost_pola){
	//lokalne premenne
	float MAX = cisla[0];
	int i = 1;
	
	//cyklus na zistenie max cisla v poli
	for(i; i < velkost_pola; i++){
		if(MAX < cisla[i]) MAX = cisla[i];
	}
	
	return MAX;
}

float minimum(float cisla[], unsigned int velkost_pola){
	//lokalne premenne
	float MIN = cisla[0];
	int i = 1;
	
	//cyklus na zistenie min cisla v poli
	for(i; i < velkost_pola; i++){
		if(MIN > cisla[i]) MIN = cisla[i];
	}
	
	return MIN;
}

//definicia funkcie pre vypocet priemeru cisiel v poli
float priemer_cisiel(float cisla[], unsigned int velkost_pola){
	
	//volame funkcie pre sucet cisel a nasledne vratenu hodnotu delime velkostou pola
	return sucet_cisiel(cisla, velkost_pola) / velkost_pola;
}

//definicia funkcie pre sucet cisel v poli
float sucet_cisiel(float cisla[], unsigned int velkost_pola){
	//lokalne premenne
	float SUM = 0;
	int i = 0;
	
	//cyklus na sucet cisel v poli
	for(i; i < velkost_pola; i++){
		SUM += cisla[i];
	}
	
	return SUM;
}

//definicia funkcie pre vypis pola
void vypis_pola(float cisla[], unsigned int velkost_pola){
	//lokalna premenna
	int i = 0;
	
	printf("\nVypis pola: ");
	
	//cyklus pre vypis cisiel v poli
	for(i; i < velkost_pola; i++){
		printf("%.1f ", cisla[i]);
	}
}
