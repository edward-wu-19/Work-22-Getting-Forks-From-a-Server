all: interface.o worker.o
	gcc -o interface interface.o
	gcc -o worker worker.o

interface.o:
	gcc -c interface.c

worker.o:
	gcc -c worker.c

clean:
	rm interface.o
	rm worker.o
	rm interface
	rm worker
	rm pToC
	rm cToP