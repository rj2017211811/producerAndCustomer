#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
//enum STATE{Ready,Running,Blocked};

#define MAX_SIZE 100
typedef struct 
{

    int data[MAX_SIZE];
    int font,rear;

}sqQueue;
sqQueue*  initQueue()
{
    sqQueue *q=(sqQueue*)malloc(sizeof(sqQueue));
    if(q!=NULL)
    {    q->font=0;
         q->rear=0;
      //  printf("%d %d",q->font,q->rear);
      //  printf("queue initalized successfully.\n");
        
 
    }
    return q;
    

}
int isEmpty(sqQueue *q)
{
    if(q->rear==q->font)
    {
        return 1;
    }
   return 0;
 
}
int enQueue(sqQueue *q,int  data)
{
    if((q->rear+1)%MAX_SIZE==q->font)
    {
    
        return 0;
    }
    else 
    {
        q->rear=(q->rear+1)%MAX_SIZE;
        q->data[q->rear]=data;
        return 1;
  
    }


}

int deQueue(sqQueue *q,int *data)
{
    if(q->rear==q->font)
    {
        return 0;

    }
    else
    {
        q->font=(q->font+1)%MAX_SIZE;
        *data=q->data[q->font];
        return 1;
    }


}
void selectSort(PCB pdb[])
{
    int i=0,j=0;
    
    for(i=0;i<pcb.length;i++)
    {
        for(j=i+1;j<pcb.length;j++)
        {
           
        }
  
    }
    


}
typedef struct process_pcb
{
    int ID;//process ID
    int priority;//youxianshu
    int arrive_time;
    int service_time;
    int start_time;
    int end_time;
    int all_time;
    int cpu_time;
    int state;




}PCB;
int main()
{
    sqQueue *q=initQueue();
    int num;
    printf("Please input the num of process.\n");
    scanf("%d",&num);
    int i=0;
    PCB pcb[num];
    printf("Please input information for ready.");
    for(i=0;i<num;i++)
    {
        printf("Please input the %d process priority,arrive_time,service_time",i);
        scanf("%d %d %d",&pcb[i].priority,&pcb[i].arrive_time,
        &pcb[i].service_time);
        pcb[i].ID=i;
        
        printf("%d\n",enQueue(q,pcb[i].ID));
         
    }
    for(i=0;i<num;i++)
    {

        printf("%d %d %d\n",pcb[i].priority,pcb[i].arrive_time,pcb[i].service_time);

    }
    int data;
    int result=0;
  while(( result=deQueue(q,&data))>0)
 {
    printf("process %d deQueue\n",data);

 }

   
      // printf("%d ",data);
  
    
   printf("1");
  //  sqQueue*q= initQueue();
  //  printf("%d %d\n",q->rear,q->font);  
   // printf("%d",isEmpty(q));
   // int i=0;
  /*  for(i=0;i<5;i++)
   {
        printf("%d",enQueue(q,i));
   }*/
    return 0;
}
