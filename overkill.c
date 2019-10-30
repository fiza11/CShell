#include"headers.h"

void func_overkill(){
    int i = 0;
    while(job_no != 0){
        pid_t pid = job[i].id;
        int u = delete_job(pid);
        int j = kill(pid, 9);
        printf("j = %d\n", j);
        if(j == -1){
            fprintf(stderr, "%s\n", strerror(errno));
        }
    }
}
