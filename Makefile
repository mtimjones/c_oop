object: object.c object.h objapp.c
		gcc -g -o object objapp.c object.c

all: object

clean:
		rm -f object
