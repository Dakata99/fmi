CC 		:= cc
CFLAGS 	:= -I . -Wunused

SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJS 	:= $()

# for making a generic target: task1, task2, etc.
TARGET := $(word 1, $(MAKECMDGOALS))
I := $(subst task,,$(TARGET))
ARGUMENTS := $(filter-out task$(I),$(MAKECMDGOALS))

# exclude targets that require input
EXCLUDE := task2 task3 task4_a task4_b

ERR := 0

ifneq ($(filter $(TARGET),$(EXCLUDE)),)
    $(info $(TARGET) needs input... Please run it manually...)
ERR := 1
endif

default: all

ifneq ($(ERR),1)
task$(I):
	$(CC) $(CFLAGS) task$(I).c -o task$(I).out
endif
	./task$(I).out

all: task clean

clean:
	rm -f *.o *.out

print_files:
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJS)
