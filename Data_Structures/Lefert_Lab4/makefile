Lab04: main.o hashTableDouble.o hashTableQuad.o hashTable.o LinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o hashTableDouble.o hashTableQuad.o hashTable.o LinkedList.o Node.o -o Lab04

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

hashTableDouble.o: hashTableDouble.h hashTableDouble.cpp
	g++ -g -std=c++11 -Wall -c hashTableDouble.cpp

hashTableQuad.o: hashTableQuad.h hashTableQuad.cpp
	g++ -g -std=c++11 -Wall -c hashTableQuad.cpp

hashTable.o: hashTable.h hashTable.cpp
	g++ -g -std=c++11 -Wall -c hashTable.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -g -std=c++11 -Wall -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o Lab04
