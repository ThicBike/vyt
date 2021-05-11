#include <stdio.h>
#include <math.h>

//deklaracia funkcii pre nacitanie stran a vykreslenie obdlznika
int nacitanie_strany(char strana);
void vykreslenie_obdlznika(int stranaA, int stranaB);

//deklaracia funkcii pre obvod, obsah a uhlopriecku obdlznika
int obvod(int stranaA, int stranaB);
int obsah(int stranaA, int stranaB);
float uhlopriecka(int stranaA, int stranaB);

//deklaracia funkcie pre pokracovanie programu
char pokracovanie();

void main(){
	//loalne premenne
    int stranaA, stranaB;

	
    do{
		printf("Zadaj rozmery obdlznika\n\n");
		
	    stranaA = nacitanie_strany('A'); //premennej sa priradi vratena hodnota z funkcie pre nacitanie strany
	    stranaB = nacitanie_strany('B'); //premennej sa priradi vratena hodnota z funkcie pre nacitanie strany
	    
		vykreslenie_obdlznika(stranaA, stranaB); //volanie funkcie pre vykreslenie obdlznika
		
		//vypis obvodu, obsahu a uhlopriecky
		printf("\nObvod = %d\n", obvod(stranaA, stranaB)); //volanie funkcie pre vypocet obvodu
	    printf("Obsah = %d\n", obsah(stranaA, stranaB)); //volanie funkcie pre vypocet obsahu
	    printf("Uhlopriecka = %.1f\n", uhlopriecka(stranaA, stranaB)); //volanie funkcie pre vypocet uhlopriecky
	    
    }while(pokracovanie() != 'n'); //cyklus sa ukonci ak pouzivatel zada pismeno n
    printf("Dovidenia! :D");
}

//definicia funkcie pre nacitanie strany
int nacitanie_strany(char strana){
	//lokalna premenna
	int velkost_strany;
	
    do{
        printf("Strana %c : ", strana);
        scanf("%d", &velkost_strany); //nacitanie velkosti strany
        
        if (velkost_strany <= 0) printf("\nZle zadana hodnota!!\nOpakuj zadanie strany!\n\n");
        
    }while(velkost_strany <= 0); //cyklus bude nacitavat stranu az kym strana nebude obsahovat kladnu hodnotu
    
	return velkost_strany;
}

//definicia funkcie pre vykreslenie obdlznika
void vykreslenie_obdlznika(int stranaA, int stranaB){
    //lokalne premenne
	int i, j;
    
    printf("\n");
    
    //cyklus pre vykreslenie obdlznika
    for(i = 1; i <= stranaB; i++){
		for(j = 1; j <= stranaA; j++){
			if(i == 1 || i == stranaB){
				printf("*");
			}else{
				if(j == 1 || j == stranaA){
					printf("*");
				}else{
					printf(" ");
				}	
			}
		}
		printf("\n");
	}
}

//definicia funkcie pre vypocet obvodu
int obvod(int stranaA, int stranaB){
	return 2 * (stranaA + stranaB);
}

//definicia funkcie pre vypocet obsahu
int obsah(int stranaA, int stranaB){
	return stranaA * stranaB;
}

//definicia funkcie pre vypocet uhlopriecky
float uhlopriecka(int stranaA, int stranaB){
	return sqrt(pow(stranaA, 2) + pow(stranaB, 2));
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
	
	return znak;
}

