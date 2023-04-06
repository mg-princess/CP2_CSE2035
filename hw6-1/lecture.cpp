#include "lecture.hpp"
// TODO: Fill in these functions.

bool Lecture::AddStudent(int id) {
    if(student_cnt >= MAX_STUDENT)
        return false;

    for(int i = 0; i<student_cnt; i++){
        if(ids[i] == id) return false;
    }
    ids[student_cnt] = id;
    grades[student_cnt] = NA;
    student_cnt++;
    return true;
}

bool Lecture::SetGradeOf(int id, Grade grade) {
    for(int i = 0; i<student_cnt; i++){
        if(ids[i] == id) {
            grades[i] = grade;
            return true;
        }
    }
    return false;
}

bool Lecture::GetGradeOf(int id, Grade *pGrade) {
    for(int i = 0; i<student_cnt; i++){
        if(ids[i] == id) {
            *pGrade = grades[i];
            return true;
        }
    }
    return false;
}