#include <cstdio>
#include "lecture.hpp"
#include "student.hpp"

using std::cout;
using std::endl;

// TODO: Fill in these functions.

void Student::PrintGrade() {
    for(auto it = lectures.begin(); it != lectures.end(); ++it) {
        Grade grade;
        if(!(*it)->GetGradeOf(GetID(), &grade)) break;
        printf("%s : %s\n", (*it)->GetCode(), GradeToString(grade));
    }
}

bool Student::Register(Lecture *lec) {
    if(!lec->AddStudent(GetID()))
        return false;
    lectures.push_back(lec);
    
    return true;
}
