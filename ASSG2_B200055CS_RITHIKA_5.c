#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void sort_A(int* arr, int n_1){
  int i,j,temp;
  for(i=0;i<n_1;++i)
  {
    for(j=0;j<(n_1-i-1);j++){
       if(arr[j]>arr[j+1]){
         temp=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=temp;
       }
    }
  }
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int A[1000];

  for(int j=0;j<n;j++)
   scanf("%d",&A[j]);
   
  sort_A(A,n);



  int min_sum=0;
  int max_sum=0;

  for(int p=0;p<(n-m);p++)
  {
    min_sum=A[p]+min_sum;
  }



 

  
  int f=n-1;
 

  for(int p_1=f;p_1>(f-(n-m));p_1--)
  {
     max_sum=A[p_1]+max_sum;
     
  }


 

  int disp_sum=0;

  disp_sum=max_sum-min_sum;

  printf("%d",disp_sum);
   
 return 0;
}