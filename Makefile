all : digits three

digits : digits.o
	gcc -o digits digits.o

digits.o : digits.c
	gcc -c digits.c

three : three.o
	gcc -o three three.o

three.o : three.c
	gcc -c three.c
