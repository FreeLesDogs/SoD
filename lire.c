#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_types.h"
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include "navalmap.h"

int convString(int Fichier){ // convertit la chaine de caractere suivante en entier
	char caractere = 0;
	int n = 0;

	while (read(Fichier,&caractere,1) != 0 && (caractere != ';' && caractere != '\n')){
		if ((caractere < '0') || (caractere > '9')){
			perror("Votre fichier est incorect.\n");
			exit(0);
		}
		n = n * 10 + atoi(&caractere);
	}
	
	printf("%d\n",n);
	return n;
}

int goLine	(int Fichier, int i){
	char caractere = 0;
	for (int j = 0; j < i; j++) {
		while (caractere != '\n') {
			read(Fichier, &caractere, 1);
		}
		caractere = 0;
		//printf("fin du fichier");
	}

	return Fichier;
}

INIT GetType(char *nom,INIT I){ // lire le premier mot du fichier
	char caractere = 0;
	int i = 0;
	int Fichier= open(nom,O_RDONLY);
	
	for (int j = 0; j < 15; j++) {
		I.Type[j] = 0;
	}
	while (read(Fichier, &caractere, 1) != 0 && caractere != ';') {
		I.Type[i] = caractere;
		i++;
	}
	printf("%s\n",I.Type );

	return I;
}

coord_t Getcoord(char * nom){
	char caractere=0;
	coord_t C;
	int Fichier = open(nom,O_RDONLY);	// on ouvre le fichier en lecture seule
	while (caractere != ';') {
			read(Fichier, &caractere, 1);
	}
		
	C.x = convString(Fichier);
	//printf("%d \n",C.x);
	C.y = convString(Fichier);
	//printf("%d \n",C.y);
	
	close(Fichier);		// fermeture du fichier   
	return C;
}

navalmap_t GetnbrShips(char *nom){
	navalmap_t N;
	int Fichier = open(nom,O_RDONLY);	// on ouvre le fichier en lecture seule
	Fichier=goLine(Fichier,1);		//mettre condition si jamais fichier taille 1
	
	N.nbShips = convString(Fichier);
	//printf("%d \n",N.nbShips);
	
	close(Fichier);		// fermeture du fichier   
	return N;
	
}

void initialisation (char *nom){ // Soir nom = argv[1]

	INIT I = GetType(nom,I);	
	coord_t C = Getcoord(nom);	
	navalmap_t N = GetnbrShips(nom);
}

int main(int argc, char *argv[])
{
	initialisation(argv[1]);
	return 0;
}