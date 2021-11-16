#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{   char key;
    struct node* node_pointer;
};

struct head_pointer
{
    struct node* head;
};

struct node* create_node(char k){
    struct node* newnode ;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
     exit(0);
    newnode->key=k;
    newnode->node_pointer=NULL;
    return newnode;
}

struct node* list_search(struct head_pointer* L,char k)
{ 
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp=L->head;
  
  while(temp!=NULL && temp->key!=k)
    temp=temp->node_pointer;
    
 return temp;    
    
}

void LIST_INSERT_FRONT(struct head_pointer* LL,char key){
    struct node* to_be_inserted;
    to_be_inserted=(struct node*)malloc(sizeof(struct node));
    if(to_be_inserted==NULL)
     exit(0);
    to_be_inserted=create_node(key);
    if(LL->head==NULL)
    {
        LL->head=to_be_inserted;
        
    }
    else
    {
        to_be_inserted->node_pointer=LL->head;
        LL->head=to_be_inserted;
    }

}

void LIST_INSERT_TAIL(struct head_pointer* LL,char key){
   struct node* to_be_inserted;
   to_be_inserted=(struct node*)malloc(sizeof(struct node));
    if(to_be_inserted==NULL)
     exit(0);
   struct node* temp;
   temp=LL->head;
    to_be_inserted=create_node(key);
    if(LL->head==NULL)
       LL->head=to_be_inserted;
    else
    {
        while(temp->node_pointer!=NULL)
         temp=temp->node_pointer;

    temp->node_pointer=to_be_inserted;
    }
}

void LIST_INSERT_AFTER(struct head_pointer* LL,char key,char key1)
 {
  struct node* to_be_inserted;
  to_be_inserted=(struct node*)malloc(sizeof(struct node));
    if(to_be_inserted==NULL)
     exit(0);
  to_be_inserted=create_node(key);
  struct node* found;
  found=list_search(LL,key1);
   if(found!=NULL)
   {   if(found->node_pointer==NULL)
        {
         found->node_pointer=to_be_inserted;
        }
       else
        {  
         to_be_inserted->node_pointer=found->node_pointer;
         found->node_pointer=to_be_inserted;
        } 
  }

}

void LIST_INSERT_BEFORE(struct head_pointer* LL,char key, char key1)
{
 struct node* to_be_inserted;
 to_be_inserted=(struct node*)malloc(sizeof(struct node));
    if(to_be_inserted==NULL)
     exit(0);

 to_be_inserted=create_node(key);
 struct node* found;
 struct node* temp;
   
  temp=LL->head;
  found=temp;
 
 while(temp!=NULL && temp->key!=key1) //list empty means temp will be NUll
   {   found=temp;
       temp=temp->node_pointer;
   }

   if(temp==NULL)
   {
       LL->head=to_be_inserted;
   }
   else
   {
     if(found==temp)
     {   to_be_inserted->node_pointer=found;
          LL->head=to_be_inserted;
     }
     else
     {
         to_be_inserted->node_pointer=found->node_pointer;
         found->node_pointer=to_be_inserted;
     }
   
    } 
}

void LIST_DELETE(struct head_pointer* LL, char key_to_search)
{   struct node* temp;
    struct node* found;
    temp=LL->head;
    found=temp;
   
   while(temp!=NULL && temp->key!=key_to_search)
    {   found=temp;
       temp=temp->node_pointer;
    }

   if(temp==NULL)
 {
   printf("%d\n",-1);
   
 }
   else
 {
    if(found==temp)
    {   
        if(temp->node_pointer!=NULL)
        {
            printf("%c\n",temp->node_pointer->key);
            LL->head=temp->node_pointer;
        
        
        }
        else
        {
            printf("%d\n",-2);
            LL->head=temp->node_pointer;
            
            
        }
     }
   else
   {
         if(temp->node_pointer==NULL)
                printf("%d\n",-2);
         else
            printf("%c\n",temp->node_pointer->key);
            
            found->node_pointer=temp->node_pointer;
     }
  }
  
    free(temp);
 }

void LIST_DELETE_FIRST(struct head_pointer* LL)
{
     struct node* select;
     select=LL->head;
     if(LL->head==NULL){
         printf("-1\n");
     }
     else
     {
         printf("%c\n",select->key);
         LL->head=select->node_pointer;
         
     }
     free(select);
     
 }

void LIST_DELETE_LAST(struct head_pointer*LL)
{
     struct node* selected=LL->head;
     struct node* previous=selected; 
     
      if(selected==NULL) printf("-1\n"); 
      else 
      { 
          while(selected->node_pointer!=NULL) 
          { previous=selected; 
           selected=selected->node_pointer;
          } 

       printf("%c\n",selected->key); 
       if(previous==selected) LL->head=NULL;
       if(previous!=NULL) 
        previous->node_pointer=NULL;
       else LL->head=NULL; 
       selected=NULL;
     }
      
       free(selected);
        
 }
    
void PRINT_LIST(struct head_pointer* LL){
  struct node* selected=LL->head; 
  if(LL->head==NULL) {
      printf("-1\n");
      return ;
  }
  while(selected!=NULL) {
       printf("%c ",selected->key); 
       selected=selected->node_pointer; 
       }
       printf("\n");
 }
 
 int main()
 {char ch;
  char key_1;
  char key_2;
  struct head_pointer*L;
  L=(struct head_pointer*)malloc(sizeof(struct head_pointer));
  if(L==NULL){
      exit(0);
  }
   L->head=NULL;
   while (1)
	{
		scanf("%c",&ch);

		switch (ch)
		{
			case 'f':	
                        scanf(" %c",&key_1);
                        //printf("key is%c",key_1);
                        LIST_INSERT_FRONT(L,key_1);
						break;
            
            case 't':	
                        scanf(" %c",&key_1);
                        LIST_INSERT_TAIL(L,key_1);
                        break;

			case 'a':	
                        scanf(" %c %c",&key_1,&key_2);
                        LIST_INSERT_AFTER(L,key_1,key_2);
						break;

			case 'b':	
                        scanf(" %c %c",&key_1,&key_2);
                        LIST_INSERT_BEFORE(L,key_1,key_2);
						break;

			case 'd':	scanf(" %c",&key_1);
			            LIST_DELETE(L,key_1);
						break;

			case 'i': 	LIST_DELETE_FIRST(L);
                        break;

            case 'l':   LIST_DELETE_LAST(L);
                        break;

            case 'p':  PRINT_LIST(L);
                        break;

            case 'e':  return 1;
                      
		}
	}
    
  return 0;
}
