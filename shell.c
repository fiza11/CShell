#include "headers.h"
int main(){
	int y = 1;
	func_pwd(cwd, 0);
	func_pwd(ft, 0); //home directory
	clear();
	int background;
	job_no = 0;
	if (signal(SIGINT, shandler) == SIG_ERR)
		sleep(0);
	signal(SIGTSTP, ctrlz);
	while(sigsetjmp(cz_buf, 1) != 0);
	while(y){
		background = 0, foreground = 0;
		yu = getcwd(buff, 1000);
		yu[(int)strlen(yu) + 1] = '\0';
		init();
		if((int)strlen(ft) <= (int)strlen(yu)){
			tilda(yu, fi);
			printf("%s%s >> ", PINK, fi);
		}
		else{
			printf("%s%s >> ", PINK, yu);
		}
		char *c = read_line();
    	char **ts = split_line(c);
		int i = 0;
		int pipe = 0, redirect = 0;
		while(i < size){
			char cds[MAX_BUFF];
			strcpy(cds, ts[i]);
			strcpy(command1, "\0");
			background = 0;
			char *command[1000];
			command[0] = strtok(ts[i], " ");
			int tok = 0;
			while(command[tok] != NULL){
				tok++;
				command[tok] = strtok(NULL, " ");
			}
			if(command[tok - 1][0] == '&'){
				command[tok - 1] = '\0';
				background = 1;
			}
			i++;
			int ex = 0, inp = 0, out = 0, ir = 0;
			while(command[ir] != NULL){
				if((strcmp(command[ir], "<") == 0) || (strcmp(command[ir], ">") == 0) || (strcmp(command[ir], ">>") == 0)){
					redirect = 1;
				}
				if(strcmp(command[ir], "|") == 0){
					pipe = 1;
				}
				if((strcmp(command[ir], ">") == 0) || (strcmp(command[ir], ">>") == 0)){
					out++;
				}
				if(strcmp(command[ir], "<") == 0)
					inp++;
				ir++;
			}
			if(inp && out && !pipe){
				func_redirect1(command);
			}
			else if(out && !pipe){
				func_redirect2(command);
			}
			else if(inp && !pipe){
				func_redirect3(command);
			}
			else if(pipe){
				exec_pipe(cds);
			}
			else if(strcmp(command[0], "quit") == 0 && !background){
				y = 0;
			}
			else if(strcmp(command[0], "overkill") == 0 && !background){
				func_overkill();
			}
			else if(strcmp(command[0], "clear") == 0 && !background){
				clear();
			}
			else if(strcmp(command[0], "pwd") == 0 && !background){
				func_pwd(cwd, 1);
			}
			else if(strcmp(command[0], "setenv") == 0 && !background){
				set(command);
			}
			else if(strcmp(command[0], "unsetenv") == 0 && !background){
				unset(command);
			}
			else if(strcmp(command[0], "cd") == 0 && !background){
				if(strcmp(command[1], "~") == 0){
					chdir(ft);
					func_pwd(cwd, 0);
					continue;
				}
				char *path = command[1];
				func_cd(path);
			}
			else if(strcmp(command[0], "echo") == 0 && !background){
				func_echo(command);
			}
			else if(strcmp(command[0], "ls") == 0 && !background){
				if(tok == 1){
					func_ls();
				}
				else if(strcmp(command[1], "-l") == 0){
					func_lsl();
				}
				else if(strcmp(command[1], "-al") == 0 || strcmp(command[1], "-la") == 0){
					func_lsal();
				}
				else if(strcmp(command[1], "-a") == 0){
					func_lsa();
				}
				else{
					func_lsdir(command[1]);
				}

			}
			else if(strcmp(command[0], "fg") == 0 && !background){
				fg(atoi(command[1]));
			}
			else if(strcmp(command[0], "bg") == 0 && !background){
				if(command[1] == NULL){
					printf("Incorrect number of arguments");
				}
				else bg(atoi(command[1]));
			}
			else if(strcmp(command[0], "kjob") == 0 && !background){
				kill_job(atoi(command[1]), atoi(command[2]));
			}
			else if(strcmp(command[0], "pinfo") == 0 && !background){
				if(!command[1])
					func_pinfo(command, 1);
				else func_pinfo(command, 0);
			}
			else if(strcmp(command[0], "jobs") == 0 && !background){
				list_jobs();
			}
			else if(background == 1){
				func_bg(command);
				strcpy(current_bg, command[0]);
			}
			else{
				czz = 0;
				foreground = 1;
				strcpy(fg_name, command[0]);
				func_fg(command);
			}
		}
	}
}
