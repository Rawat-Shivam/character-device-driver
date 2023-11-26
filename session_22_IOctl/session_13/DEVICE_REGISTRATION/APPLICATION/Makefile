#! /bin/bash

APP: main.o mainMenu.o openFile.o closeFile.o writeFile.o readFile.o ioctlAPP.o 
	gcc -o APP main.o mainMenu.o openFile.o closeFile.o writeFile.o readFile.o ioctlAPP.o

main.o: main.c headers.h declarations.h
	gcc -c main.c

ioctlAPP.o: ioctlAPP.c headers.h ioctlHEADERS.h declarations.h
	gcc -c ioctlAPP.c

mainMenu.o: mainMenu.c headers.h declarations.h
	gcc -c mainMenu.c

openFile.o: openFile.c headers.h declarations.h
	gcc -c openFile.c

closeFile.o: closeFile.c headers.h declarations.h
	gcc -c closeFile.c

writeFile.o: writeFile.c headers.h declarations.h
	gcc -c writeFile.c

readFile.o: readFile.c headers.h declarations.h
	gcc -c readFile.c
