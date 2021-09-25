#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int sum_of_arr(int*,int n);

int main(){
  int n;
  scanf("%d",&n);
  int *arr;
  arr=(int*)malloc(sizeof(int)*n);
  
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);    //to scan in elements
  }
 
 int pos_sub_arr[100];
 int neg_sub_arr[100];
 int count_pos=0;
 int count_neg=0;
 int max_sum=0;

 for(int i=0;i<n;i++){
    if(arr[i]>=0){
        pos_sub_arr[count_pos++]=arr[i];
    }
    else if(arr[i]<=0){
       neg_sub_arr[count_neg++]=arr[i];
    }

 }
 
 int flag=0;

 if(count_pos>0){
 max_sum=sum_of_arr(pos_sub_arr,count_pos);

 int display_Count=0;

 display_Count=count_pos;

 printf("%d %d",max_sum, display_Count);
 flag=1;

 }
 if(count_neg>0 && flag!=1){

   int min=0;
   int display=1;

   min=neg_sub_arr[0];

   for(int j=0;j<count_neg;j++){
        if(neg_sub_arr[j]>min){
            min=neg_sub_arr[j];
        }
   } 

   if(min==0){
     for(int k=0;k<count_neg;k++){
       if(min==neg_sub_arr[k])
       display=display+1;
     }
   }

    printf("%d %d",min,display);
 }
 
  return 0;
}

int sum_of_arr(int* a,int n){

  int sum=0;
  for(int i=0;i<n;i++)
    sum=sum+a[i];
  
  return sum;
}