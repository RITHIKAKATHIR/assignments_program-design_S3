#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void max_heapify(int*A,int i,int n){
 
 int l,r;
 int largest=i;
 l=(2*i)+1;
 r=(2*i)+2;

  
  if(l<=n){ 
   
    if(A[l]>A[i])
   {  
     largest=l;
  
   }
  }

  if(r<=n){ 
  
    if(A[r]>A[largest])
   {
    largest=r;
   }
  }
  
 
  int temp;
  if(largest!=i)
   {
    temp=A[i];
    A[i]=A[largest];
    A[largest]=temp;
    max_heapify(A,largest,n);
    }

}
 
 void build_heap(int*A,int n)
 {

  for(int i=(n/2);i>=0;i--)
  {
    max_heapify(A,i,n);
  }
 
 }

 void heapsort(int*A, int n){
     int n1=n;
     int heapsize=n;
     build_heap(A,n);
    

     /* printf("\n");
     for(int j=0;j<=n;j++){
      printf("%d ",A[j]);
     } */
    
     int temp;
     int j;
     for(j=n1;j>=1;j--)
    {
      temp=A[j];
      A[j]=A[0];
      A[0]=temp;
      heapsize--;
      max_heapify(A,0,heapsize);
    }
}

void insert_patients(int*A, int  n){
     heapsort(A, n);
}

int extract_next_patient(int*A,int count){
    int to_be_Disp;
    to_be_Disp=*(A+0);
    for(int j=0;j<count;j++){
        A[j]=A[j+1];
    }

    return to_be_Disp;
}

void get_next_patient(int* A, int count){
    printf("%d",A[0]);
    printf("\n");
}

void change_token_number(int* A,int count, int org){
 int new;
 scanf("%d",&new);

  for(int i=0;i<count;i++)
  {
    if(A[i]==org && new<org)
    {
       A[i]=new;
    }
  }

  heapsort(A,count-1);

}

void display_queue(int* A, int count){
    for(int i=0;i<count;i++){
        printf("%d",*(A+i));
    }
}


int main(){
    char ch;
    int count=0;
    int array_A[10000];
    int token;
    int to_be_changed;
    int max;
    while (1)
	{
		scanf("%c", &ch);

		switch (ch)
		{
			case 'i' :     scanf("%d",&token);
                           array_A[count]=token;
                           insert_patients(array_A,count);
                           count++;
                           break;
            
             case 'e':    if(count==0){
                           printf("-1"); 
                           printf("\n");
                          }  
                           if(count!=0){
                            max=extract_next_patient(array_A,count);	
                            count--;
                            printf("%d ",max);
                            printf("\n");
                          }
              
                         break;

			case 'm':      if(count==0) {
                           printf("-1");
                           printf("\n");
                         }
                           if(count!=0){
                            get_next_patient(array_A,count);
                            printf("\n");
                          }
                          break;

            case 'c': 	 scanf("%d",&to_be_changed);
                         change_token_number(array_A,count,to_be_changed);
                         break;
            
            case 'd':  display_queue(array_A,count);
                         break;
           
            case 's':   return 1;

		}
   }

  return 0;
}