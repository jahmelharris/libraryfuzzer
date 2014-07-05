all : 
	gcc -c -g -Wall -Werror -fpic testLibrary.c
	gcc -g -shared -o libtestLibrary.so testLibrary.o
	gcc -g -Wall -o main main.c -L`pwd` -ltestLibrary

clean: 
	rm main testLibrary.o libtestLibrary.so
