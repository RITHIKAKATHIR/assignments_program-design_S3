#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char exp;
    struct node* next_data;
};

struct top{
    struct node* top_pointer;
};

struct node* create_node(char k){

    struct node* newnode ;        //creation of new node
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
     exit(0);
    newnode->exp=k;
    newnode->next_data=NULL;
    return newnode;
}

void push(struct top* top, struct node* nodenow){
    if(top->top_pointer==NULL){         //checking if top is pointing to null
        top->top_pointer=nodenow;       //if top is pointing to null, assigning new node to top
    }
    else{
        nodenow->next_data=top->top_pointer; //else we are entering newnode as the first element
        top->top_pointer=nodenow;
    }
}

int is_empty(struct top* top){
    if(top->top_pointer==NULL)
      return -1;            //if top points to NULL, list is empty: return -1
    else
      return 1;     //if list not empty return 1
}

char pop(struct top* top){

  struct node* to_push;
  to_push=(struct node*)malloc(sizeof(struct node));
  to_push=top->top_pointer;    //to_push points to the first element
  int check;
  check=is_empty(top);  //list underflow condition is checked
  if(check==-1) printf("-1\n");
  else{ 
         
     top->top_pointer=to_push->next_data;  //top points to the next element in the stack
      
     printf(" top->top_pointer=%c",top->top_pointer->exp);
     return to_push->exp;
     }
  }

 int precedence(char present)
 {  int p=0;
    if(present== '+' || present== '-')
        p=1;
    if(present== '*' || present== '/')
        p=2;

    return p;
 }

void INFIXTOPOSTFIX(char* e)
{
    int j,j1;
    char check;
    struct top* top;
    top=(struct top*)malloc(sizeof(struct top));
    top->top_pointer=NULL;
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL) exit(0);

   /* struct node* temp1;
    temp1=(struct node*)malloc(sizeof(struct node));
    if(temp1==NULL) exit(0);

    temp1=top->top_pointer;*/
   
    for(int i=0;e[i]!='\0';i++)
    {   printf("charcter gulugu is: %c ",e[i]);
        if((e[i]>=65 && e[i]<=90) || (e[i]>=97 && e[i]<=122)){
        printf("charcter is: %c ",e[i]);
        printf("%c",e[i]);
        }
        else
        {   
            temp=create_node(e[i]);
            if(e[i]=='(')
            {
            push(top,temp);
            continue;
            }

             if(e[i]==')')
            {
                while((check=pop(top))!='(')
                printf("%c",check);
                continue;

            }
            if(top->top_pointer==NULL)
            push(top,temp);
            else
            {  
               j=precedence(top->top_pointer->exp);
               
               j1=precedence(temp->exp);
            
                if(j<j1)
                {  
                    push(top,temp);
                }
                else 
                {   
                   
                   while(precedence(top->top_pointer->exp)>=precedence(temp->exp))
                   {printf("poped");
                    check=pop(top);
                    if(check!='(')
                    printf("%c",check);
                    
                   }

                   push(top,temp);
                 
                }

            }

            
        }
    }

    while(top->top_pointer!=NULL){
        check=pop(top);
        if(check!='(')
        printf("%c",check);
    }
    
}
void main(){
    char expression[100000];
    fgets(expression,100000,stdin); //scan in the expression from user
    printf("%s",expression);

    INFIXTOPOSTFIX(expression); //function call

}