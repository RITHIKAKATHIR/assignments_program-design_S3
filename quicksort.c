#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int partition(int*A,int start,int end);
void quicksort(int* A_1,int start_1,int end_1){
 if(start_1<end_1){
    int q;
    q=partition(A_1,start_1,end_1);
    quicksort(A_1,start_1,q-1);
    quicksort(A_1,q+1,end_1);
  }
}
int main(){
    int* A_2;
    int n;
    scanf("%d",&n);

    A_2=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    scanf("%d",&A_2[i]);

      for(int k=0;k<n;k++){
        printf(" %d ",A_2[k]);
    }

    quicksort(A_2,0,n-1);
    printf("\n");
    for(int k=0;k<n;k++){
        printf(" %d ",A_2[k]);
    }

    return 0;
}
int partition(int*A,int start,int end){
    int pivot;
    int trans;
    pivot=A[end];
    int i=start;
    int j;
    for(j=start;j<=(end-1);j++){
        if(A[j]<=pivot){
            trans=A[j];
            A[j]=A[i];
            A[i]=trans;
            i++;
        }
       
    }

    int fin;
    fin=A[i];
    A[i]=pivot;
    A[j]=fin;


    return i;
}
