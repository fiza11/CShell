# Shell
A linux shell written in C language to implement various shell commands.

## Make Instructions:
- Run `make` to create shell executable.
- Run `./shell` to run the shell.

## File Breakdown:
- init.c: Contains functions for displaying the output and to split semi-colon separated commands.
- shell.c: Contains functions to implement commands.
- bg.c: Contains functions to implement background processes.
- fg.c: Contains functions to implement foreground processes that are not built-in commands.
- headers.h: Contains headers, function declarations and variable declarations.
- random.c: Contains some random functions like to remove an extra line and all.
- cd.c: Contains functions to implement cd command.
- pwd.c: Contains functions to implement pwd command.
- pinfo.c: Contains functions to implement pinfo command.
- ls.c: Contains functions to implement ls, ls -l, ls -al, etc. commands.
- handler.c: Contains functions to display exit status of background process.

## Features:
- Shell supports built-in commands like cd, pwd, echo, etc.
- Shell supports semi-colon separated list of commands.
- Shell supports '&' operator which lets a program run in background and displays a proper message when it exits.
- Errors are handled properly using perror.

