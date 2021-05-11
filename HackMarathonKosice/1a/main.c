#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	
	
	int x[25];
	int kolo[5];
	int v[3];
	
	int n = 3;
 	int i;
 	
 	for(i = 0; i < 25; i++){
 		x[i] = i;	
	}
	
	for(i = 0; i < 3; i++){
		v[i] = x[i];
	}
	
	
	
	//sutaziaci do kol
	//top3
	for(i = 0; i < 3; i++){
		kolo[i] = v[i]	;
	}
	
	//zvysni dvaja
	for(i = 3; i < 5; i++){
		kolo[i] = x[i];	
	}
	
	for(i = 0; i < 5; i++){
		5	
	}

	
	
	return 0;
}





