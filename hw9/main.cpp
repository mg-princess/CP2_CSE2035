#include <iostream>
#include "lecture.hpp"
#include "student.hpp"

using std::cout;

// I will fix this function to test your class implementation
void test() {
    Lecture *lec1 = new Lecture("CSE2015");
    Lecture *lec2 = new Lecture("CSE2035");
    Student *s1 = new Student(20220001, "Alice");
    Student *s2 = new Student(20220002, "Brian");
    Student *s3 = new Student(20220003, "Chris");

    // The following lines should print this:
    // Alice(20220001)
    // CSE2015 : B
    // CSE2035 : NA
    // =============
    s1->Register(lec1);
    s1->Register(lec2);
    lec1->SetGradeOf(20220001, B);
    s1->Print();
    s1->PrintGrade();
    cout << "=============\n";

    // The following lines should print this:
    // Brian(20220002)
    // CSE2015 : A
    // CSE2035 : C
    // =============
    s2->Register(lec1);
    s2->Register(lec2);
    lec1->SetGradeOf(20220002, A);
    lec2->SetGradeOf(20220002, C);
    s2->Print();
    s2->PrintGrade();
    cout << "=============\n";

    // The following lines should print this:
    // Chris(20220003)
    // CSE2015 : A
    // CSE2035 : NA
    // =============
    s3->Register(lec1);
    s3->Register(lec2);
    lec1->SetGradeOf(20220003, B);
    lec1->SetGradeOf(20220003, A); // Overwrite previous 'B' with 'A'
    s3->Print();
    s3->PrintGrade();
    cout << "=============\n";

    // The following line should print this:
    // Total 2 student(s) received A
    // Total 1 student(s) received B
    // =============
    lec1->SetGradeOf(20230001, A); // Does not exist, so ignored
    lec1->SetGradeOf(20230002, B); // Does not exist, so ignored
    cout << "Total " << lec1->CountGrade(A) << " student(s) received A\n";
    cout << "Total " << lec1->CountGrade(B) << " student(s) received B\n";
    cout << "=============\n";

    delete lec1;
    delete lec2;
    delete s1;
    delete s2;
    delete s3;
}

int main() {
    test();
    return 0;
}
