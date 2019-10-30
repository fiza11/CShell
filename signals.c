#include"headers.h"

void ctrlz(int signum){
        if(current_fg_pid < 0)
            return;
		int ff = 0;
		for(int ii = 0; ii < job_no; ii++){
			if(job[ii].id == current_fg_pid){
				ff = 1;
				break;
			}
		}
		if(ff == 0){
				strcpy(job[job_no].name, current_fg);
				job[job_no].id = current_fg_pid;
				job_no++;
		}
		kill(current_fg_pid, SIGSTOP);
        current_fg_pid = 0;
		fflush(stdout);
}

void ctrlc(int signum){
    // fprintf(stdout,"\nPress enter to continue");
    // fflush(stdout);
    return;
}

void chld(int signum){
    int stat;
    pid_t pid;
    pid = waitpid(-1, &stat, WNOHANG);
    if(pid > 0){
        delete_job(pid);
    }
    return;
}
