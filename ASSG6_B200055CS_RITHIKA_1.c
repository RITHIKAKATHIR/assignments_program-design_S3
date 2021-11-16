#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;                    //declaration of node
    struct node* next;
};

struct top{                                //top
    struct node* top_pointer;
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

void push(struct top* top, struct node* nodenow){
    if(top->top_pointer==NULL){         //checking if top is pointing to null
        top->top_pointer=nodenow;       //if top is pointing to null, assigning new node to top
    }
    else{
        nodenow->next=top->top_pointer; //else we are entering newnode as the first element
        top->top_pointer=nodenow;
    }
}

int is_empty(struct top* top){
    if(top->top_pointer==NULL)
      return -1;            //if top points to NULL, list is empty: return -1
    else
      return 1;     //if list not empty return 1
}

void pop(struct top* top){

  struct node* to_push;
  to_push=(struct node*)malloc(sizeof(struct node));
  to_push=top->top_pointer;    //to_push points to the first element
  int check;
  check=is_empty(top);  //list underflow condition is checked
  if(check==-1) printf("-1\n");
  else{ 
     printf("%d\n",to_push->data);    //first element's data is printed
     top->top_pointer=to_push->next;  //top points to the next element in the stack
     }
  }

int main(){
    char ch;  //to choose from the menu
    int num;  //to scan in the number from user
    int r;   //to check list underflow condition
    struct node* temp; 
    struct top* top_stack;  //creation of top
    top_stack=(struct top*)malloc(sizeof(struct top));
    if(top_stack==NULL) exit(0);
    top_stack->top_pointer=NULL; //initially top points to NULL as list is empty
    while(1){
        scanf("%c",&ch); //to choose from the menu

        switch(ch){ 
            case 'i':       scanf(" %d",&num);      //scanning in the data
                            temp=create_node(num);  //creation of a node
                            push(top_stack,temp);  //push function call
                            break;

            case 'd':        pop(top_stack);  //pop function call
                             break;

            case 'e':        r=is_empty(top_stack);  //to check undeflow condition
                             printf("%d\n",r);
                             break;

            case 't':        return 1; //to terminate the program
        }

    }
    return 0;
    
}