#include <stdio.h>
#include <stdlib.h>

unsigned fact (unsigned n){
	int res = 1;
	for(int i=1; i<= n; i++){
		res *= i;
	}
	return res;
}

int main(){
	int a;
	scanf ("%u",&a);

	printf("%d", fact(a));

	return EXIT_SUCCESS;
}
