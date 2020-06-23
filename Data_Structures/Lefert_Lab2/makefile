Lab02: main.o hashTable.o LinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o hashTable.o LinkedList.o Node.o -o Lab02

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

hashTable.o: hashTable.h hashTable.cpp
	g++ -g -std=c++11 -Wall -c hashTable.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -g -std=c++11 -Wall -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o Lab02
