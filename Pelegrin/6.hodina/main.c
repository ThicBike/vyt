#include <stdio.h>
#include <limits.h>

int faktorial(int n);


int main() {
	int fak = 0;
	int i; 
	
	do{
		printf("Zadaj cislo : ");
		scanf("%d", &fak);

		//if( > INT_MAX) printf("Prilis velke cislo!");
	}while(faktorial(fak) > INT_MAX);
	
	for(i = 0; i <= fak; i++){
		printf("%d! = %d\n", i, faktorial(i));
	}
	
	return 0;
}

int faktorial(int n){
	int fak = 1;
	
	if( n == 0) fak = 1;
	if( n > 0) fak = n * faktorial(n - 1);
	
	return fak;
}
