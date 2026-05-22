#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");
    if (fp == NULL)
        return;

    char key[64];
    char value[64];
    while (fscanf(fp, " %[^=]=%s", key, value) == 2) {
        if (strcmp(key, "InputFileName") == 0)
            strncpy(config_ptr->InputFileName, value, 63);
        else if (strcmp(key, "Options") == 0)
            config_ptr->Options = atoi(value);
        else if (strcmp(key, "SectionName") == 0)
            strncpy(config_ptr->SectionName, value, 63);
        else if (strcmp(key, "Address") == 0)
            config_ptr->Address = strtoull(value, NULL, 0);
    }

    fclose(fp);
}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n",
        config.InputFileName,
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}
