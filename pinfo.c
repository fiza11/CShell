#include"headers.h"
//What?
void func_pinfo(char **a, int flag){
    long long pid;
    if(flag == 1){
        pid = 0;
        pid = getpid();
    }
    else{
        //removen(a[1]);
        int fi = 1, lf = strlen(a[1]), j;
        long long sum = 0;
        for(j = lf - 1; j >= 0; j--){
            sum += ((int)a[1][j] - 48)*fi;
            fi *= 10;
        }
    	pid = sum;
    }
	char procPath[MAX_BUFF]; char statPath[MAX_BUFF];// = "/proc/\0";
    procPath[0] = '/';
	procPath[1] = 'p';
	procPath[2] = 'r';
	procPath[3] = 'o';
	procPath[4] = 'c';
	procPath[5] = '/';
	procPath[6] = '\0';
	statPath[0] = '/';
	statPath[1] = 'p';
	statPath[2] = 'r';
	statPath[3] = 'o';
	statPath[4] = 'c';
	statPath[5] = '/';
	statPath[6] = '\0';
	char *EXEC = "/exe\0";
	char *STAT = "/stat\0";
	long long fr = pid, len = 0;
	while(fr > 0){
		fr /= 10;
		len++;
	}
	char PID[MAX_BUFF];
	fr = pid;
	for(int i = 0; i < len; i++){
		PID[len - 1 - i] = (char)(48 + (fr % 10));
		fr /= 10;
	}
	PID[len] = '\0';
	strcat(procPath, PID);
    char exec[MAX_BUFF];
    int i = 0, l = strlen(procPath);
    while(i < l){
        exec[i] = procPath[i];
        i++;
    }
    exec[i] = '\0';
	strcat(statPath, PID);
	strcat(procPath, EXEC);
	strcat(statPath, STAT);
	char str[MAX_BUFF];
	for(int i = 0; i < MAX_BUFF; i++){
        str[i] = '\0';
    }
	int val = readlink(procPath, str, MAX_BUFF);
	FILE * fd = fopen(statPath, "r");
	if(fd != NULL){
		char b[MAX_BUFF];
        int x;//, mem;
        char y; char z[MAX_BUFF];
        fscanf(fd, "%d", &x);//PID
        fscanf(fd, "%s", z);//name
        fscanf(fd, " %c", &y);//Status
        fprintf(stdout, "%spid -- %d\n", WHITE, x);
        fprintf(stdout, "%sProcess Status -- %c\n", WHITE, y);
        fclose(fd);
        strcpy(statPath, exec);
        strcat(statPath, "/statm");
        FILE *mem = fopen(statPath, "r");
        if(mem == NULL){
            perror("Error in opening the file");
            return;
        }
        int ms;
        fscanf(mem, "%d", &ms);
        fprintf(stdout, "%sMemory -- %d\n", WHITE, ms); //memorysize
        fclose(mem);
	}
	else{
		perror("Error in opening the file");
        return;
	}
	if(val == -1){
		perror("Error");
        return;
	}
	else{
		printf("%sExecutable Path -- %s\n", WHITE, str);
	}
	return;
}
