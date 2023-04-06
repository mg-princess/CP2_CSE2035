// This is called a 'header guard'
#ifndef LECTURE_CLASSS
#define LECTURE_CLASSS

#include <string>
#include <map>

enum Grade { A, B, C, NA }; // NA means "not available yet".

inline const char * GradeToString(Grade g) {
    switch(g) {
        case A:
            return "A";
        case B:
            return "B";
        case C:
            return "C";
        case NA:
        default:
            return "NA";
    }
}

class Lecture {
private:
    std::string code;
    std::map<int,Grade> id_to_grade;
public:
    Lecture(const char * _code) {
        code = _code; // Automatically converted and stored as std::string.
    }

    ~Lecture() { } // You don't have to do anything in destructor.

    const char* GetCode() { return code.c_str(); }

    // Add a student whose ID is 'id'. The student's grade must be initialized
    // as 'NA'. If the lecture the provided ID is already present in this
    // lecture, don't add the student and just return false.
    bool AddStudent(int id);

    // Update the grade of the student whose ID is 'id' into 'grade'. If such
    // a student doesn't exist, just return false.
    bool SetGradeOf(int id, Grade grade);

    // Get the grade of the student whose ID is 'id', and store it at '*pGrade'.
    // If such a student doesn't exist, just return false.
    bool GetGradeOf(int id, Grade *pGrade);

    // Count how many 'grade' was given to the students in this lecture.
    int CountGrade(Grade grade);
};

#endif
