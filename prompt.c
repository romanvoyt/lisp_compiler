#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer [2048];

char* readline (char* prompt){
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

void add_history(char* unused){}

#else
#include <editline.h>
#endif

int main(int argc, char const *argv[])
{
    puts("Lisp version 0.1");
    puts("Press ctrl+c to exit\n");
    
    while (1)
    {
        char* input = readline("lisp > ");
        
        add_history(input);

        printf("No you are a %s\n", input);

        free(input);
    }
    return 0;
}
