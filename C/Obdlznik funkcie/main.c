#include <stdio.h>
#include <stdlib.h>

void nacitanie_stran(int stranaA, int stranaB);
void vykreslenie_obdlznika(int stranaA, int stranaB);
//int obvod(int stranaA, int stranaB);
//float obsah(int stranaA, int stranaB);
//float uhlopriecka(int stranaA, int stranaB);
//char pokracovanie();

void main(){
    int stranaA, stranaB;

    //do{
	printf("Zadaj rozmery obdlznika :");

    do{	
        printf("Strana A : ");
        scanf("%d", &stranaA);
        if (stranaA <= 0) printf("Zle zadana hodnota!!\nOpakuj zadanie strany!\n");
    }while(stranaA <= 0);
    
    do{
        printf("Strana B : ");
        scanf("%d", &stranaB);
        if (stranaB <= 0) printf("Zle zadana hodnota!!\nOpakuj zadanie strany!\n");
    }while(stranaB <= 0);	
    //nacitanie_stran(stranaA, stranaB);
    vykreslenie_obdlznika(stranaA, stranaB);
    //obvod(stranaA, stranaB);
    //obsah(stranaA, stranaB);
    //uhlopriecka(stranaA, stranaB);
    //pokracovanie();

    //}while(pokracovanie() != 'n' || pokracovanie() != 'N');
    
    
}

void nacitanie_stran(int stranaA, int stranaB){
    printf("Zadaj rozmery obdlznika :");

    do{
        printf("Strana A : ");
        scanf("%d", &stranaA);
        if (stranaA <= 0) printf("Zle zadana hodnota!!\nOpakuj zadanie strany!\n");
    }while(stranaA <= 0);
    
    do{
        printf("Strana B : ");
        scanf("%d", &stranaB);
        if (stranaB <= 0) printf("Zle zadana hodnota!!\nOpakuj zadanie strany!\n");
    }while(stranaB <= 0);

}

void vykreslenie_obdlznika(int stranaA, int stranaB){
    int i, j;
    for (i = 1; i <= stranaB; i++){
        for (j = 0; j < stranaA; j++){
            if (i == 1 || i == stranaA) printf("*");
            //if ();
            
            
        }
        
    }
    
}
