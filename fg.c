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

 void fg(int no){
     int status, pid;
     if(no > job_no){
         printf("No such background process exists\n");
     }
     else{
         pid_t p1 = getpid();
         pid = job[no - 1].id;
         signal(SIGTTOU, SIG_IGN);
         signal(SIGTTIN, SIG_IGN);
         tcsetpgrp(0, getpgid(pid));
         kill(pid, SIGCONT);
         waitpid(pid, NULL, WUNTRACED);
         tcsetpgrp(0, p1);
         signal(SIGTTOU, SIG_DFL);
         signal(SIGTTIN, SIG_DFL);
         delete_job(pid);
     }
 }
