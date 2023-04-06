#include <stdio.h>
#include <string.h>
#include "student-list.h"

#define BUFSIZE 128

// Don't touch this skeleton code.
int main(int argc, char ** argv) {
    char linebuf[BUFSIZE] = "";
    char namebuf[BUFSIZE + 1] = "";
    int hour, minute;
    FILE *fp;
    StudentNode *head = NULL;

    if (argc != 2) {
        printf("Provide input file path as an argument\n");
        return -1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Failed to open the input file\n");
        return -1;
    }
    while (fgets(linebuf, BUFSIZE, fp) != NULL) {
        if (sscanf(linebuf, "%s %d %d", namebuf, &hour, &minute) == EOF)
            break;
        addStudentAtEnd(&head, namebuf, hour, minute);
    }

    printStudentList(head);

    fclose(fp);

    return 0;
}
