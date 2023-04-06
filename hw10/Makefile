hw10.bin: list.o main.o
	g++ list.o main.o -o hw10.bin

list.o: node.hpp list.hpp list.cpp
	g++ -c list.cpp

main.o: node.hpp list.hpp main.cpp
	g++ -c main.cpp

clean:
	rm -f hw10.bin *.o

