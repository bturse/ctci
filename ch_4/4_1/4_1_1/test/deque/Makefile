OBJ = main.o test_deque.o ../../src/graph/graph.o ../../src/deque/deque.o

test_deque : $(OBJ)
	gcc -o test_deque $(OBJ)

main.o : test_deque.h
	gcc -c main.c 

test_deque.o : test_deque.h
	gcc -c test_deque.c

#graph :
#	cd ../../graph && $(MAKE)

.PHONY : clean
clean : 
	rm $(OBJ) test_deque
