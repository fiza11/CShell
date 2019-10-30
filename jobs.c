#include"headers.h"

void list_jobs(){
    int a = 0, fr;
    while(a < job_no){
        char statPath[MAX_BUFF];
        statPath[0] = '/';
    	statPath[1] = 'p';
    	statPath[2] = 'r';
    	statPath[3] = 'o';
    	statPath[4] = 'c';
    	statPath[5] = '/';
    	statPath[6] = '\0';
        char *STAT = "/stat\0";
        int k;
        int fr = job[a].id, len = 0;
        if(fr < 0){
            continue;
        }
        char y;
    	while(fr > 0){
    		fr /= 10;
    		len++;
    	}
        char PID[MAX_BUFF];
    	fr = job[a].id;
    	for(int i = 0; i < len; i++){
    		PID[len - 1 - i] = (char)(48 + (fr % 10));
    		fr /= 10;
    	}
    	PID[len] = '\0';
        strcat(statPath, PID);
    	strcat(statPath, STAT);
        FILE * fd = fopen(statPath, "r");
        // char bb[1000];
        // int aa;
        // fscanf(fd, "%d %s %c", &aa, bb, &y);
        char c;
        char arr[100][100];
        int at = 0, b = 0;
        while((c = getc(fd)) != EOF){
            if(c == ' ' || c == '\n'){
                arr[at][b] = '\0';
                at++;
                b = 0;
            }
            else{
                arr[at][b] = c;
                b++;
            }
        }
        char status[100];
        strcpy(status, "\0");
        if(strcmp(arr[2], "T") == 0){
            strcpy(status, "Stopped");
        }
        else{
            strcpy(status, "Running");
        }
        printf("[%d] %s %s [%d]\n", a + 1, status, job[a].name, job[a].id);
        a++;
    }
}
