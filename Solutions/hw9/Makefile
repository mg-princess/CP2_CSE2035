hw9.bin: lecture.o student.o main.o
	g++ lecture.o student.o main.o -o hw9.bin

main.o: lecture.hpp univmem.hpp student.hpp main.cpp
	g++ -c main.cpp

lecture.o: lecture.hpp lecture.cpp
	g++ -c lecture.cpp

student.o: lecture.hpp univmem.hpp student.hpp student.cpp
	g++ -c student.cpp

clean:
	rm -f hw9.bin *.o

