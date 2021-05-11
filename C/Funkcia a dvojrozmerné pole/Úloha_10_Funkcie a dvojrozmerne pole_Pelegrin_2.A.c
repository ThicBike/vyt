#include <stdio.h>
#include <stdlib.h>


/*
Uloha 10 - Funkcie a dvojrozmerne pole
Tibor Pelegrin
2.A 2.sk.
*/

//deklaracia a definicia konstatny pre pocet cisiel v riadku a v stlpci pola
const int POCETCISEL = 3;

//deklaracia funkcii pre maximum, minimum, priemer a sucet 
float maximum(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola);
float minimum(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola);
float priemer_cisel(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola);
float sucet_cisel(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola);

//deklaracia funkcii pre nacitanie a vypis pola a ponuky
void nacitanie_pola(float pole[POCETCISEL][POCETCISEL], unsigned int velkostPola);
void vypis_pola(float pole[POCETCISEL][POCETCISEL], unsigned int velkostPola);
void vypis_ponuky();

//deklaracia funkcie pre moznost volby riadku alebo stlpca
char riadok_stlpec();

//deklaracia funkcie pre moznost vyberu poradia riadku alebo stlpca
int poradie_rs(char rs, unsigned int velkostPola);

//deklaracia funkcie pre nacitanie volby od pouzivatela
char nacitanie_volby();

//deklaracia funkcie pre moznost pokracovania pogramu
char pokracovanie();

void main(){
	//lokalne premenne
	int velkostPola = POCETCISEL;
	float pole[POCETCISEL][POCETCISEL];
	char rs;
	int poradieRS;
	
	nacitanie_pola(pole, velkostPola); //volanie funkcie pre nacitanie cisel
	
	do{
		vypis_pola(pole, velkostPola); //volanie funkcie pre vypis pola
		vypis_ponuky(); // volanie funkcie pre vypis ponuky
		
		
		switch(nacitanie_volby()){ //volanie funkcie pre nacitanie volby
			case 'M':
				rs = riadok_stlpec(); //volanie funkcie pre moznost volby riadku alebo stlpca
				poradieRS = poradie_rs(rs, velkostPola); //volanie funkcie pre moznost vyberu poradia riadku alebo stlpca
				
				printf("Maximum v %d. %c je %.1f\n", poradieRS, rs, maximum(pole, rs, poradieRS, velkostPola)); //volanie funkcie pre zistenie maxima
				
				break;
			case 'm': 
				rs = riadok_stlpec();
				poradieRS = poradie_rs(rs, velkostPola);
				
				printf("Minimum v %d. %c je %.1f\n", poradieRS, rs, minimum(pole, rs, poradieRS, velkostPola)); //volanie funkcie pre zistenie minima
				
				break;
			case 'p':
				rs = riadok_stlpec();
				poradieRS = poradie_rs(rs, velkostPola);
				
				printf("Priemer cisel v %d. %c je %.1f\n", poradieRS, rs, priemer_cisel(pole, rs, poradieRS, velkostPola)); //volanie funkcie pre vypocet priemeru cisel
				
				break;
			case 's':
				rs = riadok_stlpec();
				poradieRS = poradie_rs(rs, velkostPola);
				
				printf("Sucet cisel v %d. %c je %.1f\n", poradieRS, rs, sucet_cisel(pole, rs, poradieRS, velkostPola)); //volanie funkcie pre sucet cisel
				
				break;			
		}
	}while(pokracovanie() != 'n' ); //volanie funkcie pre pokracovanie programu
	
	printf("Dovidenia! :D"); //vypis pozdravu na rozlucenie
}

//definicia funkcie pre nacitanie pola
void nacitanie_pola(float pole[POCETCISEL][POCETCISEL], unsigned int velkostPola){
	//lokalne premenne
	int i, j;
	
	printf("Zadaj cisla v poli : \n");
	
	//cyklus pre nacitanie cisiel do pola
	for(i = 0; i < velkostPola; i++){
		for(j = 0; j < velkostPola; j++){
			printf("Zadaj cislo v %d. riadku a %d. stlpci : ", i + 1, j + 1);
			scanf("%f", &pole[i][j]);
		}
	}
	printf("\n");
}

//definicia funkcie pre vypis pola
void vypis_pola(float pole[POCETCISEL][POCETCISEL], unsigned int velkostPola){
	//lokalne premenne
	int i, j;
	
	printf("Vypis pola :\n");
	
	//cyklus pre vypisanie pola
	for(i = 0; i < velkostPola; i++){
		for(j = 0; j < velkostPola; j++){
			printf("%.1f ", pole[i][j]);
		}
		printf("\n");
	}
}

//definicia funkcie pre vypis ponuky
void vypis_ponuky(){
	printf("\nPre vypis maxima stlac M\n");
	printf("Pre vypis minima stlac m\n");
	printf("Pre vypis priemeru stlac p\n");
	printf("Pre vypis sucet stlac s\n");
}

//definicia funkcie pr nacitanie volby
char nacitanie_volby(){
	//lokalna premenna
	char znak;
	
	printf("Tvoja volba : ");
	getchar();
	znak = getchar();
	
	//kontrola zadaneho znaku
	while(znak != 'M' && znak != 'm' && znak != 'p' && znak != 's'){
		printf("Zle zadany znak!\n");
		printf("Tvoja volba: ");
		getchar();
		znak = getchar();
	}
	return znak;
}

//definicia funkcie pre moznost volby ruadku alebo stlpca
char riadok_stlpec(){
	//lokalna premenna
	char znak;
	
	printf("\nZadaj 'r' pre riadok alebo 's' pre stlpec\n");
	printf("Tvoja volba : ");
	getchar();
	znak = getchar();
	
	//kontrola znaku
	while(znak != 'r' && znak != 's'){
		printf("\nZle zadany znak!\n");
		printf("Tvoja volba : ");
		getchar();
		znak = getchar();
	}
	return znak;
}

//definicia funkcie pre moznost vyberu poradia riadku alebo stlpca
int poradie_rs(char rs, unsigned int velkostPola){
	//lokalna premenna
	int poradie;
	
	printf("\nZadaj poradie %c v poli : ", rs);
	scanf("%d", &poradie);
	
	//kontrola zadaneho poradia
	while(poradie > velkostPola || poradie <= 0){
		printf("\nZle zadane poradie!\n");
		printf("Zadaj poradie znovu : ");
		scanf("%d", &poradie);
	}
	return poradie;
}

///definicia funkcie pre pokracovanie programu
char pokracovanie(){
	//lokalna premenna
	char znak;
	
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
	return znak;
}

//definicia funkcie pre maximum
float maximum(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola){
	//lokalne premenne
	float MAX;
	int i, j;
	
	if(rs == 'r'){
		i = poradieRS - 1;
		j = 0;
		MAX = pole[i][j];
		
		//cyklus pre zistenie maxima v riadku
		for(j = 1; j < velkostPola; j++){
			if(MAX < pole[i][j]) MAX = pole[i][j];
		}
	}
	
	if(rs == 's'){
		i = 0;
		j = poradieRS - 1;
		MAX = pole[i][j];
		
		//cyklus pre zistenie maxima v stlpci
		for(i = 1; i < velkostPola; i++){
			if(MAX < pole[i][j]) MAX = pole[i][j];
		}
	}
	return MAX;
}

//definicia funkcie pre zistenie minima
float minimum(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola){
	//lokalne premenne
	float MIN;
	int i, j;
	
	if(rs == 'r'){
		i = poradieRS - 1;
		j = 0;
		MIN = pole[i][j];
		
		//cyklus pre zistenie minima v riadku
		for(j = 1; j < velkostPola; j++){
			if(MIN > pole[i][j]) MIN = pole[i][j];
		}
	}
	
	if(rs == 's'){
		i = 0;
		j = poradieRS - 1;
		MIN = pole[i][j];
		
		//cyklus pre zistenie minima v stlpci
		for(i = 1; i < velkostPola; i++){
			if(MIN > pole[i][j]) MIN = pole[i][j];
		}
	}
	return MIN;
}

//definicia funkcie pre vypocet priemeru
float priemer_cisel(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola){
	//lokalna premenna 
	//volanie funkcie pre sucet cisel
	float priemer = sucet_cisel(pole, rs, poradieRS, velkostPola) / velkostPola;
	return priemer;
}

//definicie funkcie pre sucet cisiel
float sucet_cisel(float pole[POCETCISEL][POCETCISEL], char rs, int poradieRS, unsigned int velkostPola){
	//lokalne premenne
	float SUM = 0;
	int i, j;
	
	if(rs == 'r'){
		i = poradieRS - 1;
		
		//cyklus pre sucet cisel v riadku 
		for(j = 0; j < velkostPola; j++){
			SUM += pole[i][j];
		}
	}
	
	if(rs == 's'){
		j = poradieRS - 1;
		
		//cyklus pre sucet cisel v stlpci
		for(i = 0; i < velkostPola; i++){
			SUM += pole[i][j];
		}
	}
	return SUM;
}








