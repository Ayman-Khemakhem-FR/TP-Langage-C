#include <stdio.h>

size_t occ(int *t, size_t nbr, int v){
	for (unsigned int i = 0; i<nbr; ++i){
		if(*(t + i) == v) return i;
	}
	return nbr;
}

int *occ_ptr (int *t, size_t nbr, int v){
	for (unsigned int i = 0; i<nbr; ++i){
                if(*(t + i) == v) return &t[i];
        }
        return NULL;
}

int main(){
        int tab[3] = {0, 1, 2};
	printf ("%p\n", occ_ptr(tab, 3, 1));
}	
