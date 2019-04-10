.PHONY: all
all: philo_pos_block philo_no_block

CXXFLAGS=-Wall -std=c++11 -g
LDFLAGS=-pthread

%: %.o
	$(CXX) -o $@ $^ $(LDFLAGS)

philo_pos_block: philo_pos_block.o table.o aux_functions.o

philo_no_block: philo_no_block.o table.o aux_functions.o

philo_pos_block.o: philo_pos_block.cpp table.h infophilo.h aux_functions.h

philo_no_block.o: philo_no_block.cpp table.h infophilo.h aux_functions.h

table.o: table.cpp table.h

aux_functions.o: aux_functions.cpp aux_functions.h

.PHONY: clean

clean:
	rm -f *.o *.*~ *~
	rm -rf philo_no_block philo_pos_block