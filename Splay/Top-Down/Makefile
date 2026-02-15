INCLUDE_DIRS := Top-Down
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := splay.o mainsplay.o
DEPS 		 := splayHeader.h

.PHONY: clean all

all: splay.o mainsplay.o splayProgram

clean:
	rm $(OBJS) splayProgram

splay.o: splay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainsplay.o: mainsplay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

splayProgram: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
