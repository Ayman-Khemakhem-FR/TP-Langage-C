#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct rationnel{
	long int num;
	long int den;
} fraction;

fraction build(long int n, long int d){
	assert(d!=0 && "Impossible de diviser par 0 !");
	struct rationnel f;
	f.num = n;
	f.den = d;
	return f;
}

bool eq_fraction(fraction f, fraction g){
	return(f.num * g.den == g.num * f.den);
}

bool is_int(fraction f){
	return (f.num % f.den == 0);
}

fraction sum(fraction f, fraction g){
	struct rationnel res;
	res.num = f.num * g.den + g.num * f.den;
	res.den = f.den * g.den;
	return res;
}

fraction sub(fraction f, fraction g){
	struct rationnel res;
        res.num = f.num * g.den - g.num * f.den;
        res.den = f.den * g.den;
        return res;
}

fraction mul(fraction f, fraction g){
	struct rationnel res;
        res.num = f.num * g.num;
        res.den = f.den * g.den;
        return res;
}

long pgcd(long a,long b){
	if(a<0) a = -a;
	if(b<0) b = -b;
	int x = a;
	int y = b;
	int r;
	while (y !=0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}	

fraction reduce(fraction f){
	struct rationnel res;
	res.num = f.num/pgcd(f.num, f.den);
	res.den = f.den/pgcd(f.num, f.den);

	if((res.num >=0 && res.den <0) || (res.num<0 && res.den <0)){
			res.num = -f.num;
			res.den = -f.den;
		
	}

	return res;
}

void affiche(fraction f){
	printf("%ld / %ld\n", f.num, f.den);
}
int main(){
	struct rationnel ex_fraction[7];

	ex_fraction[0] = build(1,1);
	ex_fraction[1] = build(1,2);
	ex_fraction[2] = build(2,4);
	ex_fraction[3] = build(-9,3);
	ex_fraction[4] = build(8,-20);
	ex_fraction[5] = build(-5,-1);
	ex_fraction[6] = build(1,-3);

	affiche(reduce(mul(ex_fraction[4],ex_fraction[5])));	
	return EXIT_SUCCESS;
}

