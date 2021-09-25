#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int binary_search_recursive(int* num, int num_find, int array_size, int index);
int count_loop_call=0; //global variable for counting the recursion
int main()
{
    int array_size_n;                 //scanf in the size
    scanf("%d",&array_size_n);

    int* array_A;
    array_A=(int*)malloc(array_size_n*(sizeof(int)));  //dynamic declaration of array

    for(int i=0;i<array_size_n;i++){
        scanf("%d",&array_A[i]);       //taking in elements of array
    }

    int search_k;

    scanf("%d",&search_k); //scanning in the element to search for

   int search_binary;
   search_binary=binary_search_recursive(array_A,search_k,array_size_n-1,0);  //function call

   printf("%d",search_binary);  //print the index or -1 depending on inputs
   printf("\n%d",count_loop_call); //print the no.of recursion

  return 0;
}

int binary_search_recursive(int* num, int num_find, int array_size, int index){
  count_loop_call++;
 
 if(index<=array_size){
     
     int mid= index+(array_size-index)/2;  //find the middle element

    if(num_find==num[mid]){
     
      return mid;         
    }
    
    if(num_find<num[mid]){

      return binary_search_recursive(num,num_find,mid-1,index);
    }

    if(num_find>num[mid]){
       return binary_search_recursive(num,num_find,array_size,mid+1);
      }

    }

    return -1;  //incase the element isnt found
 }

   