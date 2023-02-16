#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SUP 83


void initialisation(bool T[],size_t n){
	for(size_t i=0; i<n; ++i){
        	T[i] = true;
	}
}

void remplissage(bool T[],size_t n){
       for(size_t i=0; i<n; ++i){
		for(size_t j=i+1; j<n; ++j){
			if((j+2)%(i+2) == 0){
				T[j] = false;
			}
		}
	}
}

void affichNbPremier(bool T[],size_t n){
	for(size_t i=0; i<n; ++i){
		if(T[i]) printf("%zu ", i+2);
	}
}

int main(){
	bool tab[SUP];
	initialisation(tab, SUP);
	remplissage(tab, SUP);
	affichNbPremier(tab, SUP);

	return EXIT_SUCCESS;
}



