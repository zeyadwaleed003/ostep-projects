#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    int cnt;
    char c;
    for(int i = 1; i < argc; ++i){
        FILE *f = fopen(argv[1], "r");

        if(f == NULL){
            printf("wzip: cannot open file\n");
	        exit(1);
        }
        else{
            while(fread(&cnt, sizeof(int), 1, f) != 0){
                fread(&c, sizeof(char), 1, f);

                for(int j = 0; j < cnt; ++j){
                    printf("%c", c);
                }
            }
        }
    
        fclose(f);  
    }    
    return 0;
    
}