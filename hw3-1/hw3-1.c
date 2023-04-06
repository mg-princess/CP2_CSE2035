#include <stdio.h>
#include <string.h>

#define BUFSIZE 32

// TODO: Fill in this function.
void reverse(char *s) {
    int len = strlen(s), i;
    for(i = 0; i<len/2; i++){
        char tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
    return;
}

// Don't touch this skeleton code.
int main(int argc, char ** argv) {
    char buf[BUFSIZE] = "";
    FILE *f_in;

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

    reverse(buf);
    printf("%s\n", buf);

    return 0;
}
