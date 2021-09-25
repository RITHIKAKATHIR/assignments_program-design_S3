#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>



void CONVERT(int, int*a);
void LEFT(int, int*b);
void RIGHT(int, int*c);

int main(){
 int arr[16];
 int n,k;

 for(int i=0;i<=15;i++){
   arr[i]=0;
 }

 scanf("%d %d",&n,&k);


 CONVERT(n,arr);
 printf("\n");
 LEFT(k,arr);
 printf("\n");
 RIGHT(k,arr);
 return 0;

}

void CONVERT(int n, int*a)
{
   
   int i,j;
    for(i=15;n!=0;i--,n=n/2)
      {
        a[i]=n%2;
  
      }

    for(j=0;j<=15;j++)
       printf("%d",a[j]);

}

void LEFT(int m, int* b){
   int arr_1[16];
   int f=m-1;
      for(int g=15;g>=(16-m),f>=0;g--){
        arr_1[g]=b[f--];
      }
     f=0;
   for(int b1=m;b1<16,f<(16-m);b1++){
      arr_1[f++]=b[b1];
   }

   for(int j=0;j<=15;j++){
     printf("%d",arr_1[j]);
   }
}

void RIGHT(int s, int*c){
     int arr_2[16];
     int f_1=s-1;

      for(int i=15;i>=(16-s),f_1>=0;i--,f_1--){
        arr_2[f_1]=c[i];
      }
      f_1=s;
     
    for(int d=0;d<(16-s),f_1<=15;d++){
      arr_2[f_1++]=c[d];
    }  
   
    for(int q=0;q<16;q++){
      printf("%d",*(arr_2+q));
    }
}