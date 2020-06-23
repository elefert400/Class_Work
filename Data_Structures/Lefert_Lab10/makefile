Lab10: main.o skew.o leftest.o node.o
	g++ -g -std=c++11 -Wall main.o skew.o leftest.o node.o -o Lab10

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

skew.o: skew.h skew.cpp
	g++ -g -std=c++11 -Wall -c skew.cpp

leftest.o: leftest.h leftest.cpp
	g++ -g -std=c++11 -Wall -c leftest.cpp

node.o: node.h node.cpp
	g++ -g -std=c++11 -Wall -c node.cpp

clean:
	rm *.o Lab10
