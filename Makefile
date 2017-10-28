prog1: main.o Trie.o
	g++ -std=c++11 -Wall main.o Trie.o -o prog1

main.o: main.cpp
	g++ -c main.cpp

garage.o: Trie.cpp Trie.h
	g++ -c Trie.cpp

clean:
	rm *.o prog1
