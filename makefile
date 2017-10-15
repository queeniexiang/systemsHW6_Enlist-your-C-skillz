all: linked_list.o
	gcc -o test linked_list.o 

linked_list.o: linked_list.c
	gcc -c linked_list.c 

run: 
	./test

clean:
	rm *.o
	rm *.
