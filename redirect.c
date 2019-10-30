#include"headers.h"
void func_redirect1(char **command){
    char *extra[MAX_BUFF];//[MAX_BUFF];
	int ir = 0;
	int i_flag = 0;
	while(command[ir] != NULL){
		if(strcmp(command[ir], "<") == 0){
			i_flag = ir;
			break;
		}
		extra[ir] = command[ir];
		ir++;
	}
	int size = 0;
	while(command[ir] != NULL)
		ir++;
	size = ir;
	ir--;
	char *output[MAX_BUFF];
	while(command[ir] != NULL){
		if(strcmp(command[ir], ">") == 0){
	    	io_redir(extra, command[i_flag + 1], command[ir + 1], 1);
			extra[i_flag] = NULL;
		    int pid;
			if((pid = fork()) == -1){
				perror("Child process could not be created");
			}
			if(pid == 0){
				if(execvp(extra[0], extra) == -1){
					perror("Error");
				}
			}
		}
		if(strcmp(command[ir], ">>") == 0){
		io_redir(extra, NULL, command[ir + 1], 2);
		extra[i_flag] = NULL;
		int pid;
		if((pid = fork()) == -1){
			perror("Child process could not be created");
		}
		if(pid == 0){
			if(execvp(extra[0], extra) == -1){
				perror("Error");
			}
		}
	}
	ir--;
	}
}
void func_redirect2(char **command){
    			char *extra[MAX_BUFF];
				int ir = 0;
				int i_flag = 0;
				while(command[ir] != NULL){
					if((strcmp(command[ir], ">") == 0) || (strcmp(command[ir], ">>") == 0)){
						i_flag = ir;
						break;
					}
					extra[ir] = command[ir];
					ir++;
				}
				int size = 0;
				while(command[ir] != NULL)
					ir++;
				size = ir;
				ir--;
				while(command[ir] != NULL){
					if(strcmp(command[ir], ">") == 0){
						io_redir(extra, NULL, command[ir +1], 0);
						extra[i_flag] = NULL;
						int pid;
						if((pid = fork()) == -1){
							perror("Child process could not be created");
						}
						if(pid == 0){
							if(execvp(extra[0], extra) == -1){
								perror("Error");
							}
						}
					}
					else if(strcmp(command[ir], ">>") == 0){
						io_redir(extra, NULL, command[ir + 1], 2);
						extra[i_flag] = NULL;
						int pid;
						if((pid = fork()) == -1){
							perror("Child process could not be created");
						}
						if(pid == 0){
							if(execvp(extra[0], extra) == -1){
								perror("Error");
							}
						}
					}
					ir--;
				}
}
void func_redirect3(char **command){
				char *extra[MAX_BUFF];
				int ir = 0;
				int i_flag = 0;
				while(command[ir] != NULL){
					if(strcmp(command[ir], "<") == 0){
						i_flag = ir;
						break;
					}
					extra[ir] = command[ir];
					ir++;
				}
				//printf("f%sf", extra[ir]);
				ir = 0;
				while(command[ir] != NULL){
					if(strcmp(command[ir], "<") == 0){
						io_redir(extra, command[ir + 1], NULL, 1);
						extra[ir] = NULL;
						int pid;
						if((pid = fork()) == -1){
							perror("Child process could not be created");
						}
						if(pid == 0){
							if(execvp(extra[0], extra) == -1){
								perror("Error");
							}
						}
					}
					ir++;
				}    
}