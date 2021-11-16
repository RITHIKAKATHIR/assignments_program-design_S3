#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
 struct participate{
    char reg_id[10];
    int inst_no;
    struct participate* next;
    };
 struct head_pointer{
     struct participate* head;
 };

struct participate* create_node(char* k, int d){
    struct participate* newnode ;
    newnode=(struct node*)malloc(sizeof(struct participate));
    if(newnode==NULL)
     exit(0);
    strcpy(newnode->reg_id,k);
    newnode->inst_no=d;
    newnode->next=NULL;
    return newnode;
}
void insert_node(struct head_pointer* list, struct participate* temp){
    struct participate* max;
    struct participate* temp1;
    struct participate* previous;
    temp1=list->head;
    previous=temp1;
    if(list->head==NULL)
       list->head=temp;
    else{
        while(temp1!=NULL && temp1->inst_no!=temp->inst_no){
            previous=temp1;
            temp1=temp1->next;
        }
        if(temp1!=NULL){
             temp->next=temp1;
             if(temp1=previous)
             list->head=temp;
             else
             previous->next=temp;
        }
      else{
            if(temp1->inst_no<temp->inst_no){
                list->head=temp;
                temp->next=temp1;
            }
            else{
                while(temp1!=NULL&& temp1->next!=NULL && temp1->inst_no>temp->inst_no){
                    previous=temp;
                    temp1=temp1->next;

                }
              if(temp1->next==NULL)
             {
           temp1->next=temp;
            }
       else
        {  
         temp->next=previous->next;
         previous->next=temp;
        } 
            }
      }
    }


}
void PRINT_LIST(struct head_pointer* LL){
  struct participate* selected=LL->head; 
  if(LL->head==NULL) {
      printf("-1\n");
      return ;
  }
  while(selected!=NULL) {
       printf("%s ",selected->reg_id); 
       selected=selected->next; 
       }
       printf("\n");
 }
 void count(struct head_pointer* LL, int k){
      struct participate* temp1;
     int count=0;
     while(temp1!=NULL){
     if( temp1->inst_no==k){
       count++;
       temp1=temp1->next;
     }
   }      

  printf("%d",count);
 }
 void search(struct head_pointer* LL, int k){
     struct participate* temp1=LL->head;
    int count_before=0;
     int count=0;
     while(temp1!=NULL){
         if(temp1->inst_no!=k)
         {
          count_before++;
         temp1=temp1->next;
         }
         else
         {
          count++; 
          temp1=temp1->next;
         }
     }
  printf("%d %d\n",count_before,count);
 }
 int main(){

 char ch;
  char* key_1;
  key_1=(char*)malloc(10*sizeof(char));
  int inst_no1;
  int key_2;
  struct head_pointer*L;
  struct participant* temp; 
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
			case 'r':	
                        scanf(" %s %d",&key_1,&inst_no1);
                        temp=create_node(key_1,inst_no1);
                        insert_node(L,temp);
                        
						break;
            
            case 'p':  PRINT_LIST(L);
                        break;
            
             case 'c':  scanf(" %d",&key_2);
                        count(L,key_2);
                        break;
             
            case 's': scanf(" %d",&key_2);
                        search(L,key_2);
                        break;

            case 't':  return 1;
                      
		}
	}
    
  return 0;
}

