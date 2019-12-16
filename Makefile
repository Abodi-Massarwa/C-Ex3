#-*-Makefile-*-
CC=gcc
OBJECTS_MAIN=main1.o
OBJECTS_MAIN2=main2.o
FLAGS= -Wall -g
OBJECT_isort=isort.o
OBJECT_txtfind=txtfind.o

all: isort txtfind
	 
isort: isortd $(OBJECTS_MAIN)
	$(CC) $(OBJECTS_MAIN) -o isort ./libisort.so
	
isortd: $(OBJECT_isort)
	$(CC) -shared -o libisort.so $(OBJECT_isort)

isort.o: isort.c
	$(CC) $(FLAGS) -fPIC -c isort.c

$(OBJECTS_MAIN): main1.c universal.h
	$(CC) $(FLAGS) -fPIC -c main1.c
	
############################################################################
txtfind: txtfindd $(OBJECTS_MAIN2)
	$(CC) $(OBJECTS_MAIN2) -o txtfind ./libtxtfind.so
	
txtfindd: $(OBJECT_txtfind)
	$(CC) -shared -o libtxtfind.so $(OBJECT_txtfind)
	
txtfind.o: txtfind.c
	$(CC) $(FLAGS) -fPIC -c txtfind.c

$(OBJECTS_MAIN2): main2.c universal.h
	$(CC) $(FLAGS) -fPIC -c main2.c

.PHONY: clean all

clean:
	rm -f *.o txtfind isort *.so 