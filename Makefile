out : main.o linkedList.o
	gcc main.o linkedList.o -o out

main.o : main.c 
	gcc -c main.c 

linkedList.o : linkedList.h linkedList.c
	gcc -c linkedList.c linkedList.h

clean :
	rm *.o