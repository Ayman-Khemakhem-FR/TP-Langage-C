#include <stdio.h>

size_t nbr_occ (int *t, size_t nbr, int v){
	size_t j = 0;
	for (unsigned int i = 0; i<nbr; ++i){
                if(*(t + i) == v) j++;
        }
        return j;
}

void nbr_occ_op (int *t, size_t nbr, int v, size_t *pnv){
	size_t j = 0;
        for (unsigned int i = 0; i<nbr; ++i){
                if(*(t + i) == v) j++;
        }
        *pnv = j;
	printf ("%ld\n", *pnv);
}

void min_max_op (int *t, size_t nbr, int *pmin, int *pmax){
	*pmin = *t;
	*pmax = *t;
	for (unsigned int i = 0; i<nbr; i++){
		if(*(t+i)>*pmax) *pmax = *(t+i);
		if(*(t+i)<*pmin) *pmin = *(t+i);
	}
	printf ("min: %d et max: %d\n", *pmin, *pmax);
}

	

int main(){
        int tab[6] = {0, 1, 2, 1, 4, 1};
	printf("%ld\n", nbr_occ (tab, 6, 1)); 
        
	size_t pnv;
	nbr_occ_op(tab, 6, 1, &pnv);

	int min;
	int max;
	min_max_op (tab, 6, &min, &max);
}
