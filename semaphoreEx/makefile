all: createSemaphore removeSemaphore

createSemaphore: createSemaphore.o
	$(CXX) -o $@ $^

removeSemaphore: removeSemaphore.o
	$(CXX) -o $@ $^

clean: 
	rm -f createSemaphore
	rm -f createSemaphore.o
	rm -f removeSemaphore
	rm -f removeSemaphore.o