#include <stdio.h>
#include <stdlib.h>

/*
Tibor Pelegrin
2.A 2.Sk.
Uloha 3
*/

int main() {
	int pole[100][100], i, j, matica, uhlopriecka, sum = 0;
	char volba;
	int riadky, stlpce;
	
	do{
		printf("Zadaj pocet riadkov v poli: ");
		scanf("%d", &riadky);
		if(riadky <= 0) printf("Zla hodnota!\n");
	}while(riadky <= 0);
	
	do{
		printf("Zadaj pocet stlpcov v poli: ");
		scanf("%d", &stlpce);
		if(stlpce <= 0) printf("Zla hodnota!");
	}while(stlpce <= 0);
	
	for(i = 0; i < riadky; i++){
		for(j = 0; j < stlpce; j++){
			printf("Zadaj hodnotu pola v %d. riadku a %d. stlpci : ", i + 1, j + 1);
			scanf("%d",&pole[i][j]);
			sum += pole[i][j];
		}
	}
	
	printf("Pre zobrazenie matice stlac v/V\n");	
	printf("Pre sucet prvkov v matici stlac s/S\n");
	printf("Pre ukoncenie programu stlac k/K\n");
	
	do{
		
		printf("Tvoja volba : ");
		getchar();
		volba = getchar();
		
		while(volba != 'v' && volba != 'V' && volba != 's' && volba != 'S' && volba != 'k' && volba != 'K'){
			printf("Zla volba!!\n");
			printf("Tvoja volba : ");
			getchar();
			volba = getchar();
		}
		
		switch(volba){
			case 'v' :
			case 'V' :
				printf("Matica :\n");
				for(i = 0; i < riadky; i++){
					for(j = 0; j < stlpce; j++){
						printf("%d ",pole[i][j]);
					}
					printf("\n");
				}
				break;
			case 's' : 
			case 'S' :
				printf("SUM : %d\n",sum);
				break;							
			case 'k' :
			case 'K' :
				break;	
		}
		
	
	}while(volba != 'k' && volba != 'K');
	
	printf("\n### Dovidenia! ###");
		
	return 0;
}
