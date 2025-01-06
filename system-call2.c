#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int pid;
    pid=fork();
    
    if(pid == -1){
        printf("error in process creation!");
        exit(1);
    }
    if(pid != 0){
        printf("parent process id: %d\n", getpid());
    } 
    else{
        printf("child process id: %d\n", getpid());
    }
    return 0;
}
