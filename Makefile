CC=gcc
DEPS = headers.h
OBJ = shell.c pwd.c cd.c pinfo.c random.c ls.c init.c bg.c fg.c handler.c redirection.c pipe.c echo.c signals.c jobs.c delete.c kill.c overkill.c env.c redirect.c

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

shell: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
