CXX = g++
CXXFLAGS = -fsanitize=undefined -fsanitize=address -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-variable -Wno-unused-parameter -std=c++2a -g -fmax-errors=1 -Wfatal-errors -D_GLIBCXX_DEBUG

a.out: main.o particle.o graphics.o
	$(CXX) $(CXXFLAGS) main.o particle.o graphics.o

main.o: main.cc particle.h
	$(CXX) $(CXXFLAGS) -c main.cc

particle.o: particle.h particle.cc
	$(CXX) $(CXXFLAGS) -c particle.cc

graphics.o: graphics.cc graphics.h
	$(CXX) $(CXXFLAGS) -c graphics.cc

clean:
	rm a.out main.o particle.o
