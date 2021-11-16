#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct queue
{
    int n;
    char** A;
    int head;
    int tail;
};

int queuefull(struct queue* S)
{
    if((S->tail)+1==(S->head)) return -1;
    else return 1;
}

void enqueue(struct queue* S, char*key_1)
{ int p;
  p=queuefull(S);
  if(p==-1) printf("-1\n");
  else
    { 
     strcpy(S->A[S->tail],key_1);
     if(S->tail==(S->n)-1) S->tail=0; 
     else S->tail=(S->tail)+1;
      
    }
  
 }

int queueempty(struct queue* S)
{
    if(S->tail==S->head) return -1;
    else return 1;
}

void dequeue(struct queue* S,char*key_1)
{ 
    int p; 
    p=queueempty(S);
    if(p==-1) printf("-1\n");
    else{
        // printf("heyy");
        strcpy(key_1,S->A[S->head]);
        if((S->head)==(S->n)-1) S->head=0;
        else S->head=S->head+1;

        printf("%s\n",key_1); 
    }

}

int main(){
    char ch;
    char* key_1;
    key_1=(char*)malloc(25*sizeof(char));
    char* key_2;
    key_2=(char*)malloc(25*sizeof(char));
    if(key_2==NULL) {
        exit(0);
    }
    int w;
    struct queue* S;
    int n1;
    S=(struct queue*)malloc(sizeof(struct queue));
    if(S==NULL)
    {
        exit(0);
    }
    S->head=0; 
    S->tail=0; //queue empty
    scanf("%d",&n1);
    S->n=n1;
    // printf("n in struct: %d\n",S->n);
    S->A=(char**)malloc(n1*sizeof(char*));
    for(int i=0;i<n1;i++)
    {
        S->A[i]=(char*)malloc(40*sizeof(char));
    }
    
    while(1)
    {
        scanf("%c",&ch);

        switch(ch)
        { case 'i':     
                        
                        scanf(" %s",key_1);
                        enqueue(S,key_1);
                        break;

          case 'd':   
                       dequeue(S,key_2);
                       break;
          
          case 'f':    
                       w=queuefull(S);
                       if(w==-1) printf("-1\n");
                       if(w==1) printf("1\n");
                       break;

          case 'e':  
                       w=queueempty(S);
                       if(w==-1) printf("-1\n");
                       if(w==1) printf("1\n");
                       break; 

         case 't':     return 1;

        }
    }

    return 0;
}