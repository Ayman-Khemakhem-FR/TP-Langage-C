#include <stdio.h>
#include <math.h>
#define N 100

struct polynome{
	int de;
	int co[N];
};

int eval(struct polynome p, int i){
	int res = 0;
	int puissance = 1;
	for (int j=0; j<p.de + 1; j++){
		res += p.co[j]*puissance;
		puissance *= i;
	}
	return res;
}

void print_poly(struct polynome p){
	if(p.co[0] != 0) printf("%d + ", p.co[0]);
	if(p.co[1] != 0) printf("%dx + ", p.co[1]);
	for(int i=2; i<p.de; i++){
		if(p.co[i] != 0) printf("%dx^%d + ",p.co[i], i);
	}
	printf("%dx^%d\n",p.co[p.de], p.de);
}

struct polynome derive(struct polynome p){
	struct polynome q;
	q.de = p.de -1;
	for (int i = 0; i<p.de+1; i++){
		p.co[i] *= i;
                if(i != 0) q.co[i-1] = p.co[i];
        }
	return q;
}

struct polynome init(int n){
	struct polynome p;
	p.de = n;
	for(int i = 0; i<N; i++){
		p.co[i] = 0;
	}
	return p;
}

struct polynome somme(struct polynome p, struct polynome q){
	struct polynome z;
	if(p.de > q.de)	z.de = p.de;
	
	else	z.de = q.de;
	
	for(int i = 0; i <= z.de; i++){
		
		z.co[i] = p.co[i] + q.co[i];
	}
	
	return z;
}

struct polynome multiplier(struct polynome p, struct polynome q) {
    struct polynome z;
    z.de = p.de + q.de;
    for(int i = 0; i <= z.de; i++) {
        int res = 0;
        for(int j = 0; j <= i; j++) {
            res += p.co[j] * q.co[i-j];
        }
        z.co[i] = res;
    }
    return z;
}

int main(){
	struct polynome p = init(2);
	p.co[0] = 1;
	p.co[1] = 1;
	p.co[2] = 2;

	struct polynome q = init(1);
        q.co[0] = 2;
        q.co[1] = 3;

	print_poly(multiplier(p, q));
}	
