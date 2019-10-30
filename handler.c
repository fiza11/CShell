#include"headers.h"

void handler(int sig){
    pid_t pid;
    char *exit_status = (char *)calloc(1000, sizeof(char));
    char *exit = (char *)calloc(1000, sizeof(char));
    int stat;
    pid = waitpid(0, &stat, WNOHANG); //WNOHANG means parent does not wait if child does not terminate just check and return waitpid()
    sprintf(exit, "\nProcess with pid %d exited ", pid);
    if(WIFEXITED(stat)){
        delete_job(pid);
            sprintf(exit_status, "normally\n");
    }
    else if(WIFEXITED(stat) == 0){
            sprintf(exit_status, "abnormally\n");
    }
    else if(WIFSIGNALED(stat)){
        psignal(WTERMSIG(stat), "Exit signal");
    }
    if(pid > 0){
        write(2, exit, strlen(exit));
        write(2, exit_status, strlen(exit_status));
    }
    free(exit);
    return;
}

void signal_handler(int signum){
    if(job_no > 0)
        czz = 1;
    if(signum == SIGTSTP && foreground == 1 && czz == 1){
        if(command1 != '\0'){
            printf("Pushing it in background");
            sleep(0);
            printf("\n");
            siglongjmp(cz_buf, 1);
        }
        else{
            printf("Hello\n");
            kill(job[job_no - 1].id, 9);
            delete_job(job[job_no - 1].id);
            siglongjmp(cz_buf, 1);
        }
    }
}

void shandler(int signum){
    if(signum == SIGUSR1 || signum == SIGKILL || signum == SIGSTOP || signum == SIGINT || signum == SIGTSTP || signum == SIGCHLD)
        sleep(0);
    if(signum != SIGCHLD)
        siglongjmp(cz_buf, 1);
}
