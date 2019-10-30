#include"headers.h"
void io_redir(char *command[], char *input, char *output, int flag){
    int pid;
    if((pid = fork()) < 0){
        printf("Child process could not be created\n");
        return;
    }
    if(pid == 0){
        int fdo, fdi;
        int x, y;

        //Input Redirection
        if(flag == 1){
            fdi = open(input, O_RDONLY, 0600);
            if(fdi < 0){
                perror("Couldn't open the input file");
                exit(0);
            }
            dup2(fdi, STDIN_FILENO);
            close(fdi);
            if(output != NULL){            
                fdi = open(output, O_CREAT | O_TRUNC | O_WRONLY, 0644);
                dup2(fdi, STDOUT_FILENO);
                close(fdi);
            }
        }
        else if(flag == 0){
            fdo = open(output, O_CREAT | O_TRUNC | O_WRONLY, 0644);
            if(fdo < 0){
                perror("Couldn't open the output file");
                exit(0);
            }
            dup2(fdo, STDOUT_FILENO);
            close(fdo);
        }
        else if(flag == 2){
            fdo = open(output, O_APPEND | O_RDWR | O_CREAT, 0644);
            if(fdo < 0){
                perror("Couldn't open the output file");
                exit(0);
            }
            dup2(fdo, STDOUT_FILENO);
            close(fdo);
        }
        if(execvp(command[0], command) == -1){
            perror("execvp");
        }
    }
    else{
        int status;
        while(!(wait(&status) == pid));
    }
}