OBJ = main.o test_graph.o ../../src/graph/graph.o

test_graph : $(OBJ)
	gcc -o test_graph $(OBJ)

main.o : test_graph.h
	gcc -c main.c

test_graph.o : test_graph.h
	gcc -c test_graph.c

.PHONY : clean
clean :
	rm $(OBJ) test_graph
