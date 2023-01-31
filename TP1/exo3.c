#include <stdio.h>
#include <stdlib.h>
#define N 27
int main(){
        int n = N;
	printf("\n");
	for(int i=1; i<=n; ++i){
		int tmp = 0;
		int util = i;
		while(util!=1){
                        if(util%2 == 0){    
				util=util/2;
				tmp ++;
			}
                        else{    
				util = util*3 +1;
				tmp ++;
			}
        	}
		printf("%d : %d\n",i ,tmp);
	}

	return EXIT_SUCCESS;
}
