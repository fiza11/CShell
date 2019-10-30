#include"headers.h"

int func_fg(char **a){
     strcpy(current_fg, a[0]);
     pid_t pid;
     pid = fork();
     int stat;
     if(pid < 0){
         perror("Error");
         _exit(1);
     }
     else if(pid == 0){
         if(execvp(a[0], a) == -1){
             printf("Error : Command not found");
         }
         exit(0);
     }
     else{
         int status;
         current_fg_pid = pid;
         fg_pid = pid;
         czz = 0;
         waitpid(pid, &status, WUNTRACED);
     }
     return 0;
 }
