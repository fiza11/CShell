#include"headers.h"
void func_cd(char *path){
        int f = chdir(path);
        if(f == 0){
                func_pwd(cwd, 0);
        }
        else perror("Error");
}
