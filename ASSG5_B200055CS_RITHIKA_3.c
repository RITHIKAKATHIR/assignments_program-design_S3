#include <stdio.h>
#include <stdlib.h>
struct stack{
    int n;
    int top;
    char A[100];
};
int stack_full(struct stack* S){
   if(S->top==((S->n)-1))
     return -1; //stack full  
    else return 1;
}
void push(struct stack* S,int k)
{   int p;
    p=stack_full(S);
    if(p==-1)
     printf("-1\n"); //stack full
    else
    {
      (S->top)=(S->top)+1;
       S->A[(S->top)]=k;
       
    }

   /*if(p!=-1){
      for(int i=0;i<=(S->top);i++)
        printf("%c ",S->A[i]);
        printf("\n");
   }*/
    
}

int stack_empty(struct stack* S)
{
    if(S->top==-1) return -1;
    else return 1;
}

void pop(struct stack* S)
{   int p;
    p=stack_empty(S);
    if(p==-1) printf("-1\n");
    else{
        (S->top)=(S->top)-1;
        printf("%c\n",S->A[(S->top)+1]);
        }
}

char peek(struct stack* S)
{
    int o;
    o=stack_empty(S);
    if(o==-1) printf("-1\n");
    else
    {
        return S->A[(S->top)];
    }
    return '\0';
}

int main(){
    char ch;
    char key_1;
    char peek1;
    struct stack* S;
    int n1;
    S=(struct stack*)malloc(sizeof(struct stack));
    if(S==NULL) exit(0);
    S->top=-1; //stack empty
    scanf("%d",&n1);
    S->n=n1;
    //printf("n in struct: %d",S->n);
    while(1)
    {
        scanf("%c",&ch);

        switch(ch)
        { case 'i': 
                       scanf(" %c",&key_1);
                       push(S,key_1);
                       break;
          case 'd':   
                       pop(S);
                       break;
          case 'p':    
                       peek1=peek(S);
                       if(peek1!='\0')
                       printf("%c\n",peek1);
                       break;

          case 't': return 1;

        }
    }

    return 0;
}