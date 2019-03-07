.PHONY: all lib debug

all: lib

lib:
	gcc -g -c -fPIC *.c
	ar rcs libnm.a *.o

debug:
	gcc -g -o prog main.c -L. -lnm

comp:
	gcc -o SoD lire.c
	./SoD fichier
	
clean:
	rm *.o 