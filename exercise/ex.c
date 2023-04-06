#include <stdio.h>
#include <string.h>

#define BUFSIZE 32

// This is one possible solution.
size_t my_strlen(char *s) {
    size_t i = 0;
    while(*s++) // This is equal to while(*s++ != '\0')
        i++;
    return i;
}

int main(int argc, char ** argv) {
    char buf[BUFSIZE] = "";
    FILE *f_in;
    size_t len;

    if (argc != 2) {
        printf("Provide input file path as an argument\n");
        return -1;
    }

    f_in = fopen(argv[1], "r");
    if (!f_in) {
        printf("Failed to open the input file\n");
        return -1;
    }

    fgets(buf, BUFSIZE, f_in);
    // Replace the newline characters (\n or \r) with the null chracter.
    buf[strcspn(buf, "\r\n")] = '\0';
    fclose(f_in);

    len = my_strlen(buf);
    printf("%zu\n", len);

    return 0;
}
