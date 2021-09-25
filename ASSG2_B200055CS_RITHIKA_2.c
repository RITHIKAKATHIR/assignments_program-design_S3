#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){
  int n;
  scanf("%d",&n);
 
  int array[10000];

  for(int i=0;i<=(n-1);i++)
     scanf("%d",&(*(array+i)));

  int num=0,rem=0,check=0, flag_check=0;

  for(int j=0;j<n;j++)
  {

    if(!(array[j]>=0 && array[j]<=9))
    {
     
             num=abs(array[j]);
             while(num!=0 && (num%10<=rem || check==0)){
               rem=num%10;
               num=num/10;
               check=1;
            }
          
      if(num==0){
          printf("%d ",array[j]);          
          flag_check=1;
      }

    }

    if(array[j]>=0 && array[j]<=9)
    {
      printf("%d ",array[j]);
      flag_check=1;
    }

    check=0;
 
  }

  if(flag_check!=1)
  printf("%d",-1);



  return 0;
}