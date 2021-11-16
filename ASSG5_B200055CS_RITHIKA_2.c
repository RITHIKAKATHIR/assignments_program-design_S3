#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node* next;
    struct node* prev;
};

struct head_pointer
{
    struct node* head;
};

struct node* create_node(int k)
{
    struct node* newnode ;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
     //printf("full");
     exit(0);
     
    }
    newnode->key=k;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    return newnode;
}

struct node* list_search(struct head_pointer* L,int k)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
   if(temp==NULL) exit(0);
  
  temp=L->head;
  
  while(temp!=NULL && temp->key!=k)
    temp=temp->next;
    
 return temp;    
    
}

void LIST_INSERT_FRONT(struct head_pointer*LL,struct node*to_be_inserted)
{   struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL) exit(0);

    temp=LL->head;
    
    if(LL->head==NULL)
    {
        LL->head=to_be_inserted;
        
    }
    else
    {   
        to_be_inserted->next=LL->head;
        temp->prev=to_be_inserted;
        LL->head=to_be_inserted;
        
    }

}

void LIST_INSERT_TAIL(struct head_pointer* LL,struct node* to_be_inserted)
{  struct node* temp;
   temp=(struct node*)malloc(sizeof(struct node));
   if(temp==NULL) exit(0);
   temp=LL->head;
   if(LL->head==NULL)
      LL->head=to_be_inserted;
   else
   {
       while(temp->next!=NULL)
        temp=temp->next;
             
      to_be_inserted->next=NULL;
      to_be_inserted->prev=temp;
      temp->next=to_be_inserted;
    }
}

void LIST_INSERT_AFTER(struct head_pointer* LL,struct node* to_be_inserted,struct node* found)
 {
     if(found!=NULL)
     {
        if(found->prev!=NULL && found->next!=NULL) //middle
       {    
         to_be_inserted->prev=found;
         to_be_inserted->next=found->next;
         found->next->prev=to_be_inserted;
         found->next=to_be_inserted;
        } 
        else if(found->prev==NULL && found->next!=NULL) //first element will elements following it
       {    
          to_be_inserted->next=found->next;
          to_be_inserted->prev=found;
          found->next->prev=to_be_inserted;
          found->next=to_be_inserted;
       }
       else if(found->prev!=NULL && found->next==NULL) //last
       {
         to_be_inserted->prev=found;
         found->next=to_be_inserted;
         to_be_inserted->next=NULL;
       
       }
      else if(found->prev==NULL && found->next==NULL) //one element only
       {
         to_be_inserted->prev=found;
         found->next=to_be_inserted;
         to_be_inserted->next=NULL;
       }
    }
  else 
   {
       printf("Not Found\n");
   }

}

void LIST_INSERT_BEFORE(struct head_pointer* LL,struct node* to_be_inserted,struct node* found)
{
  if(found!=NULL)
 {   
     if(found->prev!=NULL && found->next!=NULL) //middle
    {    
         to_be_inserted->prev=found->prev;
         to_be_inserted->next=found;
         found->prev->next=to_be_inserted;
         found->prev=to_be_inserted;
    } 
     else if(found->prev==NULL && found->next!=NULL)  //first element with following elements
    {   
        LL->head=to_be_inserted;
       to_be_inserted->next=found;
       found->prev=to_be_inserted;
       
    }
     else if(found->prev!=NULL && found->next==NULL) //last
    {
        to_be_inserted->next=found;
        to_be_inserted->prev=found->prev;
        found->prev->next=to_be_inserted;
        found->prev=to_be_inserted;
        found->next=NULL;
        
    }
     else if(found->prev==NULL && found->next==NULL) 
    {
        LL->head=to_be_inserted;
        to_be_inserted->next=found;
       found->prev=to_be_inserted;
       
    }
 }
 else
 {
     printf("Not Found\n");
  }
   
}

void LIST_DELETE(struct head_pointer* LL, struct node* found)
 {
   if(found!=NULL)
   {
       if(found->prev==NULL && found->next!=NULL)
       {   printf("%d\n",found->next->key);
           LL->head=found->next;
           found->next->prev=NULL;
        }
       else if(found->prev==NULL && found->next==NULL)  
       {   printf("NULL\n");
           LL->head=NULL;
        }
       else if(found->prev!=NULL && found->next!=NULL ) 
       {   printf("%d\n",found->next->key);
           found->prev->next=found->next;
           found->next->prev=found->prev;
       }
       else if(found->prev!=NULL && found->next==NULL)  
       {    printf("NULL\n");
            found->prev->next=NULL;
       } 
   }
  else
  {
   printf("Not Found\n");
  }

   free(found);
    
 }
 
void LIST_DELETE_INITIAL(struct head_pointer* LL)
 {
     struct node* select;
     select=LL->head;
     if(LL->head==NULL)
     {
         printf("Not Found\n");
     }
     else
     {
         
         printf("%d\n",select->key);
         
         LL->head=select->next;
         if(select->next!=NULL)
         {
             select->next->prev=NULL;
         }
         
     }
     free(select);
     
 }

void LIST_DELETE_LAST(struct head_pointer* LL)
 {
     struct node* temp;
     temp=LL->head;
     if(temp==NULL)
     {
         printf("Not Found\n");
        
     }
     else{
  
       while(temp->next!=NULL)
             temp=temp->next;
         
         printf("%d\n",temp->key);
         if(temp->prev!=NULL)
         temp->prev->next=NULL;
         else 
         LL->head=NULL;
     }
         
         free(temp);
 }

void PRINT_LIST_REVERSE(struct head_pointer*LL,int key_1)
{
  struct node* selected=list_search(LL,key_1);

  if(selected==NULL)
   {
      printf("Not found");
   }
   while(selected!=NULL)
   {
       printf("%d ",selected->key);
       selected=selected->prev;
   }

   printf("\n");
} 

/*void PRINT_LIST(struct head_pointer* LL)
 {
  struct node* selected=LL->head; 
   if(LL->head==NULL) 
   {
      printf("Not Found");
     
   }
   while(selected!=NULL) 
    {  
       printf("%d ",selected->key); 
       selected=selected->next; 
    }
       printf("\n");
 }*/

int main()
 {char ch;
  int key_1;
  int key_2;
  struct head_pointer* L;
  
  L=(struct head_pointer*)malloc(sizeof(struct head_pointer));
  if(L==NULL) exit(0);
 
  struct node* x;
  x=(struct node*)malloc(sizeof(struct node));
  if(x==NULL) exit(0);
  
  struct node* y;
  y=(struct node*)malloc(sizeof(struct node));
  if(y==NULL) exit(0);
  
  L->head=NULL;
  
 while (1)
 {
	 scanf("%c",&ch);

		switch (ch)
		{
			case 'f':	
                        scanf(" %d",&key_1);
                        x=create_node(key_1);
                        LIST_INSERT_FRONT(L,x);
						break;
            case 't':	
                        scanf(" %d",&key_1);
                        x=create_node(key_1);
                        LIST_INSERT_TAIL(L,x);
                        break;

		    case 'a':	
                        scanf(" %d %d",&key_1,&key_2);
                        x=create_node(key_1);
                        y=list_search(L,key_2);
                        LIST_INSERT_AFTER(L,x,y);
						break;

		   	case 'b':	
                        scanf(" %d %d",&key_1,&key_2);
                        x=create_node(key_1);
                        y=list_search(L,key_2);
                        LIST_INSERT_BEFORE(L,x,y);
						break;

		    case 'd':	scanf(" %d",&key_1);
		                y=list_search(L,key_1);
		                //printf("%d",y->key);
		                LIST_DELETE(L,y);
						break;

			case 'i': 	LIST_DELETE_INITIAL(L);
                        break;

            case 'l':   LIST_DELETE_LAST(L);
                        break;

            /*case 'p':  PRINT_LIST(L);
                        break;*/
             
            case 'r':   scanf(" %d",&key_1);
                        PRINT_LIST_REVERSE(L,key_1);
                        break;   

            case 'e':  return 1;
                      
		}
 }
    
  return 0;
}

