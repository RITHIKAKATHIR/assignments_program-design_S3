#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  int m,n;
  scanf("%d %d",&m,&n);

  int *A,*B;
  A=(int *)malloc(m*sizeof(int));
  B=(int *)malloc(n*sizeof(int));
  
  for(int i=0;i<m;i++)
   scanf("%d",&A[i]);

  for(int j=0;j<n;j++)
   scanf("%d",&B[j]);

   int* arr;
   arr=(int *)malloc((m+n)*sizeof(int));


   int count=0;

   for(int i=0;i<m;i++)
   arr[count++]=A[i];


    for(int j=0;j<n,count<(m+n);j++)
    arr[count++]=B[j];

      


   int rep;
   int check=0;
   int*arr_1;
   int arr_count=0;
  
   

   arr_1=(int*)malloc((m+n)*sizeof(int));
  

    for(int i=0;i<(m+n);i++)
    {
       if(arr[i]!='\0')
        {
           rep=arr[i];
           for(int j=i+1;j<(m+n);j++){
    
            if(arr[j]==rep && check==0){ 
             arr_1[arr_count++]=rep;
             check=1;
         
              }

            if(arr[j]==rep){
              arr_1[arr_count++]=arr[j];
              arr[j]='\0';
             }
          }

        if(check==1){
          arr[i]='\0';
        }
        
        
       }
      check=0;
    }
     
      
     
     
     for(int i=0;i<arr_count;i++)
     printf("%d ",arr_1[i]);

  

     for(int i=0;i<(m+n);i++){
        if(arr[i]!='\0' && i!=(m+n-1)){
         printf("%d ",arr[i]);
        }
        if(arr[i]!='\0' && i==(m+n-1)){
          printf("%d",arr[i]);
        }
     }

    return 0;

}

