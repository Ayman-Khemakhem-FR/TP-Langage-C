#include <stdio.h>
#include <stdlib.h>
int main() {
	int a;
	int b;

	printf("Bienvenue, veuillez choisir deux chiffres:\n");
	scanf ("%d %d", &a, &b);
	printf ("%d + %d = %d\n",a,b, a+b);

	return EXIT_SUCCESS;
}
