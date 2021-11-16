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

struct node* construct_expressiontree(char expression[10000])  //fucntion for tree construction
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

char* INFIXTOPOSTFIX(char* e)  //func to convert infix to postfix
{   char check;
    int j,j1;
    struct stack s1;
    s1.top=-1;
    char* to_r;
    to_r=(char*)malloc(2000*sizeof(char));
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

void preorder_tree(struct node* tree)  //func to print preorder of a expression tree
{
     if(tree!=NULL)
     {  printf("%c",tree->key);
        preorder_tree(tree->lchild);
        preorder_tree(tree->rchild);
    }
}

int main(){
    FILE *fptr;
    char filename[100];
    //Enter the filename to open
    scanf("%s", filename);
    fptr = fopen(filename, "r"); //open the file
    if(fptr==NULL)
    { //if file does not exist
      exit(0);
    }
    char h;
    int i=0;
    char c[2000];   
    h = fgetc(fptr);//gets the first character from the file and copies it into string
    c[i++]=h; 


while (h!= EOF)
{ //while loop is executed until EOF (End of File) is reached
  h=fgetc(fptr);
  if(h!='\n')
   {c[i]=h;
    i++;
   }
  else
  {c[i]='\n';
   i++;
  }
}
i=i-1;
c[i]='\0';
//while loop copied every character of the file into a string named c
char expression[200][2000];
int k=0;
int j=0,i_1=0;

for(i_1=0,j=0;c[i_1]!='\0';i_1++)  //expression is an two dimensional array 
{                                  //every row of this expression contains expression from the file
if(c[i_1]!='\n')
   expression[k][j++]=c[i_1];
else
   {   expression[k][j++]='\0';
       j=0;
       k=k+1;
   }
   
}
 struct node* expression_tree;    //dynamically allocating the tree
 expression_tree=(struct node*)malloc(sizeof(struct node));

  char* tree_1;     //dynamically allocating an array to store the postfix expression of every infix expression from the file
  tree_1=(char*)malloc(sizeof(char)*2000); 

   char exp[2000];

 for(int i=0;i<=k;i++)
 {
  
  tree_1=INFIXTOPOSTFIX(*(expression+i)); //function call to convert infix to postfix
   exp[0]=**(expression+i);     //creating can array with right hand side of 
                               //the expression statement, followed equal to sign and
                               // postfix form of left hand side of expression statement
    exp[1]=*(*(expression+i)+1);
    int o=2;
    for(int i=0;tree_1[i]!='\0';i++)
        exp[o++]=tree_1[i];
    exp[o]='\0';
    //printf("%s\n",exp);
   expression_tree=construct_expressiontree(exp); //call func to construct tree
    preorder_tree(expression_tree); //to traverse the tree in preorder: root->lchild->rchild
   printf("\n");
}





return 0;
}