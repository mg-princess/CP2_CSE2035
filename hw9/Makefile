hw9.bin: lecture.o student.o main.cpp
	g++ lecture.o student.o main.cpp -o hw9.bin

lecture.o: lecture.hpp lecture.cpp
	g++ -c lecture.cpp

student.o: lecture.hpp univmem.hpp student.hpp student.cpp
	g++ -c student.cpp

clean:
	rm -f hw9.bin *.o

