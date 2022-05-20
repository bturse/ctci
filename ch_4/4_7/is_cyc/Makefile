OBJ = is_cyc.o ../graph/graph.o

is_cyc : $(OBJ)
	gcc -o is_cyc $(OBJ)

is_cyc.o : is_cyc.h

../graph/graph.o : ../graph/graph.h

.PHONY : clean
clean : 
	rm $(OBJ)
