#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	float somme = 0;
	float div = 0;
	
	scanf ("%u",&a);
	somme += a;
	
	while(a!=0){
		scanf ("%u",&a);
		somme += a;
		div += 1;
	}

	printf("%f", somme/div);
	return EXIT_SUCCESS;
}
