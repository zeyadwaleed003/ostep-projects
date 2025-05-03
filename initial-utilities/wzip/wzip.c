#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *f = NULL;

    // Create a temp file to merge all files in one file
    // The '+' in "w+" means reading and writing
    FILE *tmpFile = fopen("tmpFile.txt", "w+");

    char *line = NULL;
    size_t len = 0;

    // Now all the files content are in the temp file
    for(int i = 1; i < argc; ++i){
        f = fopen(argv[1], "r");

        if(f == NULL){
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while(getline(&line, &len, f) != EOF){
            fprintf(tmpFile, "%s", line);
        }

        fclose(f);
    }

    rewind(tmpFile);

    int cnt = 0;
    char currentChar, lastChar = EOF;
    while((currentChar = (char)fgetc(tmpFile)) != EOF){
        if(lastChar == EOF || lastChar == currentChar){
            ++cnt;
            lastChar = currentChar;
        }
        else{
            fwrite(&cnt, sizeof(cnt), 1, stdout);
            putchar(lastChar);

            cnt = 1;
            lastChar = currentChar;
        }
    }

    fwrite(&cnt, sizeof(cnt), 1, stdout);
    putchar(lastChar);

    fclose(tmpFile);

    remove("tmpFile.txt");

    tmpFile = NULL;
    return 0;
}