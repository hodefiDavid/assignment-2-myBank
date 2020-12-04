CC = gcc
COMP_FLAG = -Wall 


all: mains myBank

mains: main.o libmyBank.a	
	$(CC)  $(COMP_FLAG)   -o mains main.o libmyBank.a

myBank: libmyBank.a
libmyBank.a: myBank.o myBank.h
	ar -rcs libmyBank.a  myBank.o


main.o: main.c myBank.h
	$(CC) $(COMP_FLAG) -c main.c
myBank.o: myBank.c 
	$(CC) $(COMP_FLAG) -c $*.c

.PHONY: clean all myBank

clean:
	rm -f *.a *.o mains
		
	
