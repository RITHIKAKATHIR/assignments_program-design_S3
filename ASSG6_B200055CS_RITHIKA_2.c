#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node{
 int data;                     //node declaration
 struct node* next;
};

struct queue{
    struct node* head;    //queue declaration
    struct node* tail;
};

struct node* create_node(int k){
    struct node* newnode ;        //creation of new node
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
     exit(0);
    newnode->data=k;
    newnode->next=NULL;
    return newnode;
}

void ENQUEUE(struct queue* queue, struct node* node){
     if(queue->tail==NULL && queue->head==NULL){
         queue->head=node;             //if queue was empty, head and tail points to node
         queue->tail=node;
    }
    else{
        queue->tail->next=node;
        queue->tail=node;         //else, tail points to the new node entered
    }
 }

int queue_empty(struct queue* queue){
     if(queue->head==NULL && queue->tail==NULL)  //if both, head and tail are NULL, underflow
     return -1;
     else
     return 1;
 }

void DEQUEUE(struct queue* queue){
     int check;
     check=queue_empty(queue);          //check for underflow
     if(check==-1) printf("-1\n");
     else{
         struct node* to_be_deleted;
         to_be_deleted=(struct node*)malloc(sizeof(struct node));
         if(to_be_deleted==NULL) exit(0);
         to_be_deleted=queue->head;   //node pointer assigned to first node
         printf("%d\n",to_be_deleted->data); //data of first node displayed
         if(queue->head==queue->tail){
         queue->head=NULL;            //if there is only single node, represent: both head and tail becomes NULL
         queue->tail=NULL;
         }
         else queue->head=to_be_deleted->next; //else , head points to next node
     }
 
}
int main(){
    char ch;   //to choose from menu driven options
    int num;   // to scan in data from the user
    int r;    // to disp underflow condition
    struct node* temp; 
    struct queue* queue1;  
    queue1=(struct queue*)malloc(sizeof(struct queue));
    if(queue1==NULL) exit(0);
    queue1->head=NULL;  //initially the queue is empty
    queue1->tail=NULL;
    while(1){
        scanf("%c",&ch); 

        switch(ch){ 
            case 'i':       scanf(" %d",&num);     //data from user
                            temp=create_node(num);  //creation of node
                            ENQUEUE(queue1,temp);  //enqueue function call
                            break;

            case 'd':        DEQUEUE(queue1);  //dequeue function call
                             break;

            case 'e':        r=queue_empty(queue1);  //to check undeflow condition
                             printf("%d\n",r);
                             break;

            case 't':        return 1; //to terminate the program
        }

    }
    return 0;
    
}