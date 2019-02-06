.phony: clean

all: ejemploProceso crearProceso directCalling manualCalling directCalling2 manualCalling2

ejemploProceso: ejemploProceso.o
	g++ -o $@ $<

ejemploProceso.o: ejemploProceso.cpp

crearProceso: crearProceso.o
	g++ -o $@ $<

crearProceso.o: crearProceso.cpp
	g++ -Wwrite-strings -c $<

directCalling: directCalling.o mifuncion.o
	g++ -o $@ $^

directCalling.o: directCalling.cpp constantes.h

mifuncion.o: mifuncion.cpp constantes.h

manualCalling: manualCalling.o
	g++ -o $@ $<

manualCalling.o: manualCalling.cpp

manualCalling2: manualCalling2.o
	g++ -o $@ $<

manualCalling2.o: manualCalling2.cpp

directCalling2: directCalling.o
	g++ -o $@ $<

directCalling2.o: directCalling2.cpp

clean:
	rm -f ejemploProceso.o ejemploProceso crearProceso.o crearProceso
	rm -f directCalling.o mifuncion.o directCalling
	rm -f manualCalling.o manualCalling
	rm -f directCalling2.o directCalling2
	rm -f manualCalling2.o manualCalling2
