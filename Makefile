CXX = g++
CXXFLAGS = -fsanitize=undefined -fsanitize=address -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-variable -Wno-unused-parameter -std=c++2a -g -fmax-errors=1 -Wfatal-errors -D_GLIBCXX_DEBUG

a.out: main.o particleSystem.o linkedlist.o particle.o graphics.o Node.h carson.h jackson.h gurshan.h riley.h
	$(CXX) $(CXXFLAGS) -g main.o linkedlist.o particleSystem.o particle.o graphics.o carson.o
main.o: main.cc particleSystem.o carson.o jackson.h gurshan.h riley.h
	$(CXX) $(CXXFLAGS) -c main.cc

particleSystem.o: linkedlist.o particle.o particleSystem.h particleSystem.cc
	$(CXX) $(CXXFLAGS) -c particleSystem.cc
linkedList.o: linkedlist.cc linkedlist.h Node.h particle.o	
	$(CXX) $(CXXFLAGS) -c linkedlist.cc
particle.o: particle.cc particle.h graphics.o
	$(CXX) $(CXXFLAGS) -c particle.cc
graphics.o: graphics.cc graphics.h
	$(CXX) $(CXXFLAGS) -c graphics.cc
carson.o: carson.h carson.cc
	$(CXX) $(CXXFLAGS) -c carson.cc
clean:
	rm a.out *.o
