INCLUDE_DIRS := geneRecords
CC              := g++
CFLAGS          := -I$(INCLUDE_DIRS)

OBJS          := geneBank.o mainSamples.o customErrorClass.o
DEPS          := geneBank.h customErrorClass.h

.PHONY: clean all

all: geneProgram

clean:
	rm $(OBJS) geneProgram

geneBank.o: geneBank.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainSamples.o: mainSamples.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

geneRecords: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)