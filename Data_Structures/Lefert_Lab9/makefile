Lab09: main.o minMax.o
	g++ -g -std=c++11 -Wall main.o minMax.o -o Lab09

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

minHeap.o: minMax.h minMax.cpp
	g++ -g -std=c++11 -Wall -c minMax.cpp

clean:
	rm *.o Lab09
