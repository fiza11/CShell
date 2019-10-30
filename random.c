#include"headers.h"

void tail(FILE* in, int n){
    int count = 0;
    long int pos;
    char s[100];
    if(in == NULL) {
       perror("fopen");
       exit(EXIT_FAILURE);
    }
    fseek(in, 0, SEEK_END);
    pos = ftell(in);
    while(pos){
       fseek(in, --pos, SEEK_SET);
       if(fgetc(in) == '\n') {
           if(count++ == 10)
                break;
       }
   }
   while(fgets(s, sizeof(s), in) != NULL) {
       printf("%s\n", s);
   }
   fclose(in);
}

void tilda(char *t, char *f){
	int i, j, k, flag;
	for(j = 0; j < (int)strlen(ft); j++){
		if(t[j] == ft[j])
			flag = 1;
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		k = 0;
		f[k] = '~';
		i = strlen(ft);
		while(i < strlen(t)){
			f[++k] = t[i];
			i++;
		}
		f[++k]='\0';
	}
	else{
		i = 0;
		while(t[i] != '\0'){
			f[i] = t[i];
			i++;
		}
		f[i] = '\0';
	}
}
