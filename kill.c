#include"headers.h"

void kill_job(int no, int signal){
    int y = 2;
    if(no >= job_no){
        printf("Job does not exist\n");
        return;
    }
    pid_t pid = job[no - 1].id;
    if(signal == 9){
        y = delete_job(pid);
    }
    if(y == 0){
        printf("Job does not exist\n");
        return;
    }
    int i = kill(pid, signal);
    if(i == -1){
        fprintf(stderr, "%s\n", strerror(errno));
    }
}
