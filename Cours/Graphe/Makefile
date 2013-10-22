EXE=Exercice1
LIBS=file.o topo.o
FLAGS= -Wall -g

${EXE}:${LIBS}

	gcc ${LIBS} -o ${EXE} ${FLAGS}

file.o:file.c

	gcc -c file.c ${FLAGS}

topo.o:topo.c

	gcc -c topo.c ${FLAGS}

clean:
	rm -f *.o