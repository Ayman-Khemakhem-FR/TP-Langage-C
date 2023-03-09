#include <stdio.h>
#include <stdlib.h>


int main(){
	printf("1) Les bouts de condes sont équivalents, pt point à chaque fois vers le même élément du tableau. t == &t[0]\n\n");
	printf("2) Il y'a un conflit de type pour t\n\n");
	printf("3) Il y'a des erreurs sur la premiere, pour la deuxième gcc retourne une erreur pour cette utilisation de malloc\n\n");
	printf("4) Pour les deux ils y'a plusieurs erreurs.\n");
}	
