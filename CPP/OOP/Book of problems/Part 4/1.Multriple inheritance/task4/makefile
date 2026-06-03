SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

CPP = g++
CPPFLAGS = -I .

default: all

%.o: $(SOURCES)
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
