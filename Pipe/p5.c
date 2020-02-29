#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h> 

struct arg {
    int l,b ;
}arg1,arg2,arg3,arg4 ;

int main(){

    int pfd1[2] ,pfd2[2],id1, id2,s;
    pipe(pfd1);
    pipe(pfd2);
    id1 = fork();
    if(id1>0)
    {
        printf("enter the length and breadth :\n");
        //close(1);     // don't close or link to file descriptor 1 since it is needed later to display the answer
        //dup(pfd1[1]);
        close(pfd1[0]);
        close(pfd2[1]);
        scanf("%d %d",&arg1.l, &arg1.b);
        write(pfd1[1],&arg1,sizeof(arg1));

        wait(NULL);
        close(pfd1[1]);
        // for reading squares
        close(0);
        dup(pfd2[0]);
        
        read(pfd2[0],&arg4,sizeof(arg4));
        s= arg4.l*arg4.b ;
        printf("the area of the rectangle is %d\n",s);
        //write(1,&s,sizeof(int));   
        // 1 for displaying on the monitor has been closed. for initial programs, therefore don't close it.
    }
    else
    {
        close(0);
        dup(pfd1[0]);
        close(pfd1[1]);
        close(1);
        dup(pfd2[1]);
        close(pfd2[0]);
        
        read(pfd1[0],&arg2,sizeof(arg2));
        arg3.l = arg2.l * arg2.l ;
        arg3.b = arg2.b * arg2.b ;

        write(pfd2[1],&arg3,sizeof(arg3));
        exit(0);
    }

return 0 ;
}
