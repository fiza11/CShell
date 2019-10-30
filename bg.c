#include"headers.h"

void func_bg(char **a){
     //pid_t is a data type to represent process id
     pid_t pid;
     pid = fork(); //creates a child process
     //setpgid(0, 0);
     strcpy(job[job_no].name, a[0]);
     job[job_no].id = pid;
     job_no++;
     int status;
     current_bg_pid = pid;
     if(pid < 0){
         perror("Error"); //no child process created
         return;
     }
     else if(pid == 0){
         if (signal(SIGINT, shandler) == SIG_ERR)
     		sleep(0);
     	signal(SIGTSTP, shandler);
     	if (signal(SIGTSTP, signal_handler));
     	while(sigsetjmp(cz_buf, 1) != 0);
         //Returned to the newly created child process
         if(execvp(a[0], a) == -1){
             perror("Error");
         }
         exit(0);
     }
     else{
         signal(SIGCHLD, handler);
         return;
     }
     return;
 }
