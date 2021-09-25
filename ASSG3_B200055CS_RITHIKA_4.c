#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void merge(int* Array_1,int p_lower_1,int q_mid_1,int r_high_1);
void merge_sort_func(int* Array, int p_lower, int r_higher);
void print(int*A_array,int size_array);
int count_comparision=0;
int main(){
    int n;
    scanf("%d",&n);
    
    int*A;
    A=(int*)malloc(n*(sizeof(int)));
    
    for(int i=0;i<=(n-1);i++)
    scanf("%d",&A[i]);

    

    merge_sort_func(A,0,n-1);

    print(A,n);

    printf("\n%d",count_comparision);
    
    return 0;
}
void merge_sort_func(int* Array, int p_lower, int r_higher){
    int mid_index;
    if(p_lower<r_higher){
    mid_index=p_lower+((r_higher-p_lower)/2);
    merge_sort_func(Array,p_lower,mid_index);
    merge_sort_func(Array,mid_index+1,r_higher);
    merge(Array,p_lower,mid_index,r_higher);
    }
   
   return ;
}
void merge(int* Array_1,int p_lower_1,int q_mid_1,int r_high_1){
    int end_index_1=q_mid_1-p_lower_1+1;
    int end_index_2=r_high_1-q_mid_1;

    int* P;
    int* Q;
    P=(int*)malloc((end_index_1+1)*(sizeof(int)));
    Q=(int*)malloc((end_index_2+1)*sizeof(int));

    for(int i=0;i<end_index_1;){
        P[i]=Array_1[p_lower_1+i];
        i++;
    }
   
   for(int j=0;j<end_index_2;){
       Q[j]=Array_1[q_mid_1+j+1];
       j++;
   }

   P[end_index_1]=1000000;
   Q[end_index_2]=1000000;

   int i,j,h;

   i=0;
   j=0;
  
   /*while(i<(end_index_1-1) && j<(end_index_2-1)){
       count_comparision=count_comparision+1;
       if(P[i]<=Q[j]){
           Array_1[h]=P[i];
           i++;
       }
       else{
            Array_1[h]=Q[j];
           j++;
       }
       h++;
   }
   while(i<(end_index_1-1)){
       count_comparision=count_comparision+1;
       Array_1[h]=P[i];
       i++;
       h++;
   }
   while(j<(end_index_2-1)){
       count_comparision=count_comparision+1;
       Array_1[h]=Q[j];
       j++;
       h++;
   }*/

 for(h=p_lower_1;h<=r_high_1;h++)
    {count_comparision=count_comparision+1;
      if(P[i]<=Q[j]){
           Array_1[h]=P[i];
           i++;
           }
      else{
          Array_1[h]=Q[j];
          j++;
           }
    }
  

}

void print(int*A_array,int size_array){
    for(int i=0;i<size_array;i++)
    printf("%d ",A_array[i]);
   }