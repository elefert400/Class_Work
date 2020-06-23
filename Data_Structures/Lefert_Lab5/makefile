Lab05: main.o binarySearchTree.o node.o
	g++ -g -std=c++11 -Wall main.o binarySearchTree.o node.o -o Lab05

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

binarySearchTree.o: binarySearchTree.h binarySearchTree.cpp
	g++ -g -std=c++11 -Wall -c binarySearchTree.cpp

node.o: node.h node.cpp
	g++ -g -std=c++11 -Wall -c node.cpp

clean:
	rm *.o Lab05
