hw11.bin: string.o main.o
	g++ string.o main.o -o hw11.bin

string.o: string.hpp string.cpp
	g++ -c string.cpp

main.o: string.hpp main.cpp
	g++ -c main.cpp

clean:
	rm -f hw11.bin *.o

