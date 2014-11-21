main:NICDevices.o main.o common.o IPMonitor.o
	g++ -o main NICDevices.o main.o common.o -lpcap
main.o: main.cpp
	g++ -c main.cpp -lpcap
common.o:common.cpp common.h
	g++ -c common.cpp
NICDevices.o:NICDevices.cpp NICDevices.h common.h
	g++ -c NICDevices.cpp -lpcap
IPMonitor.o:IPMonitor.cpp IPMonitor.h
	g++ -c IPMonitor.cpp -lpcap

clean:
	rm -f NICDevices.o IPMonitor.o main.o common.o
