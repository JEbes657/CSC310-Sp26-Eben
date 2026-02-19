INCLUDE_DIRS := DSW
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := dsw.o main.o
DEPS 		 := dsw.h

.PHONY: clean all

all: dsw.o main.o dswProgram

clean:
	rm $(OBJS) dswProgram

dsw.o: dsw.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

dswProgram: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)