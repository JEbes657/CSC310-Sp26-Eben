INCLUDE_DIRS := geneRecords
CC              := g++
CFLAGS          := -I$(INCLUDE_DIRS)

OBJS          := hash.o main.o avl.o
DEPS          := hash.h AVL/avl.h

.PHONY: clean all

all:hash

clean:
	rm $(OBJS) hash

hash.o: hash.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: mainHash.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

avl.o: AVL/avl.cpp AVL/avl.h
	$(CC) -c -o $@ $(CFLAGS) $<

hash: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)