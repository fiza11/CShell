#include"headers.h"

void init(){
	char host[MAX_BUFF];
  	int hostname = gethostname(host, MAX_BUFF);
	char* username = getenv("USER");
	printf("\n%s%s@%s: ", BLUE, username, host);
}

char *read_line(){
	char *line = NULL;
	ssize_t bs = 0;
	printf("%s", WHITE);
	getline(&line, &bs, stdin);
	return line;
}

char **split_line(char *line){
	int bs = 64, pos = 0;
	char **ts = malloc(bs * sizeof(char*));
	char **command = malloc(bs * sizeof(char*));
	char *tn;
	if(!ts || !command){
		fprintf(stderr, "Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	tn = strtok(line, ";\n");
	while(tn != NULL){
		ts[pos] = tn;
		pos++;
		if(pos >= bs){
			bs += 64;
			ts = realloc(ts, bs * sizeof(char*));
			if(!ts){
				fprintf(stderr, "Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}
		tn = strtok(NULL, ";\n");
	}
	size = pos;
	return ts;
}
