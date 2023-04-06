#ifndef STUDENT_CLASSS
#define STUDENT_CLASSS

#include <iostream>
#include <vector>
#include "lecture.hpp"
#include "univmem.hpp"

class Student: public UnivMem {
private:
    std::vector<Lecture*> lectures;
public:
    Student(int _id, const char *_name): UnivMem(_id, _name)
    { }

    // Print the grades of this student. For each of the lecture, print its
    // lecture code and the student's grade in the following format:
    // "<lecture code> : <grade string>\n"
    // You can use GradeToString() function provided in lecture.hpp file.
    void PrintGrade();

    // Add this student to 'lec'. Return false if this registration was
    // unsuccessful. If the registration was successful, add 'lec' at the end of
    // the 'lectures' vector, and then return true.
    bool Register(Lecture *lec);
};

#endif
