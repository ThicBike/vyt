#include <stdio.h>
#include <stdlib.h>

int min = 100, max = 20;
void vymen(int *min, int *max);


int main(int argc, char *argv[]) {
	
	printf("Max: %d\nMin: %d", max, min);
	
	vymen(&min, &max);
	
	printf("\nMax: %d\nMin: %d", max, min);
	
	return 0;
}

void vymen(int *min, int *max){
	int buffer;
	
	if(*min > *max){
		buffer = *max;
		*max = *min;
		*min = buffer;
	}
	
	printf("\nMax: %d\nMin: %d", *max, *min);
}
