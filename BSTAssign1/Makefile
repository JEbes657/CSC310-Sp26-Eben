#BSTProgram: BSTAssign.cpp BSTMain.cpp
#	g++ -o BSTProgram BSTAssign.cpp BSTMain.cpp

INCLUDE_DIRS := BSTAssign1
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := BSTAssign.o BSTMain.o
DEPS 		 := BSTAssign.h

.PHONY: clean all

all: BSTAssign.o BSTMain.o BSTProgram

clean:
	rm $(OBJS) BSTProgram

BSTAssign.o: BSTAssign.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

BSTMain.o: BSTMain.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

BSTProgram: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)