#include<stdio.h>
#include<unistd.h>

int main(){

if(fork() || fork())
printf("hello\n");
else 
printf("bye\n");

pause();

return 0 ;
}
