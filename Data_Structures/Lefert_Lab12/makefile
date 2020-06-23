Lab12: main.o graph.o minHeap.o LinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o graph.o minHeap.o LinkedList.o Node.o -o Lab12

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

graph.o: graph.h graph.cpp
	g++ -g -std=c++11 -Wall -c graph.cpp

minHeap.o: minHeap.h minHeap.cpp
	g++ -g -std=c++11 -Wall -c minHeap.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -g -std=c++11 -Wall -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o Lab12
