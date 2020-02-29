#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

    int pfd1[2] ,pfd2[2],id1, id2 ;
    pipe(pfd1);
    id1 = fork();
    if(id1==0){
        pipe(pfd2);
        id2 = fork();

        if(id2==0)
        {
        close(1);
        dup(pfd2[1]);
        close(pfd2[0]);
        close(pfd1[1]);
        close(pfd1[0]);
        execlp("ps","ps","-e",NULL);
        
        }
        else{
            close(0);
            dup(pfd2[0]);
            close(pfd2[1]);
            close(pfd2[0]);
            close(pfd1[0]);
            close(1);
            dup(pfd1[1]);
            execlp("grep","grep","systemd",NULL);
        
            }
    }
    else {
        close(0);
        dup(pfd1[0]);
        close(pfd1[0]);
        close(pfd1[1]);
        execlp("wc","wc","-l",NULL);
  }

return 0 ;
}
