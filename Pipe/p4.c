#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

struct arg {
    int l,b ;
}arg1,arg2 ;

int main(){

    int pfd1[2],id1,s;
    pipe(pfd1);
    id1 = fork();
    if(id1==0){
        printf("enter the length and breadth :\n");
        close(1);
        dup(pfd1[1]);
        close(pfd1[0]);
        scanf("%d %d",&arg1.l, &arg1.b);
        write(pfd1[1],&arg1,sizeof(arg1));
    }
    else{
        close(0);
        dup(pfd1[0]);
        close(pfd1[1]);
        read(pfd1[0],&arg2,sizeof(arg2));
        s= arg2.l*arg2.b ;
        printf("the area of the rectangle is %d\n",s);
    }



return 0 ;
}
