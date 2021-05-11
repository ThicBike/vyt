#include <stdio.h>
#include <stdlib.h>

int n;
int t;
unsigned char otazka[1000];

int main(int argc, char *argv[]) {
	int i;
	int id;
	int kt;
	int h;
	char moznost;
	int velkostPrek = 0;
	
	scanf("%d", &n);
    scanf("%d", &t);
    
    int pole[n];
    int prek[n];
    
    for(i = 0; i < n; i++){
    	scanf("%d", &pole[i]);
		if(pole[i] > t){
			velkostPrek++;
			prek[velkostPrek - 1] = pole[i];
		}  
	}
	
	
	
	
	do{
		scanf("%c", &otazka[]);
		if(moznost == 'N'){
			scanf("%d", &id);
			
		}else if(moznost == 'Z'){
			scanf("%d", &kt);
			scanf("%d", &h);
		} 
	}while(moznost != 'E');
	
	
	
	
	
	return 0;
}
