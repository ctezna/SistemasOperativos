all: philosophers

CXXFLAGS=-Wall -std=c++11 -g
LDFLAGS=-pthread

philosophers: main.o table.o
	$(CXX) -o $@ $^ $(LDFLAGS)

table.o: table.cpp table.h

main.o: main.cpp table.h

clean:
	rm -rf philosophers
	rm -rf table.o
	rm -rf main.o