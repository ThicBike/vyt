#include <stdio.h>
#include <stdlib.h>

/*
Tibor Pelegrin
2.A 2.Sk.
Uloha 1
*/

int main() {
	int pole[3][3], sum = 0, i, j;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("Zadaj hodnotu pola v %d. riadku a %d. stlpci : ", i + 1, j + 1);
			scanf("%d",&pole[i][j]);
			sum += pole[i][j];
		}
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d ",pole[i][j]);
		}
		printf("\n");
	}
	
	printf("SUMA : %d",sum);
	
	return 0;
}
