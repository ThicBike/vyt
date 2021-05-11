#include <stdio.h>

int jevpoli(int cislo, int pole[]);
int main() {
	int i, j;
	int vs[3];
	
	scanf("%d", &vs[0]);
    scanf("%d", &vs[1]);
    scanf("%d", &vs[2]);
    int poz[vs[0]];
    for(i = 0; i < vs[1]; i++){
    	scanf("%d", &poz[i]);
	}
    int pole[2*vs[2]];
    for(i = 0; i < 2*vs[2]; i++){
    	scanf("%d", &pole[i]);
	}
	for(j = 0; j < vs[1]; j++){
		for(i = 0; i < vs[2]*2; i += 2){
			if(poz[j] == pole[i] ){	
				
				if(!jevpoli(pole[i + 1], poz)){
					vs[1]++;
					poz[vs[1] - 1] = pole[i + 1];
				}	
			}else if(poz[j] == pole[i + 1]){
					
				if(!jevpoli(pole[i], poz)){
					vs[1]++;
					poz[vs[1] - 1] = pole[i];
				}
			}
		}
	}
	printf("%d", vs[1]);
	
	return 0;
}

int jevpoli(int cislo, int pole[]){
	int je[2];
	je[0] = 0;
	
	for(je[1] = 0; je[1] < sizeof(pole); je[1]++){
		if(cislo == pole[je[1]]) je[0] = 1;
	}
	return je[0];
}
