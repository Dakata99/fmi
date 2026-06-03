CPP = g++
CPPFLAGS = -I .

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

default: all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $<

main: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o a.out

all: main clean

clean:
	rm *.o

print_files:
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJS)
