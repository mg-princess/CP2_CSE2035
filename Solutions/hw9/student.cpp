#include <cstdio>
#include "lecture.hpp"
#include "student.hpp"

using std::cout;
using std::endl;

// TODO: Fill in these functions.

void Student::PrintGrade() {
    for (auto it = lectures.begin(); it != lectures.end(); it++) {
        Lecture *lec = *it;
        const char * code = lec->GetCode();
        Grade grade;
        if (lec->GetGradeOf(this->GetID(), &grade)) {
            cout << code << " : " << GradeToString(grade) << endl;
        }
    }
}

bool Student::Register(Lecture *lec) {
    if (!lec->AddStudent(this->GetID())) {
        return false;
    }

    lectures.push_back(lec);
    return true;
}
