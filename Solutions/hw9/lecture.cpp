#include "lecture.hpp"

// TODO: Fill in these functions.

bool Lecture::AddStudent(int id) {
    if (id_to_grade.count(id) != 0) {
        return false; // The student is already registered.
    }

    id_to_grade[id] = NA; // Otherwise, add student and initialize grade.
    return true;
}

bool Lecture::SetGradeOf(int id, Grade grade) {
    if (id_to_grade.count(id) == 0) {
        return false; // The student is not registered yet.
    }

    id_to_grade[id] = grade; // Otherwise, update the grade of student.
    return true;
}

bool Lecture::GetGradeOf(int id, Grade *pGrade) {
    if (id_to_grade.count(id) == 0) {
        return false; // The student is not registered yet.
    }

    *pGrade = id_to_grade[id]; // Otherwise, retrieve the value from the map.
    return true;
}

int Lecture::CountGrade(Grade grade) {
    int count = 0;
    for (auto it = id_to_grade.begin(); it != id_to_grade.end(); it++) {
        if (it->second == grade) {
            count++;
        }
    }
    return count;
}
