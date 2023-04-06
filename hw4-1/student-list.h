// This is called a 'header guard'
#ifndef STUDENT_LIST
#define STUDENT_LIST

#define MAX_NAMELEN 64

typedef enum { Present, Late, Absent } Attendance;

typedef struct StudentNode {
    char name[MAX_NAMELEN + 1];
    Attendance state;
    struct StudentNode* next;
} StudentNode;

// Function bodies are implemented in student-list.c file. Fill in the function
// bodies in that file (in other words, do not touch this file).
void addStudentAtEnd(StudentNode **phead, char *name, int hour, int minute);
void printStudentList(StudentNode *head);

#endif
