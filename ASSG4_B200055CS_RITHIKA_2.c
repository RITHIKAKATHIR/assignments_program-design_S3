#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct student
{ int student_id;
  char student_name[25];
  int rank;
};

void max_heapify(struct student* A,int i,int n){
 int l,r;
 int largest=i;
 l=(2*i)+1;
 r=(2*i)+2;
 if(l<=n && A[l].rank>=A[i].rank)
   {
   largest=l;
   }
 if(r<=n && A[r].rank>=A[largest].rank)
   {
    largest=r;
   }
 
  struct student temp;
  if(largest!=i){
    temp=A[i];
    A[i]=A[largest];
    A[largest]=temp;
    max_heapify(A,largest,n);
    }

}
 
struct student interview(struct student* A,int count)
{
    

  struct student max_1;
  max_1=A[0];
  for(int j=0;j<count;j++){
  A[j]=A[j+1];
  }
  return max_1;
}

void build_heap(struct student*A,int n)
{
  for(int i=(n/2);i>=0;i--)
  {
      max_heapify(A,i,n);
  }
}

void heap_sort(struct student*A, int n){
     int n1=n;
     int heapsize=n;
     build_heap(A,n);
     struct student temp;
     int j;
     for(j=n1;j>=1;j--)
     {
      temp=A[j];
      A[j]=A[0];
      A[0]=temp;
      heapsize--;
      max_heapify(A,0,heapsize);
    }

   /*for(int i=0;i<=n1;i++){
        printf("%d ",A[i].student_id);
        printf("%s ",A[i].student_name);
        printf("%d \n",A[i].rank);
     }*/
}
/*void heap_increase_key(struct student* A, int i,int key)
{

    //A[i].rank=key;
    struct student temp;
    for(;i>=0 && (A[i-1].rank>A[i].rank);i--)
    {
      temp=A[i];
      A[i]=A[i-1];
      A[i-1]=temp;
    }
}*/

void enter(struct student* A, int count){
    scanf("%d",&A[count].student_id);
    scanf("%s",A[count].student_name);
    scanf("%d",&A[count].rank);
  
    heap_sort(A,count);
}

void list(struct student* A, int count){
    
    for(int i=0;i<count;i++){
        printf("%d ",A[i].student_id);
        //printf("%s ",A[i].student_name);
        //printf("%d ",A[i].rank);
      }
    
}
int main(){
    char ch;
    struct student studentarray[100];
    int count=0;
    struct student max;
    while (1)
	{
		scanf("%c", &ch);

		switch (ch)
		{
			case 'e': enter(studentarray,count);
                count++;
                break;
    case 'i':   
    
                if(count==0){
                printf("-1"); 
                printf("\n");
                }  
                if(count!=0){
                max=interview(studentarray,count);	
                count--;
                printf("%d ",max.student_id);
                printf("%s ",max.student_name);
                printf("\n");
                }
                //printf("%d ",max.rank);
                break;

			case 'l': 
                   if(count==0) {
                     printf("-1");
                     printf("\n");
                    }
                   if(count!=0){
                     list(studentarray,count);
                     printf("\n");
                   }
                break;

       case 't': 	return 1;
		}
    
	}

  return 0;

}
