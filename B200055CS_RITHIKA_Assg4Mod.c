#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void max_heapify(int*A,int i,int n){
 int l,r;
 int largest=i;
 l=(2*i)+1;
 r=(2*i)+2;
 if(r<=n){ 
    if(A[r]>A[i])
   {  
     largest=r;
  
   }
  }
 if(l<=n){ 
     if(A[l]>A[largest])
   {
    largest=l;
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

void heap_sort(int*A, int n){
     int n1=n;
     int heapsize=n;
     build_heap(A,n);
    /* for(j=n1;j>=1;j--)
    {
      temp=A[j];
      A[j]=A[0];
      A[0]=temp;
      heapsize--;
      max_heapify(A,0,heapsize);
    }

     printf("\n");
     for(int j=0;j<=n;j++){
      printf("%d ",A[j]);
     } */
}
 void max_heap_insert(int * array_of_choco,int n){
    int count_1=0;
    for(int i=0;i<=n;i++){
        scanf("%d",&array_of_choco[i]);
        
        count_1++;
    }
    heap_sort(array_of_choco,count_1-1);

}

int pick_choco(int*array_of_choco,int count){

    printf("\n");
     for(int j=0;j<=count;j++){
      printf("%d ",array_of_choco[j]);
     }
    
    int max_pick;
    max_pick=array_of_choco[0];
    if(array_of_choco[0]%2==0)
      array_of_choco[0]=array_of_choco[0]/2;
    else
      array_of_choco[0]=(array_of_choco[0]-1)/2;
    
    heap_sort(array_of_choco,count);
    

    return max_pick;

}
int main(){
    int pick;
    int N,M;
    scanf("%d",&N);
    scanf("%d",&M);
    int* array_of_choco;
    array_of_choco=(int*)malloc(N*sizeof(int));
    max_heap_insert(array_of_choco,N-1);
    for(int k=1;k<=M;k++){
        pick=pick+pick_choco(array_of_choco,N-1);
    }

    printf("\n%d",pick);


 return 0;
}
