#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char buf[64];

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';
        if (strlen(buf) == 0)
            continue;

        char* endptr;
        long val = strtol(buf, &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "invalid input %s\n", buf);
        } else {
            sum += (int)val;
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
