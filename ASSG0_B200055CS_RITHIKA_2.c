#include<stdio.h>
#include<stdlib.h>
int* A;
int palindrome(int num){
 int j,p=0,q=0,r=0,count=0;    

 for( j=0;j<num;j++){
  p=0;
  q=0;
  r=0;
  p=*(A+j);
  
  while(p!=0){
  q=p%10;
  r=(r*10)+q;
  p=p/10;

 }

 if(r==j[A])
 count=count+1;

}

return count;
}

int main() {
    
    int n; 
    int op;
    scanf("%d",&n);

    A=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){      
     scanf("%d",&A[i]); 
    }

    
    op=palindrome(n);

    printf("%d",op);

    return 0;

}