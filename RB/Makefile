INCLUDE_DIRS := RB
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := rb.o mainRB.o
DEPS 		 := rb.h

.PHONY: clean all

all: rb.o mainRB.o RBProgram

clean:
	rm $(OBJS) RBProgram

rb.o: rb.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainRB.o: mainRB.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

RBProgram: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)