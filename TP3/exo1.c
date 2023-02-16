#include <stdio.h>
#include <stdlib.h>
#define NBC 10
#include <time.h>

enum etat {
VALIDEE, ENCOURS, EXPEDIEE
};
typedef enum etat etat;

struct commande {
	int num_com;
	int prix_exp;
	int prix_prod;
	etat etat_com;
};

typedef struct commande commande;

void affiche_com(commande c){
	printf("La commande %d est produite pour %d euros et est expediée pour %d euros. ", c.num_com, c.prix_exp, c.prix_prod);
	switch(c.etat_com){
		case VALIDEE:	printf("La commande est validée.\n");
				break;
		case ENCOURS:	printf("La commande est en cours d'expedition.\n");
				break;
		case EXPEDIEE:	printf("La commande a été expediée.\n");
				break;
	}
}

commande com_alea(int num){
	
	struct commande c = {num, rand()%21 + 1, rand()%2001 + 1, rand()%3};
	return c;
}

void affiche_exp(commande t[], size_t taille){
	for(unsigned int i=0; i<taille; ++i){
                if(t[i].etat_com == 2){
			affiche_com(t[i]);
		}
        }
}

int nbr_en_cours(commande t[], size_t taille){
	int res = 0; 
	for(unsigned int i=0; i<taille; ++i){
                if(t[i].etat_com == 1){
                	res += 1;
		}
        }
	return printf("Le tableau a %d commandes en cours d'expedition\n", res);
}

int cout_validees(commande t[],size_t taille){
	int res = 0;
        for(unsigned int i=0; i<taille; ++i){
                if(t[i].etat_com == 0){
                        res += t[i].prix_exp;
                }
        }
        return printf("Le coût total d'expedition est de %d euros\n", res);
}

commande change_prix(commande c, int i){
	struct commande c1 = c;
	c1.prix_prod = i;
	return c1;
}

commande change_etat(commande c, int i){
        struct commande c1 = c;
        c1.etat_com = i;
        return c1;
}

void expedie_tout(commande tab[], size_t n){
	for(unsigned int i=0; i<n; ++i){
		tab[i] = change_etat(tab[i], 2);
	}
}

int main(void){
	commande tab[NBC];
	for(unsigned int i=0; i<NBC; ++i){
		tab[i] = com_alea(i);
	}
	expedie_tout(tab, 10);
	affiche_exp(tab, 10);
}

