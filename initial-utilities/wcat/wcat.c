#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    if(argc < 2){
        exit(0);
    }

    int c = 0;
    while(++c < argc){
        // Open file (read-only mode)
        FILE *fp = fopen(argv[c], "r");
        if(fp == NULL){
            printf("wcat: cannot open file\n");
            exit(1); // 1 indicates failure in UNIX systems 
        }

        // Read file content and display it
        char buffer[BUFFER_SIZE];
        while(fgets(buffer, BUFFER_SIZE, fp) != NULL){
            printf("%s", buffer);
        }

        // Close file
        fclose(fp);
    }
    return 0;
}