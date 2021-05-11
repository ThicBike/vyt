 #include <stdio.h>
#include <stdlib.h>

/*
Tibor Pelegrin
2.A 2.Sk.
Uloha 2
*/


int main(){
	int pole[3][3], i, j, stlpec;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("Zadaj hodnotu pola v %d. riadku a %d. stlpci : ", i + 1, j + 1);
			scanf("%d",&pole[i][j]);
		}
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", pole[i][j]);
		}
		printf("\n");
	}
	
	printf("Zadaj cislo stlpca : ");
	scanf("%d", &stlpec);
	
	j = stlpec - 1;
	
	if(j < 3 && j >= 0){
		for(i = 0; i < 3; i++){
			printf("%d\n",pole[i][j]);
		}
	}else{
		printf("Neexistujuci stlpec!");
	}
		
	return 0;
}
