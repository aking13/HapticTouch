#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;



void forking() {
    const char* command ="./gitty";
    pid_t c_pid, pid;
    int status;

    c_pid = fork();
      

    if (c_pid == 0) {
        printf("Child: executing\n");
        execvp(command,NULL);
        perror("execve failed");
    }else if (c_pid > 0) {
      if ( (pid = wait(&status)) < 0) {
            perror("wait");
            _exit(1);
      }
      printf("Parent: finished\n");

    } else {
        perror("fork failed\n");
        _exit(1);
    }
}


int main()
{
    for (int i=0; i < 11; i++) {
        forking();
    }

    return 0;

}

