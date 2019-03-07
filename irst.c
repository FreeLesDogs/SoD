#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main(int argc, char const *argv[]){
char buffer[1000];
char x;
/*char type;*/
int val;
int tailleX,tailleY;


  if (argc != 2){
    printf("erreur nb argument \n");
    return -1;
  }

  int rep=open(argv[1], 444);
  read (rep, &buffer,1000);
  

  //r pour rectangle c pour carré

  if(buffer[0]=='c'){
  	
  	//on met le pointeur à la position 2
  	lseek(rep,2,SEEK_SET);
  	read(rep,&x,1);

  	tailleX=atoi(&x);
  	tailleY=tailleX;

  	printf("type carré\n");
  	printf("taille x et y: %d\n",tailleX);
  }
  else if(buffer[0]=='r'){

  	lseek(rep,2,SEEK_SET);
  	read(rep,&x,1);

  	tailleX=atoi(&x);
  	lseek(rep,4,SEEK_SET);
  	read(rep,&x,1);
  	tailleY=atoi(&x);

  	printf("type rectangle\n");
  	printf("taille x: %d\n",tailleX);
  	printf("taille y: %d\n",tailleY);


  }
  

  else{
  	printf("type inconnu verifier fichier d'entrée");
  	return -2;
  }


  //printf("%s\n",buffer);
  close(rep);



return 0;
}