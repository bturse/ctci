OBJ = main.o test_bfs.o ../../src/graph/graph.o ../../src/deque/deque.o ../../src/bfs/bfs.o ../graph/test_graph.o

test_bfs : $(OBJ)
	gcc -o test_bfs $(OBJ)

main.o : test_bfs.h
	gcc -c main.c 

test_bfs.o : test_bfs.h
	gcc -c test_bfs.c

#graph :
#	cd ../../graph && $(MAKE)
#
#deque :
#	cd ../../deque && $(MAKE)

#test_graph :
#	cd ../../test/graph && $(MAKE)


.PHONY : clean
clean : 
	rm $(OBJ) test_bfs


