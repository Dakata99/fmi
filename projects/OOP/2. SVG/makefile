CPP = g++
CPPFLAGS = -I .

SOURCES = Figure.cpp Circle.cpp Rectangle.cpp Line.cpp Figures.cpp Tools.cpp Menu.cpp test.cpp
HEADERS = $(wildcard *.h)
OBJS := Figure.o Circle.o Rectangle.o Line.o Figures.o Tools.o Menu.o main.o

default: all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $<

main: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o main
	./main
	rm -f main

test:
	$(CPP) $(CPPFLAGS) $(SOURCES) -o test
	./test
	rm -f test

all: main test clean

clean:
	rm -f *.o

print_files:
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJS)
