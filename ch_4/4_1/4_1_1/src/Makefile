OBJ = bfs/bfs.o graph/graph.o deque/deque.o

has_path : $(OBJ)
	gcc -o has_path main.c $(OBJ)

bfs/bfs.o : bfs/bfs.h
graph/graph.o : graph/graph.h
deque/deque/o : deque/deque.h

.PHONY : clean
clean : 
	rm $(OBJ) has_path
