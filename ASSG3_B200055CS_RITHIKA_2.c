#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int binary_recursion_occ(int* A,int lower_index, int higher_index,int search_num);

int count=0,found=0;

int main(){
    int n;
    scanf("%d",&n); //scan in the the no. of elements

    int A[1000];

    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);  //scan the elements
    
    int search_num_1;
    scanf("%d",&search_num_1); //search for a particular element

    int output;

    output=binary_recursion_occ(A,0,n-1,search_num_1); //call statement
    
    if(found==1){
    printf("%d",output);  
    }
    else printf("%d",-1); //print -1 if the element isnt found

    printf("\n%d",count);

    return 0;
}

int index_1=0;

int binary_recursion_occ(int* A,int lower_index, int higher_index,int search_num){

 int mid;
 count=count+1;

 if(lower_index<=higher_index){
  
  mid=lower_index+((higher_index-lower_index)/2);  //find the middle element

  if(A[mid]==search_num){
   index_1=mid;
   found=1;
    if(A[mid-1]==search_num)
    binary_recursion_occ(A,lower_index,mid-1,search_num); //find the first occurence 
   }
     
   if(A[mid]<search_num && found==0){
   binary_recursion_occ(A,mid+1,higher_index,search_num);
  }
 
   if(A[mid]>search_num &&found==0){
  
     binary_recursion_occ(A,lower_index,mid-1,search_num);
  }
 
}

return index_1; //return index

}