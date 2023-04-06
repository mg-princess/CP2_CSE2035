#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student-list.h"

// TODO: Fill in this function.
void addStudentAtEnd(StudentNode **phead, char *name, int hour, int minute) {
    StudentNode *new_node = (StudentNode *) malloc(sizeof(StudentNode));
    Attendance state = Absent;
    
    strncpy(new_node->name, name, MAX_NAMELEN);
    new_node->name[strlen(new_node->name)] = '\0';
    if(hour<=9){
        if(hour < 9 || minute == 0) state = Present;
        else if(minute <= 15) state = Late;
    } 
    new_node->state = state;
    new_node->next = *phead;
    *phead = new_node;
}

// TODO: Fill in this function.
void printStudentList(StudentNode *head) {
    while(head != NULL){
        if(head->state == Present)
            printf("%s is Present\n", head->name);
        else if(head->state == Late)
            printf("%s is Late\n", head->name);
        else printf("%s is Absent\n", head->name);

        head = head->next;
    }
}
