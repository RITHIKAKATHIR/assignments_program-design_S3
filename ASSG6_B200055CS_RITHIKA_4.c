#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node* lchild;
    struct node* rchild;
    struct node* next;
};

struct top
{
    struct node* top_pointer;
};

struct node* create_node(int k,struct node* l,struct node* r)
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

struct node* construct_expressiontree(char expression[10000]){
    //printf("heyyy");
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
    for(i=0;expression[i]!='\0'&&expression[i]!=' '&&expression[i]!='\n';i++)
    {   //printf(" %c ",expression[i]);
        if((expression[i]>=97 && expression[i]<=122)||(expression[i]>=65 && expression[i]<=90))
        {
            temp=create_node(expression[i],NULL,NULL);
           // printf("%c",temp->key);
            push(temp,top);
        }
        else
        {   //printf(" entered ");
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
    struct node* selected;
    selected=(struct node*)malloc(sizeof(struct node));
    selected=top->top_pointer;
    while(selected->next!=NULL){
       selected=selected->next;
   }

   /*printf("%c",selected->key);
   if(selected->lchild!=NULL)
   printf("%c",selected->lchild->key);
   if(selected->rchild!=NULL)
   printf("%c",selected->rchild->key);*/

   return selected;

}
void inorder_tree(struct node* tree)
{
    if(tree!=NULL){
        inorder_tree(tree->lchild);
        printf("%c",tree->key);
        inorder_tree(tree->rchild);
    }

}
void preorder_tree(struct node* tree)
{
     if(tree!=NULL)
     {  printf("%c",tree->key);
        preorder_tree(tree->lchild);
        preorder_tree(tree->rchild);
    }
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

int main(){
    char expression[10000];
    struct node* expression_tree;
    expression_tree=(struct node*)malloc(sizeof(struct node));
    char ch;
    char ch1;
    char a;
    while (1)
	{
		scanf("%c",&ch);

		switch (ch)
		{
			case 'e':	scanf("%c",&ch1);
                        fgets(expression,10000,stdin);
                        //printf("%s",expression);
                        expression_tree=construct_expressiontree(expression);
                        /*printf("im back");
                        printf("%c",expression_tree->key);
                        if(expression_tree->lchild!=NULL)
                        printf("%c",expression_tree->lchild->key);
                        if(expression_tree->rchild!=NULL)
                        printf("%c",expression_tree->rchild->key);
                        print_tree(expression_tree);*/
                        break;

			case 'i':	inorder_tree(expression_tree);
                        printf("\n");
						break;

			case 'p':	preorder_tree(expression_tree);
                        printf("\n");
						break;

			case 's':	postorder_tree(expression_tree);
                        printf("\n");
						break;

			case 't': 	return 1;
		}
	}
    
    return 0;
}