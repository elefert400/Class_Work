Lab01: main.o LinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o LinkedList.o Node.o -o Lab01

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -g -std=c++11 -Wall -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o Lab01
