CC := g++
FLAGS := -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program: pro2.o Estudiant.o solucio.o Cjt_estudiants.o
	$(CC) $(FLAGS) -o $@ $^ 
%.o: %.cc
	$(CC) $(FLAGS) -c $< 

.PHONY := clean

clean:
	rm -rf program *.o *.out 
