#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

int main(){
  char str[100000];
  

 fgets(str,100000,stdin);
  

   for(int i=0;str[i]!='\0';i++){
    if(str[i]>=97 && str[i]<=122)
     str[i]=str[i]-32;

    else if(str[i]>=65 && str[i]<=90)
      str[i]=str[i]+32;
   }
   
   char *ptr;
   ptr=str;

  while(*ptr!='\0'){
    printf("%c",*ptr);
    ptr++;
  }


  return 0;
}