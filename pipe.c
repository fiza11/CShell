#include"headers.h"

void exec_pipe(char *command){
	int i = 0;
	char *pipe_args[MAX_BUFF], *token, *arg[1000][1000];
	token = strtok(command, "|");
	pipe_args[i] = token;
	i++;
	while(token != NULL){
		token = strtok(NULL, "|");
		pipe_args[i] = token;
		i++;
	}
	pipe_args[i] = NULL;
    int j = 0, k = 0, len = i - 1;
    i = 0;
	while(i < len){
		j = 0;
		token = strtok(pipe_args[i], " ");
		arg[i][j] = token;
		j++;
		while(token != NULL){
			token = strtok(NULL, " ");
			arg[i][j] = token;
			j++;
		}
		arg[i][j] = NULL;
        i++;
	}
    int fd1[2], fd2[2];
    for(i = 0; i < len; i++){
    	if(i % 2 == 0){
    		if(pipe(fd1) < 0) {   
                perror("Error");
                return;
            }
            pid_t p1 = fork();
            if(p1 < 0){
                perror("Forking failed");
                return;
            }
            else if(p1 == 0){
                if (i != 0){
                    dup2(fd2[0], STDIN_FILENO);
                }
                if (i != len - 1){
                    dup2(fd1[1], STDOUT_FILENO);
                }
                if(execvp(arg[i][0], arg[i]) < 0){
                  perror("Error in executing the command");
                  return;
                }
            } 
            else{
                if(i != 0){
                    close(fd2[0]);
                }
                if (i != len - 1){
                    close(fd1[1]);
                }
                wait(NULL);
            }
        }
        else{
        	if(pipe(fd2) < 0){   
                perror("Error");
                return;
            }
            pid_t p1 = fork();
            if(p1 < 0){
                perror("Forking failed");
                return;
            }
            else if(p1 == 0){
                dup2(fd1[0], STDIN_FILENO);
                if(i != len - 1){
                    dup2(fd2[1], STDOUT_FILENO);
                }
                if(execvp(arg[i][0], arg[i]) < 0){
                    perror("Error in executing the command");
                    return;
                }
            } 
            else{
                close(fd1[0]);
                if (i != len - 1){
                    close(fd2[1]);
                }
            }
                wait(NULL);
            }
        }
}

// void exec_pipe_io(char *command){
//     int i = 0;
// 	char *pipe_args[MAX_BUFF], *token, *arg[1000][1000];
// 	token = strtok(command, "|");
// 	pipe_args[i] = token;
// 	i++;
// 	while(token != NULL){
// 		token = strtok(NULL, "|");
// 		pipe_args[i] = token;
// 		i++;
// 	}
// 	pipe_args[i] = NULL;
//     int j = 0, k = 0, len = i - 1;
//     i = 0;
// 	while(i < len){
// 		j = 0;
// 		token = strtok(pipe_args[i], " ");
// 		arg[i][j] = token;
// 		j++;
// 		while(token != NULL){
// 			token = strtok(NULL, " ");
// 			arg[i][j] = token;
// 			j++;
// 		}
// 		arg[i][j] = NULL;
//         i++;
// 	}
//     int fd1[2], fd2[2];
//     for(i = 0; i < len; i++){
//         int jj = 0, inp = 0, out = 0;
//         while(arg[i][jj] != NULL){
//             if(strcmp(arg[i][jj], '<') == 0)
//                 inp++;
//             else if(strcmp(arg[i][jj], '>') == 0 || strcmp(arg[i][jj], '>>') == 0)
//                 out++;
//             jj++;
//         }
//         if(inp && out){
// 			func_redirect1(arg[i]);
// 		}
// 		else if(out){
// 			func_redirect2(arg[i]);
// 		}
// 		else if(inp){
// 			func_redirect3(arg[i]);
// 		}
//     	if(i % 2 == 0){
//     		if(pipe(fd1) < 0) {   
//                 perror("Error");
//                 return;
//             }
//             pid_t p1 = fork();
//             if(p1 < 0){
//                 perror("Forking failed");
//                 return;
//             }
//             else if(p1 == 0){
//                 if (i != 0){
//                     dup2(fd2[0], STDIN_FILENO);
//                 }
//                 if (i != len - 1){
//                     dup2(fd1[1], STDOUT_FILENO);
//                 }
//                 if(execvp(arg[i][0], arg[i]) < 0){
//                   perror("Error in executing the command");
//                   return;
//                 }
//             } 
//             else{
//                 if(i != 0){
//                     close(fd2[0]);
//                 }
//                 if (i != len - 1){
//                     close(fd1[1]);
//                 }
//                 wait(NULL);
//             }
//         }
//         else{
//         	if(pipe(fd2) < 0){   
//                 perror("Error");
//                 return;
//             }
//             pid_t p1 = fork();
//             if(p1 < 0){
//                 perror("Forking failed");
//                 return;
//             }
//             else if(p1 == 0){
//                 dup2(fd1[0], STDIN_FILENO);
//                 if(i != len - 1){
//                     dup2(fd2[1], STDOUT_FILENO);
//                 }
//                 if(execvp(arg[i][0], arg[i]) < 0){
//                     perror("Error in executing the command");
//                     return;
//                 }
//             } 
//             else{
//                 close(fd1[0]);
//                 if (i != len - 1){
//                     close(fd2[1]);
//                 }
//             }
//                 wait(NULL);
//             }
//         }
// }