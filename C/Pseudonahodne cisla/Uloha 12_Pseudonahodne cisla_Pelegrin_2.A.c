#include <stdio.h>
#include <math.h>

/*
Uloha 12 - Pseudonahodne cisla
Tibor Pelegrin
2.A 2.sk.
*/

//deklaracia a definicia konstatny pre velkost pola
const int POCETCISEL = 5;

//deklaracia funkcii pre maximum, minimum, priemer a sucet 
int maximum(int cisla[], unsigned int velkost_pola);
int minimum(int cisla[], unsigned int velkost_pola);
int priemer_cisel(int cisla[], unsigned int velkost_pola);
int sucet_cisel(int cisla[], unsigned int velkost_pola);

//deklaracia funkcii pre nacitanie intervalu a generaciu nahodnych cisel
void nacitanie_inrervalu(int cisla[], int dolnaH, int hornaH, unsigned int velkost_pola);
void generovanie_cisel(int cisla[], int dolnaH, int hornaH, unsigned int velkost_pola);

//deklaracia funkcie pre vypis pola
void vypis_pola(int cisla[], unsigned int vekost_pola);

void main(){
	//lokalne premenne
	int velkost_pola = POCETCISEL, i, dolnaH, hornaH;
	int cisla[POCETCISEL];
	char znak;
	
	//volanie funkcie pre nacitanie intervalu cisiel v poli
	nacitanie_inrervalu(cisla, dolnaH, hornaH, velkost_pola);
	
	do{
		//volanie funkcie pre vypis pola
		vypis_pola(cisla, velkost_pola); 
		
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
				printf("Maximum v poli: %d\n", maximum(cisla, velkost_pola)); //volanie funkcie pre zistenie max cisla v poli
				break;
			case 'm':
				printf("Minimum v poli: %d\n", minimum(cisla, velkost_pola)); //volanie funckie pre zistenie mic cisla v poli
				break;
			case 'p':
				printf("Priemer cisiel: %d\n", priemer_cisel(cisla, velkost_pola)); //volanie funkcie pre vypocet priemeru cisel v poli
				break;
			case 's':
				printf("Sucet cisiel: %d\n", sucet_cisel(cisla, velkost_pola)); //volanie funkcie pre sucet cisel v poli
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
		
	}while(znak != 'n'); //cyklus sa ukonci po stlaceni n
	
	printf("Dovidenia! :D");
}

//definicia funkcie pre maximum
int maximum(int cisla[], unsigned int velkost_pola){
	//lokalne premenne
	int max = cisla[0];
	int i;
	
	//cyklus na zistenie max cisla v poli
	for(i = 1; i < velkost_pola; i++){
		if(max < cisla[i]) max = cisla[i];
	}
	
	return max;
}

//definicia funkcie pre minimum
int minimum(int cisla[], unsigned int velkost_pola){
	//lokalne premenne
	int min = cisla[0];
	int i;
	
	//cyklus na zistenie min cisla v poli
	for(i = 0; i < velkost_pola; i++){
		if(min > cisla[i]) min = cisla[i];
	}
	
	return min;
}

//definicia funkcie pre vypocet priemeru cisiel v poli
int priemer_cisel(int cisla[], unsigned int velkost_pola){
	//lokalne premenne
	int priemer, a;
	a = velkost_pola;
	priemer = sucet_cisel(cisla, velkost_pola) / a;	//volanie funkcie pre sucet cisel a nasledne vratenu hodnotu delime velkostou pola - a

	return priemer; 
}

//definicia funkcie pre sucet cisel v poli
int sucet_cisel(int cisla[], unsigned int velkost_pola){
	//lokalne premenne
	int sum = cisla[0];
	int i;
	
	//cyklus na sucet cisel v poli
	for(i = 1; i < velkost_pola; i++){
		sum += cisla[i];
	}
	
	return sum;
}

//definicia funkcie pre nacitanie intervalu cisel pola
void nacitanie_inrervalu(int cisla[], int dolnaH, int hornaH, unsigned int velkost_pola){
	
	//nacitanie dolnej hranice intervalu
	printf("Zadaj dolnu hranicu intervalu : ");
	scanf("%d", &dolnaH);
	
	//nacitanie hornej hranice intervalu
	printf("Zadaj hornu hranicu intervalu : ");
	scanf("%d", &hornaH);
	
	//kontrola nacitanych hranic intervalu, upozornenie pouzivatela na chybu a nasledne znovunacitanie hranic intervalu
	while(hornaH < dolnaH || hornaH - dolnaH < velkost_pola){
		if(hornaH < dolnaH) printf("Horna hranica musi byt vacsia ako dolna!!\nOpakuj zadanie hranic!\n"); 
		if(hornaH - dolnaH < velkost_pola) printf("Rozdiel medzi hornou a dolnou hranicou musi byt aspon %d!!\nOpakuj zadanie hranic!\n", velkost_pola);
		
		printf("Zadaj dolnu hranicu intervalu : ");
		scanf("%d", &dolnaH);
	
		printf("Zadaj hornu hranicu intervalu : ");
		scanf("%d", &hornaH);
	}
	
	//volanie funkcie pre vygenerovanie nahodnych cisel do pola
	generovanie_cisel(cisla, dolnaH, hornaH, velkost_pola);
}

//definicia funkcie pre generovanie nahodnych cisel do pola
void generovanie_cisel(int cisla[], int dolnaH, int hornaH, unsigned int velkost_pola){
	//lokalna premenna
	int i;
	
	//inicializácia generátora náhodných èísel, srand(time(0)) zabezpeci aby sa po kazdom spusteni programu generovala ina postupnost cisel
	srand(time(0));
	for(i = 0; i < velkost_pola; i++){
		
		//vygenerovanie nahodneho cisla a nasledne priradenie tohto cisla do pola.
		/*
		horna a dolna hranica mozu byt aj zaporne cisla, z toho dovodu potrebujeme spravit rozdiel medzi hornou a dolnou hranicou aby sme zistili 
		kladny rozsah stupnice, napr. - 10 - (-20) = 10, teda generator nam vygeneruje cisla z intervalu od 0 - 9, kedze chceme aby to mohlo
		generovat aj 10 tak priratame + 1, tym padom nam to bude generovat cisla od 0 - 10...Nasledne tieto cisla chceme posunut spat 
		do zapornych cisel a tak od nich odpocitame dolnu hranicu intervalu
		*/
		cisla[i] = (rand() % (hornaH - dolnaH + 1)) + dolnaH;
	}
}

//definicia funkcie pre vypis pola
void vypis_pola(int cisla[], unsigned int velkost_pola){
	//lokalna premenna
	int i;
	
	printf("\nVypis pola: ");
	
	//cyklus pre vypis cisiel v poli
	for(i = 0; i < velkost_pola; i++){
		printf("%d ", cisla[i]);
	}
}
