#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int max_heapify(int*A,int i,int n){
 int comparison=0;
 int l,r;
 int largest=i;
 l=(2*i)+1;
 r=(2*i)+2;

  
  if(l<=n){ 
    comparison++;
    if(A[l]>A[i])
   {  
     largest=l;
  
   }
  }

  if(r<=n){ 
    comparison++;
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
    comparison=comparison+max_heapify(A,largest,n);
    }

  return comparison;

}
 
 int build_heap(int*A,int n)
 {int num=0;

  for(int i=(n/2);i>=0;i--)
  {
    num=num+max_heapify(A,i,n);
  
  }

 
  return num; 
}

int heap_sort(int*A, int n){
     int n1=n;
     int heapsize=n;
     
     int count=0;
     count=count+build_heap(A,n);
    

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
      count=count+max_heapify(A,0,heapsize);
    }

   return count;
}

void main(){
    int* array;
    int size;
    scanf("%d",&size);
    array=(int*)malloc(size*sizeof(int));

    for(int k=0;k<size;k++){
        scanf("%d",&array[k]);
    }
   
   /*for(int j=0;j<size;j++){
      printf("%d ",array[j]);
    }*/

     int disp;

     disp=heap_sort(array,size-1);

     for(int j=0;j<size;j++)
     {
        printf("%d ",array[j]);
     }

     printf("\n");
     printf("%d",disp);
}
 