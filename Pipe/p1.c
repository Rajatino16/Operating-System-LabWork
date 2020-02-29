#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

    int pfd[2],n,s ;
    pipe(pfd);
    int id = fork();
    if(id==0){
        printf("enter the number :\n");
        close(1);
        dup(pfd[1]);
        close(pfd[0]);
        scanf("%d",&n);
        write(pfd[1],&n,sizeof(int));
    }
    else{
        close(0);
        dup(pfd[0]);
        close(pfd[1]);
        read(pfd[0],&n,sizeof(int));
        s= n*n ;
        printf("the square of the number is %d\n",s);
    }

return 0 ;
}
