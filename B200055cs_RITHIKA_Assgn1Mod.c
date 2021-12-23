#include<stdio.h>
#include<math.h>
#include<string.h>

void toggle_move(char *p);
void merger_string_reverse(char*p);


int main(){
  int n;
  scanf("%d",&n);
  char arr[10][10000];
  

  for(int i=0;i<n;i++){
    scanf(" %[^\n]", &arr[i]);
  }

  /*for(int i=0;i<n;i++) {
		printf("%s",arr[i]);
    printf("\n");
	} */
  for(int i=0;i<n;i++)
  toggle_move(arr[i]);


  /*for(int i=0;i<n;i++) {
		printf("%s",arr[i]);
    printf("\n");
  }*/
  for(int i=0;i<n;i++)
   merger_string_reverse(arr[i]);

 return 0;
}


void toggle_move(char *p){

  for(int i=0;p[i]!='\0';i++){
    if(*(p+i)>=97 && *(p+i)<=122)
     *(p+i)=*(p+i)-32;

    else if(*(p+i)>=65 && *(p+i)<=90)
      *(p+i)=*(p+i)+32;
   }
}

void merger_string_reverse(char*p)
{
 for(int i=0;p[i]!='\0';i++){
    if(!(*(p+i)>=97 && *(p+i)<=122) && !(*(p+i)>=65 && *(p+i)<=90)){
         for(int j=0;j<strlen(p);j++){
           *(p+i+j)=*(p+i+j+1);
         }
    }
    
  }

  strrev(p);
  puts(p);

}