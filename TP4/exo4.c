#include <stdio.h>

void print_tab (int *t, size_t start, size_t end){
	for (unsigned int i = start; i<end; ++i){
		printf("%p : %d\n", t+i, *(t+i));
	}
}

void print_tab2(int *pstart, int *pend){
        printf("1");
	while(pstart <= pend){
		printf("2");
		printf("%p : %d\n", pstart, *pstart);
		pstart++;
        }
}

int main(){
        int tab[6] = {0, 1, 2, 1, 4, 1};
	print_tab2(tab+1, tab+5);
}
