all: createSemaphore

createSemaphore: createSemaphore.o
	$(CXX) -o $@ $^

clean: 
	rm -f createSemaphore.o