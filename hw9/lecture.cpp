#include "lecture.hpp"

// TODO: Fill in these functions.

bool Lecture::AddStudent(int id) {
    if(id_to_grade.count(id))
        return false;
    id_to_grade[id] = NA;
    return true;
}

bool Lecture::SetGradeOf(int id, Grade grade) {
    auto it = id_to_grade.find(id);
    if(it == id_to_grade.end()) 
        return false;
    id_to_grade[id] = grade;
    return true;
}

bool Lecture::GetGradeOf(int id, Grade *pGrade) {
    if(!id_to_grade.count(id))
        return false;
    *pGrade = id_to_grade.find(id)->second;
    return true;
}

int Lecture::CountGrade(Grade grade) {
    int cnt = 0;
    for(auto it = id_to_grade.begin(); it != id_to_grade.end(); ++it) {
        if(it->second == grade) cnt++;
    }
    return cnt;
}
