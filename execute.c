#include"headers.h"

int execute(char **command){
    pid_t pid, pid2;
    int bg = 0, status, i = 0;
    while(command[i] != NULL){
        if(strcmp(command[i],"&") == 0 && command[i + 1] == NULL){
            bg = 1;
            break;
        }
        i++;
    }
    pid = fork();
    printf("%d\n", pid);
    if (pid < 0){
        perror("ERROR");
        return 1;
    }
    if(pid == 0){
        if(execvp(command[0], command) == -1){
            fprintf(stderr,"Command: %s not found\n", command[0]);
            exit(EXIT_FAILURE);
        }
    }
    if(bg == 0){
        pid2 = waitpid(pid, &status, WUNTRACED);
        while(1){
            if(!WIFEXITED(status) && !WIFSIGNALED(status)){
                pid2 = waitpid (pid, &status, WUNTRACED);
                continue;
            }
            break;
        }
    }
    return 1;
}
