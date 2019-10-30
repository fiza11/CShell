#include"headers.h"

void func_echo(char ** command){
    if(command[1][0] == '$'){
        char var[1000];
        int po;
        for(po = 1; po < (int)strlen(command[1]); po++)
            var[po - 1] = command[1][po];
        var[po - 1] = '\0';
        if(getenv(var) != NULL)
            printf("%s", getenv(var));
        else printf("Environment not found");
    }
    else {
        int ir = 1;
        while(command[ir] != NULL){
            printf("%s ", command[ir]);
            ir++;
        }
    }
}
