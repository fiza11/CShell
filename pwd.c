#include"headers.h"

void func_pwd(char *c, int g){
	char temp[MAX_BUFF];
	char *path = getcwd(temp, MAX_BUFF);
	if(path != NULL){
		strcpy(c, temp);
		if(g == 1){
			printf("%s%s\n", WHITE, c);
		}
	}
	else perror("Error\n");
}
