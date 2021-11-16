#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
 struct stack{
    long int stack[10000];
    long int top;
};

 void push(int e,struct stack* s1){
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

 int pop(struct stack* s1){
    int c;
    c=isunderflow(s1);
    if(c==-1) printf("-1");
    else{
      s1->top=s1->top-1;
      return s1->stack[s1->top+1];
    }
}
void EVALUATEPOSTFIX(char* e){
    //printf(" hey 1");
    long int no1,no2;
    long int num,num_1;
    long int ans;
    long int n[25];
    long int n_p=0;
    long int l=0;
    long int h=0;
    long int digit;
    long int chck=0;
    struct stack s1;
    s1.top=-1;
    for(int i=0;e[i]!='\0'&&e[i]!='\n';i++)
    { //printf("hey 2");
      if(e[i]==' ') continue;
      if(e[i]>=48 && e[i]<=57)
      {
        while(e[i+1]!=' ')
        {//printf("wronggg  ");
        n[l]=e[i]-'0';
        l++;
        i++;
        chck=1;
        }
        n[l++]=e[i]-'0';

        /*for(int i=0;i<l;i++)
        printf("%d",n[i]);*/

        if(chck==1)
        { /*printf(" wornnnn");
           digit=l-1;
           while(digit>=0 && h<=l-1){
           n_p=n_p+(n[h]*pow(10,digit));
           digit--;
            h++;
           }
            printf(" jjjj %d ",n_p);
            push(n_p,&s1);*/
         digit=l-1;
         while(digit>=0 && h<l){
         n_p=n_p+(n[h]*pow(10,digit));
         digit--;
         h++;
         }
         //printf(" jjjj %d ",n_p);
         push(n_p,&s1);
        }
       else
         push(e[i]-'0',&s1);
       
     }
        
    else{ 
            /*printf("the stack now: ");
            for(int j=s1.top;j>=0;j--)
            printf("%d ",s1.stack[j]);*/


            no1=pop(&s1);
            
            no2=pop(&s1);
          
            if(e[i]=='+'){
             ans=no2+no1;
             push(ans,&s1);

            }
            if(e[i]=='-'){
             ans=no2-no1;
             push(ans,&s1);
             }
            if(e[i]=='*'){
             ans=no2*no1;
             push(ans,&s1); 
            }
            if(e[i]=='/'){
              ans=(no2)/(no1);
             push(ans,&s1);
            }
        }

        l=0;
        h=0;
        chck=0;
        n_p=0;
    }

    printf("%d",s1.stack[s1.top]);
}

void main(){
    char expression[100000];
    fgets(expression,100000,stdin); //scan in the expression from user
    //printf("%s",expression);

    EVALUATEPOSTFIX(expression); //function call

}