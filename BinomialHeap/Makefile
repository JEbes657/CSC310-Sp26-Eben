INCLUDE_DIRS := BinomialHeap
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := binomial.o main.o
DEPS 		 := binomial.h

.PHONY: clean all

all: binomial.o main.o Binomial

clean:
	rm $(OBJS) Binomial

binomial.o: rb.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: mainRB.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

Binomial: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)