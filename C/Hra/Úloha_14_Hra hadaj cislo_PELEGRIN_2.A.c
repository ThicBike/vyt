#include <stdio.h>
#include <stdlib.h>

/*
Uloha 14 - Hra, hadaj cislo
Tibor Pelegrin
2.A 2.sk.
*/

//deklaracia a inicializacia konstatny pre velkost intervalu z ktoreho sa bude generovat nahodny interval
const int INTERVAL_0 = 200;

//deklaracia funkcie pre generovanie hranice
int generovanie_hranic();

//deklaracia funkcie pre kontrolu hranic 
int kontrolaH(int hornaH, int dolnaH);

//deklaracia funkcie pre generovanie nahodneho cisla z nahodne vygenerovaneho intervalu
int generovanie_cisla(int hornaH, int dolnaH);

//deklaracia funkcie pre hadanie cisla
void hadanie(int hornaH, int dolnaH, int cislo);

//deklaracia funkcie pre vypis zaveru hry
void vypis(int pocet_pokusov, int rozsah);

//deklaracia funkcie pre pokracovanie programu
char pokracovanie();

void main(){
	//lokalne premenne
	int hornaH, dolnaH, cislo;
	
	do{
		printf("==== VITAJTE V HRE HADAJ CISLO ====\n");
		
		//srand(time(0)) pouzijeme aby sa nam kazdu sekundu generovali ine cisla
		srand(time(0));
		
		do{
			hornaH = generovanie_hranic(); //premennej hornaH priradime vratenu hodnotu z volanej funkcie pre generovanie hranic
			dolnaH = generovanie_hranic(); //premennej dolnaH priradime vratenu hodnotu z volanej funkcie pre generovanie hranic
		}while(kontrolaH(hornaH, dolnaH) != 1); //cyklus sa ukonci ak vratena hodnota z funkcie pre kontorlu hranic bude 1
		
		cislo = generovanie_cisla(hornaH, dolnaH); //premennej cislo sa priradi vratena hodnota z volanej funkcie pre generovanie nahodneho cisla
		hadanie(hornaH, dolnaH, cislo); //volanie funckie pre hadanie cisla
	}while(pokracovanie() != 'n'); //program sa bude opakovat kym vrateny znak z funckie pre pokracovanie nebude n
	
	printf("====GAME OVER====");
}

//definicia funkcie pre generovanie hranic
int generovanie_hranic(){
	//lokalna premenna
	int hranica;
	
	//do premennej hranica sa priradi nahodna hodnota z intervalu 0 az 200
	hranica = (rand() % (INTERVAL_0 +1));
	
	return hranica;
}

//definicia funkcie pre kontrolu hranic
int kontrolaH(int hornaH, int dolnaH){
	if(hornaH > dolnaH && hornaH - dolnaH <= 20 && hornaH - dolnaH >= 10){
		return 1; 
	}else{
		return 0;
	}
}

//definicia funkcie pre geenrovanie cisla
int generovanie_cisla(int hornaH, int dolnaH){
	//lokalna premenna
	int cislo;
	
	//do premennej cislo sa priradi nahodna hodnota z intervalu
	cislo = (rand() % (hornaH - dolnaH + 1)) + dolnaH;
	
	return cislo;
}

//definicia funkcie pre hadanie cisla
void hadanie(int hornaH, int dolnaH, int cislo){
	//lokalne premenne
	int tip, pocet_pokusov = 0;
	
	printf("Hadaj cislo z intervalu %d %d.\n", dolnaH, hornaH);
	
	do{
		//nacitanie cisla od pouzivatela do premennej tip
		printf("Zadaj cislo : ");
		scanf("%d", &tip);
		
		if(tip > cislo){
			if(tip > hornaH){
				printf("Zadana hodnota je vacsia ako horna hranica intervalu!\n"); //program upozorni pouzivatela ak by zadal vyssiu hodnotu ako je horna hranica intervalu
			}else{
				printf("Menej!\n"); //navigovanie pouzivatela k hadanemu cislu
			} 
		} 
		
		if(tip < cislo){
			if(tip < dolnaH){
				printf("Zadana hodnota je mensia ako dolna hranica intervalu!\n"); //program upozorni pouzivatela ak by zadal nizsiu hodnotu ako je dolna hranica intervalu
			}else{
				printf("Viac!\n"); //navigovanie pouzivatela k hadanemu cislu
			}
		} 
	
		pocet_pokusov ++; //pocitanie pokusov
	}while(tip != cislo); //cyklus sa ukonci ked pouzivatel uhadne cislo
	
	vypis(pocet_pokusov, (hornaH - dolnaH) / 2); //volanie funkcie pre vypis zaveru hry
}

//definicia funkcie pre vypis zaveru hry
void vypis(int pocet_pokusov, int rozsah){
	printf("\n****HURA****\n");
	
	if(pocet_pokusov <= rozsah){
		printf("SUPER\n");
		if(pocet_pokusov == 1) printf("OVLADOL SI HRU!\n");
	}else{
		printf("ZAMESTNAJ VESTCA\n");
	}
	
	printf("Pocet pokusov : %d", pocet_pokusov); //vypis poctu pokusov hadania cisla
}

//definicia funkcie pre pokracovanie programu
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
	
	printf("\n\n");
	
	return znak;
}




