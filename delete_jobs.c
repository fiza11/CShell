#include"headers.h"

int delete_job(pid_t pid){
    int j, flag = 0;
    for(int i = 0; i < job_no; i++){
        if(job[i].id == pid){
           j = i;
           flag = 1;
           strcpy(current_fg, job[i].name);
           break;
        }
    }
    if(flag == 0){
        return 0;
    }
    for(int i = j; i < job_no - 1; i++){
        job[i].id = job[i + 1].id;
        strcpy(job[i].name, job[i + 1].name);
    }
    job_no--;
    return 1;
}
