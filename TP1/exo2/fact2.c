#include <stdio.h>
#include <stdlib.h>

void fact2 (unsigned n){
	int res = 1;
	for(int i=1; i<= n; i++){
		res *= i;
		printf("%d! = %d\n", i, res);
	}
}

int main(){
	int a;
	
	scanf ("%u",&a);
	fact2(a);

	return EXIT_SUCCESS;
}
