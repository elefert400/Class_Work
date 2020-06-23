Lab03: main.o hashTableDouble.o hashTableQuad.o
	g++ -g -std=c++11 -Wall main.o hashTableDouble.o hashTableQuad.o -o Lab03

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

hashTableDouble.o: hashTableDouble.h hashTableDouble.cpp
	g++ -g -std=c++11 -Wall -c hashTableDouble.cpp

hashTableQuad.o: hashTableQuad.h hashTableQuad.cpp
	g++ -g -std=c++11 -Wall -c hashTableQuad.cpp

clean:
	rm *.o Lab03
