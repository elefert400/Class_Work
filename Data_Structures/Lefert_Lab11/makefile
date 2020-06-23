Lab11: main.o binarySearchTree.o node.o maxHeap.o minHeap.o
	g++ -g -std=c++11 -Wall main.o binarySearchTree.o node.o maxHeap.o minHeap.o -o Lab11

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

binarySearchTree.o: binarySearchTree.h binarySearchTree.cpp
	g++ -g -std=c++11 -Wall -c binarySearchTree.cpp

node.o: node.h node.cpp
	g++ -g -std=c++11 -Wall -c node.cpp

maxHeap.o: maxHeap.h maxHeap.cpp
	g++ -g -std=c++11 -Wall -c maxHeap.cpp

minHeap.o: minHeap.h minHeap.cpp
	g++ -g -std=c++11 -Wall -c minHeap.cpp

clean:
	rm *.o Lab11
