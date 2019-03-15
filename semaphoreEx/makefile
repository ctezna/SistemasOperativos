all: createSemaphore

createSemaphore: createSemaphore.o
	$(CXX) -o $@ $^

clean: 
	rm -f createSemaphore
	rm -f createSemaphore.o