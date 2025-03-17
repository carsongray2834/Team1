CXX = g++
CXXFLAGS = -fsanitize=undefined -fsanitize=address -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-variable -Wno-unused-parameter -std=c++2a -g -fmax-errors=1 -Wfatal-errors -D_GLIBCXX_DEBUG

a.out: main.o particle.o
	$(CXX) $(CXXFLAGS) main.o particle.o

main.o: main.cc particle.h
	$(CXX) $(CXXFLAGS) -c main.cc

particle.o: particle.h particle.cc
	$(CXX) $(CXXFLAGS) -c particle.cc

clean:
	rm a.out main.o particle.o
