#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include "public.h"
int main(int argc,char *argv[])
{
    fflush(stdin);
    printf("producer process\n");
    int i=0;
    int shmid;
    shared_struct *pbuf=0;
    int length=0;
    //full,the production producer produce,inital value 0
    //empty,now buffer has no product inital value 10
    //mutex,mutext signal ,inital value 1
    sem_t *full,*empty,*mutex;
    //creat and init full,empty,mutex signal
     full=sem_open("full_sem1",O_CREAT,0666,0);
   // printf("full:%d\n",*full);
    empty=sem_open("empty_sem1",O_CREAT,0666,10);
  // printf("empty:%d\n",*empty);
   printf("producer full:%d empty:%d\n",*full,*empty);
   /* mutex=sem_open("buf_mutex",O_CREAT,0666,1);
    printf("mutex:%d\n",*mutex);*/
    //printf("2 ");
    length=sizeof(shared_struct);
    //printf("length:%d\n",length);
    //creat shared memory,key 1234
    //in common sense,we should use "ftox" create unique key
    shmid=shmget((key_t)1234,length,0666|IPC_CREAT);
    
    //put shared memory map process private area
    pbuf = (shared_struct*)shmat(shmid,0,0);
    //printf("%d\n",*pbuf);
    //every procuder process produce 10 product

    printf("producer init sucess\n");
    for(i=0;i<10;i++){
       // printf("producer waiting\n");
      //  sleep(rand()%3);
        sleep(1);
        //printf("wait empty\n");
        int wait= sem_wait(empty);//wait a empty buffer
        //printf("wait:%d\n",wait);
       // printf("wait mutex\n");
        sem_wait(mutex);//wait mutex into critical area
        //write str in buffer write pointer exists
        //printf("start produce\n");
        pbuf->buf[pbuf->write]='a'+pbuf->write;
       // printf("producer 1\n");
        printf("Producer-%d:write %c\n",getpid(),pbuf->buf[pbuf->write]);
        //update write pointer value
        pbuf->write=(++pbuf->write)%10;
        
        sem_post(mutex);//free buffer
        sem_post(full);//full +1
          
   }

   shmdt((void*)pbuf);//cancel shared memory
   sleep(10);
   shmctl(shmid,IPC_RMID,0);//delete shared memory
   //close three signals
   sem_close(full);
   sem_close(empty);
   sem_close(mutex);
   //delete three signals
   sem_unlink("full_sem");
   sem_unlink("empty_sem");
   sem_unlink("buf_mutex");
   printf("\nexit\n");
   exit(0);  


}
