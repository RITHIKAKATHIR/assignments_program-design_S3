#include<stdio.h>
#include<math.h>
void oct_func(int);

int check_octal(int j){
    int flag=0;
    
    
    while(j!=0){
         if(j%10>=8)
         {flag=1;
         break;
         }
         else
         j=j/10;
     }
    
 
 return flag;
}

void main(){

int n;
scanf("%d",&n);
int num;
num=check_octal(n);
if(num==0)
oct_func(n);
}

void oct_func(int p){
int rem=0;
int count=-1;
int dec=0;
    while(p!=0){
        count=count+1;
        rem=p%10;
        dec=dec+(rem*pow(8,count));
        p=p/10;
        }

 printf("%d",dec);

}