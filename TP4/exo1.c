#include <stdio.h>

void swap (int *p, int *q){
	int x = *p;
    	*p = *q;
    	*q = x;
}

int main(){
	int tab[3] = {0, 1, 2};
	swap(&tab[0], &tab[1]);
	for(int i=0; i<3; i++){
		printf ("%d ", tab[i]);
	}
	printf ("\n");
	
}
