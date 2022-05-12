// mysh.c ... a bootleg shell
// Started by John Shepherd, October 2017
// Completed by Kevin Edbert Sutandi, z5352065

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

// Defines to make code easier to read
#define MAXLINE 128
#define EQUAL 0

// this next line may  be needed on you machine
// uncomment it out if you are getting an error about strdup
// extern char *strdup(char *);

void trim(char *);
char **tokenise(char *, char *);
void freeTokens(char **);
int isExecutable(char *);
void execute(char **, char **, char **);

int main(int argc, char *argv[], char *envp[])
{
   pid_t pid;   // pid of child process
   int stat;    // return status of child
   char **path; // array of directory names

   // set up command PATH from environment variable
   int i;
   for (i = 0; envp[i] != NULL; i++) {
      if (strncmp(envp[i], "PATH=", 5) == 0) break;
   }
   if (envp[i] == NULL)
      path = tokenise("/bin:/usr/bin",":");
   else
      // &envp[i][5] skips over "PATH=" prefix
      path = tokenise(&envp[i][5],":");

#ifdef DBUG
   for (i = 0; path[i] != NULL;i++)
      printf("dir[%d] = %s\n",i,path[i]);
#endif

   // main loop: print prompt, read line, execute command
   char line[BUFSIZ];
   printf("mysh$ ");
   while (fgets(line, BUFSIZ, stdin) != NULL) {
        trim(line); // remove leading/trailing space
        if (strcmp(line,"exit") == 0) break;
        if (strcmp(line,"") == 0) { printf("mysh$ "); continue; }

        char **new_command = tokenise(line," ");
      
        // Fork a child process
        pid = fork();

        // Child process error processing
        if (pid < 0) {
            printf("Fork Failed \n");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // pID == 0 means it is the child process
            //execute the commmand
            execute(new_command, path, envp);
            freeTokens(path);
        } else {
            // Parent process
            wait(&stat); // This returs the status of the child
            freeTokens(new_command); // free the tokens
            printf("mysh$ "); // print prompt
        }
   }
   printf("\n");
   return(EXIT_SUCCESS);
}

// execute: run a program, given command-line args, path and envp
void execute(char **args, char **path, char **envp)
{
   // TODO: implement the find-the-executable and execve() it code
   if (strncmp (args[0], ".", 1) == 0 || strncmp (args[0], "/", 1) == 0) {
       // if the command starts with ./, then it is in the current directory
       printf("Executing %s\n", args[0]);
       execve(args[0], args, envp);
   } else {
       // if the command does not start with ./ or /, then it is in the path
       char full_name[MAXLINE];
       char path_name[MAXLINE];
       for (int i = 0; path[i] != NULL; i++) {
           strcpy(path_name, path[i]);
           strcat(path_name, "/");
           strcat(path_name, args[0]);
           if (isExecutable(path_name)) {
               // strcpy to combine the path and the command
               strcat(full_name, path_name);
               printf("Executing %s\n", full_name);
               // execute the command
               execve(path_name, args, envp);
               // exit when the command is found
               exit(EXIT_SUCCESS);
           }
        }
        // if the command is not found in the path
        // it will exit loop and go through the error message
        perror(args[0]);

   }
   // exit if the command is not found in the path
   exit(EXIT_FAILURE);
}

// Check whether this process can execute a file.  This function will be
// useful while searching through the list of directories in the path to
// find an executable file.
int isExecutable(char *pathname)
{
    struct stat s;
    return
        // does the file exist?
        stat(pathname, &s) == 0 &&
        // is the file a regular file?
        S_ISREG(s.st_mode) &&
        // can we execute it?
        faccessat(AT_FDCWD, pathname, X_OK, AT_EACCESS) == 0;
}

// tokenise: split a string around a set of separators
// create an array of separate strings
// final array element contains NULL
char **tokenise(char *str, char *sep)
{
   // temp copy of string, because strtok() mangles it
   char *tmp;
   // count tokens
   tmp = strdup(str);
   int n = 0;
   strtok(tmp, sep); n++;
   while (strtok(NULL, sep) != NULL) n++;
   free(tmp);
   // allocate array for argv strings
   char **strings = malloc((n+1)*sizeof(char *));
   assert(strings != NULL);
   // now tokenise and fill array
   tmp = strdup(str);
   char *next; int i = 0;
   next = strtok(tmp, sep);
   strings[i++] = strdup(next);
   while ((next = strtok(NULL,sep)) != NULL)
      strings[i++] = strdup(next);
   strings[i] = NULL;
   free(tmp);
   return strings;
}

// freeTokens: free memory associated with array of tokens
void freeTokens(char **toks)
{
   for (int i = 0; toks[i] != NULL; i++)
      free(toks[i]);
   free(toks);
}

// trim: remove leading/trailing spaces from a string
void trim(char *str)
{
   int first, last;
   first = 0;
   while (isspace(str[first])) first++;
   last  = strlen(str)-1;
   while (isspace(str[last])) last--;
   int i, j = 0;
   for (i = first; i <= last; i++) str[j++] = str[i];
   str[j] = '\0';
}
