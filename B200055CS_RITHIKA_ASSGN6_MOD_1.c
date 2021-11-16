#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char key;
    struct node* lchild;
    struct node* rchild;
    struct node* next;
};

struct top
{
    struct node* top_pointer;
};

struct stack{
    char stack[10000];
    int top;
};

struct node* create_node(char k,struct node* l,struct node* r)
{
    struct node* newnode ;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
     exit(0);
    }
    newnode->key=k;
    newnode->lchild=l;
    newnode->rchild=r;
    newnode->next=NULL;
    
    return newnode;
}

void push(struct node* temp,struct top* top)
{
    if(top->top_pointer==NULL)
     top->top_pointer=temp;
    else{
        temp->next=top->top_pointer; //else we are entering newnode as the first element
        top->top_pointer=temp;
    }

}

struct node* pop(struct top* top)
{
  struct node* to_push;
  to_push=(struct node*)malloc(sizeof(struct node));
  to_push=top->top_pointer;  
   if(to_push!=NULL)
   {
       top->top_pointer=to_push->next;
   }
   return to_push;
}

struct node* construct_expressiontree(char expression[10000])
{
    struct node* left;
    left=(struct node*)malloc(sizeof(struct node));
    struct node* right;
    right=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    struct top* top;
    top=(struct top*)malloc(sizeof(struct top));
    top->top_pointer=NULL;
    int i;
    struct node* temp1;
    temp1=(struct node*)malloc(sizeof(struct node));
    struct node* temp2;
    temp2=(struct node*)malloc(sizeof(struct node));
    temp2=create_node(expression[0],NULL,NULL);
    temp1=create_node(expression[1],temp2,NULL);
    for(i=2;expression[i]!=';'&&expression[i]!='\0'&&expression[i]!=' '&&expression[i]!='\n';i++)
    {   //printf(" %c ",expression[i]);
        if((expression[i]>=97 && expression[i]<=122)||(expression[i]>=65 && expression[i]<=90))
        {
            temp=create_node(expression[i],NULL,NULL);
           // printf("%c",temp->key);
            push(temp,top);
        }
        else
        {   if(expression[i]!=')' && expression[i]!='(')
           {
            //printf(" entered ");
            right=pop(top);
           // printf("%c",right->key);
            left=pop(top);
            //printf("%c",left->key);
            temp=create_node(expression[i],left,right);
           /* printf("%c",temp->key);
            if(temp->lchild!=NULL)
            printf("%c",temp->lchild->key);
            if(temp->rchild!=NULL)
            printf("%c",temp->rchild->key);*/
            push(temp,top);
          }
        }
    }

   temp1->rchild=top->top_pointer;



  /* struct node* selected;
    selected=(struct node*)malloc(sizeof(struct node));
    selected=top->top_pointer;
    while(selected->next!=NULL){
       selected=selected->next;
   }
  return selected;*/

  return temp1;

}

void postorder_tree(struct node* tree)
{
     if(tree!=NULL)
     { 
        postorder_tree(tree->lchild);
        postorder_tree(tree->rchild);
        printf("%c",tree->key);
    }
}



void push1(char e,struct stack* s1){
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

char pop1(struct stack* s1){
    int c;
    c=isunderflow(s1);
    if(c==-1) printf("-1");
    else{
      s1->top=s1->top-1;
      return s1->stack[s1->top+1];
    }
}
char* INFIXTOPOSTFIX(char* e)
{   char check;
    int j,j1;
    struct stack s1;
    s1.top=-1;
    char* to_r;
    to_r=(char*)malloc(10000*sizeof(char));
    int h=0;
   
    for(int i=2;e[i]!=' '&&e[i]!='\n'&&e[i]!='\0'&&e[i]!=';';i++)
    {   
        if((e[i]>=65 && e[i]<=90) || (e[i]>=97 && e[i]<=122))
        {
        //printf("charcter is: %c ",e[i]);
         to_r[h++]=e[i];
        }
        else
        {   
        
            if(e[i]=='(')
            {
            push1(e[i],&s1);
            continue;
          
            }

            if(e[i]==')')
            {
                while((check=pop1(&s1))!='(')
                to_r[h++]=check;
                
                continue;
            

            }

            if(s1.top==-1)
            push1(e[i],&s1);

            else
            {  //printf("%c    ",s1.stack[s1.top]);
               j=precedence(s1.stack[s1.top]);
               //printf("%d",j);
               
               j1=precedence(e[i]);
               //printf("   %d",j1);
            
                if(j<j1)
                {   //printf("   lllllpuhed  ");
                    push1(e[i],&s1);
                }
                else 
                {   
                   
                   while(precedence(s1.stack[s1.top])>=precedence(e[i]) && s1.top!=-1)
                   {//printf("poped");
                    check=pop1(&s1);
                    if(check!='(')
                     to_r[h++]=check;
                   }

                   push1(e[i],&s1);
                 
                }

            }

            
        }
    }

    while(s1.top!=-1){
        check=pop1(&s1);
        if(check!='(')
         to_r[h++]=check;
    }
    to_r[h]='\0';

    return to_r;
    
}


int main(){
    char expression[10000];
    struct node* expression_tree;
    expression_tree=(struct node*)malloc(sizeof(struct node));
    fgets(expression,10000,stdin);
    //printf("%s",expression);
    char* tree_1;
    tree_1=(char*)malloc(sizeof(char)*10000);
    tree_1=INFIXTOPOSTFIX(expression); //function call
    //printf("tree_1:  %s\n",tree_1);
    char exp[10000];
    exp[0]=expression[0];
    exp[1]=expression[1];
    int o=2;
     for(int i=0;tree_1[i]!='\0';i++)
        exp[o++]=tree_1[i];
    exp[o]='\0';
   expression_tree=construct_expressiontree(exp);
    postorder_tree(expression_tree);
    return 0;
}

