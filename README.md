# Shell
A linux shell written in C language to implement various shell commands.

## Make Instructions:
- Run `make` to create shell executable.
- Run `./shell` to run the shell.

## File Breakdown:
- init.c: Contains functions for displaying the output and to split semi-colon separated commands.
- shell.c: Contains functions to implement commands.
- bg.c: Contains functions to implement background processes and bring stopped background process to running background process.
- fg.c: Contains functions to implement foreground processes that are not built-in commands and send foreground process to stopped background process.
- headers.h: Contains headers, function declarations and variable declarations.
- random.c: Contains some random functions like to remove an extra line and all.
- cd.c: Contains functions to implement cd command.
- pwd.c: Contains function to implement pwd command.
- echo.c : Contains function to implement echo command.
- pinfo.c: Contains functions to implement pinfo command.
- ls.c: Contains functions to implement ls, ls -l, ls -al, etc. commands.
- handler.c: Contains functions to display exit status of background process.
- signals.c : Contains user defined signal handlers.
- delete.c : Contains function to delete the background job that has been killed from jobs structure.
- env.c : Contains functions to set and unset an environment variable.
- jobs.c : Contains functions to list all the background processes with their state and pid.
- overkill.c : Contains function to kill all the background processes at once.
- pipe.c : Contains function to implement piping commands.
- redirection.c : Contains function to implement I/O redirection.
- redirect.c : Contains function to I/O redirection + pipes redirection.
- kill.c : Contains function to send a signal value to a process whose id is known.

## Features:
- Shell supports built-in commands like cd, pwd, echo, etc.
- Shell supports semi-colon separated list of commands.
- Shell supports '&' operator which lets a program run in background and displays a proper message when it exits.
- Shell supports many manually defined commands like jobs, kjob, fg, bg, overkill, Ctrl + Z and Ctrl + C.
- Errors are handled properly.

## Commands:
- `cd [directory]` : Changes current working directory to the directory specified.
- `pwd` : Displays the name of current working directory.
* `echo [arguments]` : 
  * Displays whatever is specified in [arguments].
  * Displays the value of environment variable(ex. $USER).
* `pinfo <pid>` :
  * Displays process info such as status, memory and executable path about given pid.
  * If no arguments, displays details of the shell.
- `ls [-l -a] [directory]` : Lists all the files and directories in the specified directory.
- `bg <job number>` : Changes a stopped background job with given job number to a running background job.
- `fg <job number>` : Brings a running or a stopped background job with given job number to foreground.
- `setenv var[value]` : Creates environment variable *var* if it does not exist and sets value of *var* to *value*.
- `unsetenv var` : Destroys the environment variable *var*.
- `jobs` : Prints a list of all background jobs(Running or Stopped) with their pid.
- `kjob <job number> <signal number>` : Sends a signal value to a running process with the given job number.
- `overkill` : Kills all background process at once.
- `quit` : Exits the shell.
- `Ctrl-Z` : Changes the status of currently running job to stop, and pushes it to the background.
- `Ctrl-C` : Sends SIGINT signal to the current foreground job of the shell.

