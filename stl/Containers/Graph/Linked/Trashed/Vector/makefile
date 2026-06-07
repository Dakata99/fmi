CC=g++
COMPILE=$(CC) -c
LINK=$(CC)

.cpp.o:
	$(COMPILE) -I. $< -o $@
	
glist:	main.o Graph.h Graph.o GList.h GList.o GListTests.o
	$(LINK) main.o Graph.o GList.o GListTests.o -o $@
	
gelist:	main.o Graph.h GEList.h Graph.o GEList.o GEListTests.o
	$(LINK) main.o Graph.o GEList.o GEListTests.o -o $@

gmatrix: main.o Graph.h GMatrix.h Graph.o GMatrix.o GMatrixTests.o
	$(LINK) main.o Graph.o GMatrix.o GMatrixTests.o -o $@

all:	glist gelist gmatrix
	
clean:
	rm -f *.o
