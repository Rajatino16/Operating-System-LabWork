#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

    int pfd[2] ;
    pipe(pfd);
    int id = fork();
    if(id==0){
        close(1);
        dup(pfd[1]);
        close(pfd[0]);
        close(pfd[1]);
        execlp("ls","ls",NULL);
    }
    else{
        close(0);
        dup(pfd[0]);
        close(pfd[1]);
        close(pfd[0]);
        execlp("wc","wc","-w",NULL);
    }

return 0 ;
}
