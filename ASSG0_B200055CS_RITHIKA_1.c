#include<stdio.h>
#include<math.h>

void palindrome_func(int num){
int i=0, n1=0, rem=0;
n1=num;
for(;n1!=0;)
{
     
    
    rem=n1%10;
    i=(i*10)+rem;
    n1=n1/10;
}

if(i==num)
printf("YES");
else
printf("NO");

}

int main()
{ 
 int n;
 
 
 scanf("%d",&n);

 palindrome_func(n);
 
 return 0;
}