#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>
 
int main(int argc,char *argv[])
{

    int i=0;
    //set signal hei,inital value=1
    sem_t * hei=sem_open("chess_black_sem",O_CREAT,0666,1);
    sem_t *hong=sem_open("chess_red_sem",O_CREAT,0666,0);
    //set signal hong ,inital value=0
    for(i=0;i<10;i++){

        //test if hei has moved ,hei initial value=1,so hong first step
        sem_wait(hong);
        if(i!=9){
            printf("Black chess has moved,red chess go!\n");
        }else{
            printf("Red chess lost\n");
        }
        fflush(stdout);
           
        sem_post(hei);//hong has moved,send message to hei
   }
   sleep(10);
  
  //close two signals
  sem_close(hei);
  sem_close(hong);
  //delete two signals
  sem_unlink("chess_red_sem");
  sem_unlink("chess_black_sem");
  exit(0);

}


