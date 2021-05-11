#include <stdio.h>
#include <stdlib.h>



int main() {
	int a = 1, b = 10, c = 1;
	int *pa = &a, *pb = &b, *pc = &c;	
	printf("a	b	c	 	pa  		  	pb   			pc\n");
	
	a = b * c;// 10 10 1 &a &b &c
	printf("%d	%d	%d	%p	%p	%p\n", a, b, c, pa, pb, pc);
	
	a += c;// 11 10 1 &a &b &c
	printf("%d	%d	%d	%p	%p	%p\n", a, b, c, pa, pb, pc);
	
	c = *pa;// 11 10 11 &a &b &c
	printf("%d	%d	%d	%p	%p	%p\n", a, b, c, pa, pb, pc);
	
	pc = pb;// 11 10 11 &a &b &b
	printf("%d	%d	%d	%p	%p	%p\n", a, b, c, pa, pb, pc);
	
	a = (*pb) * (*pc);// 100 10 11 &a &b &b
	printf("%d	%d	%d	%p	%p	%p\n", a, b, c, pa, pb, pc);
	
	b = a * (*pc);// 100 1000 11 &a &b &b
	printf("%d	%d	%d	%p	%p	%p\n", a, b, c, pa, pb, pc);
	
	*pc += 1;//100 1001 11 &a &b &b
	printf("%d	%d	%d	%p	%p	%p\n", a, b, c, pa, pb, pc);
	
	return 0;
}
