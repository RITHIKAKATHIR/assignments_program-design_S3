#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);

    int*array_of_no;
    array_of_no=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    scanf("%d",&array_of_no[i]);

    int spe;

    scanf("%d",&spe);

    printf("%d ",1);
    for(int i=0;i<n;i++)
    printf("%d",array_of_no[i]);

    int even[100][100];
    int odd[100][100];
    
    int i=0;
    int mid;
    int even_row=0, odd_row=0, j_1=0,j_2=0;
    
   for(int i=0;i<=(n-1);i++){
       mid=(0+n)/2;
       for(int j=0;j<=mid;j++){
           even[even_row][j_1++]=2*i;
           even[even_row][j_1++]=array_of_no[j];
           even[even_row][j_1++]=10001;
       }
       for(int p=mid+1;p<n;p++){
           odd[odd_row][j_2++]=((2*i)+1);
           odd[odd_row][j_2++]=array_of_no[p];
           odd[odd_row][j_2++]=10001;
       }


     even_row++;
     odd_row++;
     j_1=0;
     j_2=0;
   }

  for(int i=0;i<even_row;i++)
  {
      for(int j=0;even[i][j]!=10001;j++)
      printf("%d",even[i][j]);

      printf("\n");

  }

   for(int i=0;i<odd_row;i++)
  {
      for(int j=0;odd[i][j]!=10001;j++)
      printf("%d",odd[i][j]);

      printf("\n");
  }


   for(int i=0;i<even_row;i++)
  {
      for(int j=0;even[i][j]!=10001;j++){
          if(even[i][j]==spe)
          printf("%d ",even[i][0]);
      }


  }

    for(int i=0;i<odd_row;i++)
  {
      for(int j=0;odd[i][j]!=10001;j++){
          if(odd[i][j]==spe)
          printf("%d ",odd[i][0]);
      }


  }

  int count_even=0,count_odd=0;

  for(int i=0;i<even_row;i++)
  {
      for(int j=0;even[i][j]!=10001;j++){
          count_even++;}


  }

  for(int i=0;i<odd_row;i++)
  {
      for(int j=0;odd[i][j]!=10001;j++){
          count_odd++;}


  }

  printf("\n%d",count_even+count_odd);




  




  


     
     
   return 0;  
}