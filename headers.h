#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<sys/stat.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>
#include<fcntl.h>
#include<linux/limits.h>
#include<signal.h>
#include<ctype.h>
#include<setjmp.h>
#define MAXCOM 1000
#define MAXLIST 100
#define MAX_BUFF 1000
#define SIZE 100
#define clear() printf("\033[H\033[J")
#define GREEN "\x1b[92m"
#define BLUE "\x1b[94m"
#define DEF "\x1B[0m"
#define CYAN "\x1b[96m"
#define PINK "\x1b[95m"
#define RED "\x1b[31m"
#define DARKPINK "\x1b[35m"
#define WHITE "\x1b[37m"

//Function Declarations
void func_ls();
void func_redirect1(char **command);
void exec_pipe_io(char *command);
void func_redirect2(char **command);
void func_redirect3(char **command);
void func_lsdir(char *name);
void func_lsa();
void func_lsl();
void func_lsal();
void init();
char* read_line();
char** split_line(char *line);
void func_pwd(char *c, int g);
void func_cd(char *path);
void removen(char *path);
void tilda(char *t, char *dest);
void func_pinfo(char **a, int flag);
void func_bg(char **a);
int func_fg(char **a);
char *trimwhitespace(char *str);
void handler(int sig);
void tail(FILE* in, int n);
void io_redir(char *command[], char *input, char *output, int flag);
void exec_pipe(char *arg1);
void func_echo(char ** command);
void ctrlz(int signum);
void ctrlc(int signum);
void chld(int signum);
int execute(char **command);
void list_jobs();
int delete_job(pid_t pid);
void kill_job(int no, int signal);
void func_overkill();
void signal_handler(int signum);
void shandler(int signum);
void set(char **command);
void unset(char **command);

//Variable Declarations
int size, sz;//, background = 0;
char cwd[1000];
int no_of_pipes;
char ft[1000], buff[1000], fi[1000];
char *yu;
char buf1[1000][1000];
int arr[MAX_BUFF];
typedef struct node{
    char name[1000];
    pid_t id;
}node;
node job[10000];
int job_no, foreground, czz;
pid_t fg_pid;
char fg_name[1000], command1[1000];
sigjmp_buf cz_buf;
char current_bg[MAX_BUFF];
int current_bg_pid;
char current_fg[MAX_BUFF];
int current_fg_pid;
