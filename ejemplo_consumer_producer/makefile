.phony: clean
LDFLAGS=-pthread

execs=prodcon prodconcpp

all: $(execs)

prodcon: prodcon.o
	$(CXX) -o $@ $^ $(LDFLAGS)

prodcon.o: prodcon.cpp

prodconcpp: prodconcpp.o
	$(CXX) -o $@ $^ $(LDFLAGS)

prodconcpp.o: prodconcpp.cpp

clean:
	rm -f *.cpp~ makefile~ *.h~
	rm -f *.o
	rm -f $(execs)

