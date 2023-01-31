#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int puissance = 1;
	int res = 0;

	scanf("%d", &n);
	for(int i=1; i<n+1; i++){
		for(int j=1; j<4; j++){
			puissance *= i;
		}
		res += puissance;
		puissance = 1;
	}
	printf("%d\n", res);
	return EXIT_SUCCESS;
}
