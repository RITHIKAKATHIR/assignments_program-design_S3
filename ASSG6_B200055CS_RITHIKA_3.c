#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct stack{
    char stack[10000];
    int top;
};
void push(char e,struct stack* s1){
    if(s1->top==-1){
        s1->top=s1->top+1;
        s1->stack[s1->top]=e;
    }
   else
   {
         s1->top=s1->top+1;
        s1->stack[s1->top]=e;
    }
}
int isunderflow(struct stack* s1){
    if(s1->top==-1) return -1;
    else return 1;
}

int precedence(char present)
 {  int p=0;

     if(present== '(')
        p=0;
     if(present== '+' || present== '-')
        p=1;
     if(present== '*' || present== '/')
        p=2;

    return p;
 }

char pop(struct stack* s1){
    int c;
    c=isunderflow(s1);
    if(c==-1) printf("-1");
    else{
      s1->top=s1->top-1;
      return s1->stack[s1->top+1];
    }
}
void INFIXTOPOSTFIX(char* e)
{   char check;
    int j,j1;
    struct stack s1;
    s1.top=-1;
   
    for(int i=0;e[i]!=' '&&e[i]!='\n'&&e[i]!='\0';i++)
    {   
        if((e[i]>=65 && e[i]<=90) || (e[i]>=97 && e[i]<=122))
        {
        //printf("charcter is: %c ",e[i]);
        printf("%c",e[i]);
        }
        else
        {   
        
            if(e[i]=='(')
            {
            push(e[i],&s1);
            continue;
          
            }

            if(e[i]==')')
            {
                while((check=pop(&s1))!='(')
                printf("%c",check);
                
                continue;
            

            }

            if(s1.top==-1)
            push(e[i],&s1);

            else
            {  //printf("%c    ",s1.stack[s1.top]);
               j=precedence(s1.stack[s1.top]);
               //printf("%d",j);
               
               j1=precedence(e[i]);
               //printf("   %d",j1);
            
                if(j<j1)
                {   //printf("   lllllpuhed  ");
                    push(e[i],&s1);
                }
                else 
                {   
                   
                   while(precedence(s1.stack[s1.top])>=precedence(e[i]) && s1.top!=-1)
                   {//printf("poped");
                    check=pop(&s1);
                    if(check!='(')
                    printf("%c",check);
                   }

                   push(e[i],&s1);
                 
                }

            }

            
        }
    }

    while(s1.top!=-1){
        check=pop(&s1);
        if(check!='(')
        printf("%c",check);
    }
    
}
void main(){
    char expression[100000];
    fgets(expression,100000,stdin); //scan in the expression from user
    //printf("%s",expression);

    INFIXTOPOSTFIX(expression); //function call

}
