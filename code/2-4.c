#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");

    int freq[26] = {0};
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c >= 'a' && c <= 'z')
            freq[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        printf("%c: %d\n", 'a' + i, freq[i]);

    fclose(fp);
}
