#include <stdio.h>
#include <string.h>

#define INPUT_BUFSIZE 32
#define DST_BUFSIZE 16



// TODO: Fill in this function.
void safe_strcat(char *dst, char *src, size_t sz) {
    while(*dst++) sz--;
    *dst--;
    while(sz-- && *src) 
        *dst++ = *src++;
    *dst = '\0';
    return;
}

// Don't touch this skeleton code.
int main(int argc, char ** argv) {
    char buf[INPUT_BUFSIZE] = "";
    char dst[DST_BUFSIZE];
    char danger_zone[16] = "Dummy";
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

    fgets(buf, INPUT_BUFSIZE, f_in);
    // Replace the newline characters (\n or \r) with the null chracter.
    buf[strcspn(buf, "\r\n")] = '\0';
    fclose(f_in);

    // Initialize 'dst' with special characters.
    memset(dst, '#', DST_BUFSIZE);
    // Now put the first string in 'dst'.
    strcpy(dst, "[CSE]");
    // Append the input string after the first string in 'dst'.
    safe_strcat(dst, buf, DST_BUFSIZE);

    printf("%s\n", dst);

    return 0;
}
