#include"headers.h"

void set(char **command){
    if(command[3] != NULL){
        printf("Error: Command requires maximum of two arguments\n");
        return;
    }
    if(command[2][0] == '\0'){
        setenv(command[1], " ", 1);
    }
    else{
        setenv(command[1], command[2], 1);
        printf("%s", getenv(command[1]));
    }
    return;
}

void unset(char **command){
    unsetenv(command[1]);
}
