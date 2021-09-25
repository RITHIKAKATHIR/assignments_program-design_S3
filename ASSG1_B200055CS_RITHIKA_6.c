#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void gcd_FUNC(int,int);

int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  if(a!=0 && b!=0)
  {
  if(a>b)
  gcd_FUNC(a,b);
  else
  gcd_FUNC(b,a);
  }

  return 0;
}

void gcd_FUNC(int m, int n)
{
   if(m%n!=0)
   gcd_FUNC(n,m%n);
   else 
   printf("%d",n);
}