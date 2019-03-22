all: createSemSmokers removeSemSmokers Smoker Agent

LDFLAGS=-pthread
CXXFLAGS=-Wall -std=c++11 -g

createSemSmokers: createSemSmokers.o names.o
	$(CXX) -o $@ $(LDFLAGS) $^
createSemSmokers.o: createSemSmokers.cpp names.h

removeSemSmokers: removeSemSmokers.o names.o
	$(CXX) -o $@ $(LDFLAGS) $^
removeSemSmokers.o: removeSemSmokers.cpp names.h


Smoker: Smoker.o
	$(CXX) -o $@ $(LDFLAGS) $^


Agent: Agent.o names.o
	$(CXX) -o $@ $(LDFLAGS) $^
Agent.o: Agent.cpp names.h

clean: 
	rm -f createSemSmokers
	rm -f createSemSmokers.o
	rm -f removeSemSmokers
	rm -f removeSemSmokers.o
	rm -f Smoker
	rm -f Smoker.o
	rm -f Agent
	rm -f Agent.o
	rm -f names.o