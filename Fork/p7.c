#include <stdio.h> 
#include <unistd.h> 
int main() 
{  
    int child_pid = fork(); 

    if (child_pid == 0) 
        execlp("ls","ls",NULL); 
    else        
       wait(); 
  
    return 0; 
}