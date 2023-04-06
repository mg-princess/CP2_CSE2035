#include <cstdio>
#include "lecture.hpp"
#include "student.hpp"

using std::cout;
using std::endl;

// TODO: Fill in these functions.

void Student::PrintGrade() {
    for(int i = 0; i<lecture_cnt; i++) {
        Grade grade;
        if(!lectures[i]->GetGradeOf(this->GetID(), &grade)) break;
        printf("%s : %s\n", lectures[i]->GetCode(), GradeToString(grade));
    }
}

bool Student::Register(Lecture *lec) {
    
}
