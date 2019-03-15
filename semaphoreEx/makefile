all: createSemaphore removeSemaphore demonPrinter clientPrinter

createSemaphore: createSemaphore.o
	$(CXX) -o $@ $^

removeSemaphore: removeSemaphore.o
	$(CXX) -o $@ $^

demonPrinter: demonPrinter.o
	$(CXX) -o $@ $^

clientPrinter: clientPrinter.o
	$(CXX) -o $@ $^

clean: 
	rm -f createSemaphore
	rm -f createSemaphore.o
	rm -f removeSemaphore
	rm -f removeSemaphore.o
	rm -f demonPrinter
	rm -f demonPrinter.o
	rm -f clientPrinter
	rm -f clientPrinter.o