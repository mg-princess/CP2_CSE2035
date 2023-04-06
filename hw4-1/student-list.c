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
    
    new_node->next = NULL;

    if(*phead == NULL){ //빈 리스트
        *phead = new_node;
    }
    else{ //리스트 요소존재
        StudentNode *cur_node = *phead;
        while(cur_node->next != NULL) cur_node = cur_node->next;
        cur_node->next = new_node;
    }
}

// TODO: Fill in this function.
void printStudentList(StudentNode *head) {
    while(head != NULL){
        switch(head->state){
            case Present:
                printf("%s is present.\n", head->name);
                break;
            case Late:
                printf("%s is late.\n", head->name);
                break;
            default:
                printf("%s is absent.\n", head->name);
        }
        head = head->next;
    }
}
