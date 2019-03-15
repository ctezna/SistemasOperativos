all: createSemaphore removeSemaphore deamonPrinter clientPrinter processHierarchy

createSemaphore: createSemaphore.o
	$(CXX) -o $@ $^

removeSemaphore: removeSemaphore.o
	$(CXX) -o $@ $^

deamonPrinter: deamonPrinter.o
	$(CXX) -o $@ $^

clientPrinter: clientPrinter.o
	$(CXX) -o $@ $^

processHierarchy: processHierarchy.o
	$(CXX) -o $@ $^

clean: 
	rm -f createSemaphore
	rm -f createSemaphore.o
	rm -f removeSemaphore
	rm -f removeSemaphore.o
	rm -f deamonPrinter
	rm -f deamonPrinter.o
	rm -f clientPrinter
	rm -f clientPrinter.o
	rm -f processHierarchy
	rm -f processHierarchy.o