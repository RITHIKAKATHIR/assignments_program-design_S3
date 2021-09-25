#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int binary_recursive_func(int * array, int lower_index, int higher_index, int num_find);
int main(){
    int m,n;

    scanf("%d %d",&m,&n);
    
    int* A;
    A=(int*)malloc(m*sizeof(int));

    int* B;
    B=(int*)malloc(n*sizeof(int));

    for(int i=0;i<m;i++)
    scanf("%d",&A[i]);    //unsorted

     for(int i=0;i<n;i++)
    scanf("%d",&B[i]);   //sorted

    int found[100000];
    int display_output=0;
    int found_size=0;

    for(int i=0;i<m;i++){
    display_output=binary_recursive_func(B,0,n-1,A[i]);
    found[found_size++]=display_output;
    }
   
    
    for(int j=0;j<found_size;j++){
      if(found[j]!=-1){
       printf("%d ",found[j]);
       }
    }

  

 return 0;
}

int binary_recursive_func(int* array, int lower_index, int higher_index, int num_find){
    int mid_num;
    //printf(" 0.5entered ");

    if(lower_index<=higher_index){
        mid_num=lower_index+(higher_index-lower_index)/2;

        if(num_find==array[mid_num]){
        //printf(" 1entered ");
        return num_find;
        }

        if(array[mid_num]>num_find)
        { //printf(" 2entered ");
          return binary_recursive_func(array,mid_num+1,higher_index,num_find);
        }

        if(array[mid_num]<num_find)
        { 
         return binary_recursive_func(array,lower_index,mid_num-1,num_find);
        }

  }

  return -1;

    
}