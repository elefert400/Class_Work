Lab08: main.o minHeap.o maxHeap.o
	g++ -g -std=c++11 -Wall main.o minHeap.o maxHeap.o -o Lab08

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

minHeap.o: minHeap.h minHeap.cpp
	g++ -g -std=c++11 -Wall -c minHeap.cpp

maxHeap.o: maxHeap.h maxHeap.cpp
	g++ -g -std=c++11 -Wall -c maxHeap.cpp

clean:
	rm *.o Lab08
