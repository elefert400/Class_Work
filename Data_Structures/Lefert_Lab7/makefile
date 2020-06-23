Lab07: main.o twoThreeTree.o node.o
	g++ -g -std=c++11 -Wall main.o twoThreeTree.o node.o -o Lab07

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

twoThreeTree.o: twoThreeTree.h twoThreeTree.cpp
	g++ -g -std=c++11 -Wall -c twoThreeTree.cpp

node.o: node.h node.cpp
	g++ -g -std=c++11 -Wall -c node.cpp

clean:
	rm *.o Lab07
