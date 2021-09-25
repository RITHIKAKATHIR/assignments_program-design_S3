#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void InsertionSortAs(int*,int);
void InsertionSortDs(int*,int);
void Print(int*,int);

int main(){
  int m;
  scanf("%d",&m);

  int* num_arr;
  
  num_arr=(int*)malloc(m*sizeof(int));

  for(int i=0;i<m;i++)
  scanf("%d",&num_arr[i]);

  

  int num_arr_even[1000];
  int num_arr_odd[1000];
  int even_ele=0;
  int odd_ele=0;

  for(int i=0;i<m;i++){
    if(i%2==0){
      num_arr_even[even_ele++]=num_arr[i];
    }
    if(i%2!=0){
       num_arr_odd[odd_ele++]=num_arr[i];
    }

  }





  InsertionSortAs(num_arr_even,even_ele);

  InsertionSortDs(num_arr_odd,odd_ele);

  Print(num_arr_even,even_ele);

  printf("\n");

  Print(num_arr_odd,odd_ele);
 
  

 return 0;
}

void InsertionSortAs(int* a,int e){
  int i, j,key;
  for(i=1;i<e;i++)
  {
     j=i-1;
     key=a[i];
     while(j>=0 && a[j]>key)
     {
       a[j+1]=a[j];
       j--;
     }
     a[j+1]=key;
  }

}

void InsertionSortDs(int* AR,int O){
 
 int i, j,key;
  for(i=1;i<O;i++)
  {
     j=i-1;
     key=AR[i];
     while(j>=0 && AR[j]<key)
     {
       AR[j+1]=AR[j];
       j--;
     }
     AR[j+1]=key;
  }

}



void Print(int* a_1,int num_1){

  for(int i=0;i<num_1;i++){
    printf("%d ",a_1[i]);
  }
}