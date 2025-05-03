#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void READ(FILE *fp, const char *search_str){
    char *line = NULL;
    size_t len = 0;
    while(getline(&line, &len, fp) != -1){
        if(strstr(line, search_str) != NULL)
            printf("%s", line);
    }

    free(line);
}

int main(int argc, char *argv[]) {
    // argv[1] => The term I am looking for
    if(argc < 2){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    const char *search_str = argv[1];

    FILE *fp = stdin; // Default to standard input
    if(argc > 2) {
        int c = 1;
        while(++c < argc){
            fp = fopen(argv[c], "r");
            if(fp == NULL){
                printf("wgrep: cannot open file\n");
                exit(1);  
            }
        }  
        
        READ(fp, search_str);
        fclose(fp);
    }
    else {
        READ(fp, search_str);
    }
    
    return 0;
}