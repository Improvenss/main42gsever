#include<stdio.h>
#include<unistd.h>
#include<signal.h>
/**
	Burada ^C signalin 'ignore' edilecektir. Yani yok sayilacaktir. 
*/
int main(){
  signal(SIGINT,SIG_IGN); // Register signal handler for ignoring the signal

  for(int i=1;;i++){    //Infinite loop
    printf("%d : Inside main function\n",i);
    sleep(1);  // Delay for 1 second
  }
  return 0;
}

