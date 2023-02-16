#include <stdio.h>

int f(int n){
	if(n==1) return 2;
	return 2*3*f((n-1)/2);
}

int g(int n){
	if(n ==1) return 1;
	return 3*f(n/2);
}

int main(){
	printf("%d", f(20));
}
