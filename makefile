CC := g++
FLAGS := -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

./target/program: ./obj/pro2.o ./obj/Estudiant.o ./obj/solucio.o ./obj/Cjt_estudiants.o
	$(CC) $(FLAGS) -o $@ $^ 
./obj/%.o: ./src/%.cc
	$(CC) $(FLAGS) -c $< -o $@

.PHONY = clean test check
clean:
	rm -rf ./target/* ./obj/*
test: 
	./target/program < ./tests/sample.inp > ./target/output
check: ./target/output
	diff ./target/output ./tests/sample.cor


