#include"headers.h"

void func_ls(){
    int i = 0;
    struct dirent **lr;
    int no = scandir(".", &lr, 0, alphasort); //lr points to allocated array of pointers to allocated strings
    if (no >= 0){
        for(i = 0; i < no; i++ ){
            if(strcmp(lr[i]->d_name, ".") == 0 || strcmp(lr[i]->d_name, "..") == 0){
                continue;
            }
            else{
				printf("%s%s", WHITE, lr[i]->d_name);
			}
			printf("\n");
        }
    }
    else{
        perror ("Error");
    }
    //To free the Memory
    for(i = 0; i < no; i++){
        free(lr[i]);
    }
    free(lr);
    //return;
}

void func_lsdir(char *name){
    int i = 0;
    struct dirent **lr;
    int no = scandir(name, &lr, 0, alphasort);
    if (no >= 0){
        for(i = 0; i < no; i++ ){
            if(strcmp(lr[i]->d_name, ".") == 0 || strcmp(lr[i]->d_name, "..") == 0){
                continue;
            }
            else{
				printf("%s%s", WHITE, lr[i]->d_name);
			}
			printf("\n");
        }
    }
    else{
        perror ("Error");
    }
    for(i = 0; i < no; i++){
        free(lr[i]);
    }
    free(lr);
}
void func_lsa(){
    int i = 0;
    struct dirent **lr;
    int no = scandir(".", &lr, 0, alphasort);
    if (no >= 0){
        for(i = 0; i < no; i++ ){
				printf("%s%s    ", WHITE, lr[i]->d_name);
				printf("\n");
        }
    }
    else{
        perror ("Error");
    }
    for(i = 0; i < no; i++){
        free(lr[i]);
    }
    free(lr);
}

void func_lsl(){
    int i = 0, sum = 0;
    char timer[14];
    struct dirent **lr;
    struct stat file;
    int no = scandir(".", &lr, 0, alphasort);
    if(no > 0){
        for (i = 0; i < no; i++){
            if(strcmp(lr[i]->d_name, ".") == 0 || strcmp(lr[i]->d_name, "..") == 0){
                continue;
            }
            else if(stat(lr[i]->d_name, &file) == 0){
                sum += file.st_blocks; // block size
                // owner permissions-group permissions-other permissions
                printf("%s%1s",WHITE, (S_ISDIR(file.st_mode)) ? "d" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IRUSR) ? "r" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IWUSR) ? "w" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IXUSR) ? "x" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IRGRP) ? "r" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IWGRP) ? "w" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IXGRP) ? "x" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IROTH) ? "r" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IWOTH) ? "w" : "-");
                printf("%s%1s ", WHITE, (file.st_mode & S_IXOTH) ? "x" : "-");
                // links associated - owner name - group name
                printf("%s%2ld ", WHITE, (unsigned long)(file.st_nlink));
                printf("%s%s ", WHITE, (getpwuid(file.st_uid))->pw_name);
                printf("%s%s ", WHITE, (getgrgid(file.st_gid))->gr_name);
                // file size (bytes) - time modified - name
                printf("%s%5lld ", WHITE, (unsigned long long)file.st_size);
                strftime (timer, 14, "%h %d %H:%M", localtime(&file.st_mtime));
                printf("%s%s ", WHITE, timer);
                printf("%s%s\n", WHITE, lr[i]->d_name);
            }
        }
    }
    else{
            printf("%sEmpty\n", WHITE);
    }
    for(i = 0; i < no; i++){
        free(lr[i]);
    }
    free(lr);
}
void func_lsal(){
    int i = 0, sum = 0;
    char timer[14];
    struct dirent **lr;
    struct stat file;
    int no = scandir(".", &lr, 0, alphasort);
    if(no > 0){
        for (i = 0; i < no; i++){
			if(stat(lr[i]->d_name, &file) == 0){
                sum += file.st_blocks; // block size
                // owner permissions-group permissions-other permissions
                printf("%s%1s", WHITE, (S_ISDIR(file.st_mode)) ? "d" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IRUSR) ? "r" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IWUSR) ? "w" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IXUSR) ? "x" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IRGRP) ? "r" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IWGRP) ? "w" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IXGRP) ? "x" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IROTH) ? "r" : "-");
                printf("%s%1s", WHITE, (file.st_mode & S_IWOTH) ? "w" : "-");
                printf("%s%1s ", WHITE, (file.st_mode & S_IXOTH) ? "x" : "-");
                // links associated - owner name - group name
                printf("%s%2ld ", WHITE, (unsigned long)(file.st_nlink));
                printf("%s%s ", WHITE, (getpwuid(file.st_uid))->pw_name);
                printf("%s%s ", WHITE, (getgrgid(file.st_gid))->gr_name);
                // file size (bytes) - time modified - name
                printf("%s%5lld ", WHITE, (unsigned long long)file.st_size);
                strftime (timer, 14, "%h %d %H:%M", localtime(&file.st_mtime));
                printf("%s%s ", WHITE, timer);
                printf("%s%s\n", WHITE, lr[i]->d_name);
        	}
		}
    }
    else{
            printf("%sEmpty\n", WHITE );
    }
    for(i = 0; i < no; i++){
        free(lr[i]);
    }
    free(lr);
}
