#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

int main(){
  int A[1000];
  int n;

  scanf("%d",&n);

  for(int i=0;i<n;i++)
  {
    scanf("%d",&A[i]);
   }
   
   int num;
   int count=1;
   int time=0;

   int flag=0,check=0;

   for(int i=0;i<n;i++)
   {
         if(A[i]!='\0')
        {
           num=A[i];
           for(int j=i+1;j<n;j++){
     
           if(num==A[j] && check==0){ 
           printf("%d %d",num,i);
           check=1;
           time=1;
           }
           if(num==A[j]){
           printf(" %d",j);
           count++;
           flag=1;
           A[j]='\0';
           }   
       }
   
     if(flag==1)
     {
     printf(" %d\n",count);
     count=1;
     flag=0;
     check=0;
    }
   
  }
   
}

if(time!=1) printf("%d",-1);
 
return 0;

}