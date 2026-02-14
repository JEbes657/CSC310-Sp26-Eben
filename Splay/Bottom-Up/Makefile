INCLUDE_DIRS := Bottom-Up
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := customErrorClass.o customErrorHandling.o
DEPS 		 := ${INCLUDE_DIRS}

.PHONY: clean all

all: customErrorClass.o customErrorHandling.o mainsplay.o splay.o

clean:
	rm $(OBJS) errorTutorial

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorHandling.o: customErrorHandling.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainsplay.o: mainsplay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

splay.o: splay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<