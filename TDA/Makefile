#============================
# Makefile 
#============================

#-------------
# Executables 
#-------------

testpile : testpile.o eltprim.o pileprim.o lstprim.o lstop.o tradpile.o
	gcc testpile.o eltprim.o pileprim.o lstprim.o lstop.o tradpile.o -o testpile

testpile.o : testpile.c
	gcc -c testpile.c -o testpile.o 

#----------
# Modules
#----------

# TDA ELEMENT
#

# -- Primitives avec realisation par "char"
#
eltprim.o : eltchar.c eltprim.h
	gcc -c eltchar.c -o eltprim.o

eltprim.h : eltsdd.h
	touch eltprim.h

eltsdd.h : eltchar.h
	touch eltsdd.h

# -- Operations 
#

# TDA PILE
#

# -- Primitives avec realisation par faux pointeurs : 
#

pileprim.o : piltabdy.c pileprim.h
	gcc -c piltabdy.c -o pileprim.o

pileprim.h : pilesdd.h 
	touch pileprim.h

pilesdd.h : piltabdy.h 
	touch pilesdd.h

# -- Operations 
#

# TDA LISTE
#

# -- Primitives avec realisation par pointeurs : 
#

lstprim.o : lstptr.c lstprim.h
	gcc -c lstptr.c -o lstprim.o

lstsdd.h : lstptr.h
	touch lstsdd.h

lstprim.h : lstsdd.h 
	touch lstprim.h

tradpile.o : tradpile.c tradpile.h
	gcc -c tradpile.c -o tradpile.o

# -- Operations 
#

lstop.o : c1lstop.c c1lstop.h 
	gcc -c c1lstop.c -o lstop.o

c1lstop.h : lstprim.h
	touch c1lstop.h


#----------------------------
# Gestion generale du projet 
#----------------------------

all : testpile

clean :
	rm *.o

tags : 
	etags *.c *.h
