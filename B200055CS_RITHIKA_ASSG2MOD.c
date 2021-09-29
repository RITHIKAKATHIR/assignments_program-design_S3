#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int Compare(char* str1, char* str2);
void insertion_Sort_Lex(char(*arr)[10],int n){
 int i,j;
 char str_key[10];
 for(i=1;i<n;i++){
    j=i-1;
    strcpy(str_key,arr[i]);
    while(j>=0 && (Compare(arr[j],str_key)==1)){
        strcpy(arr[j+1],arr[j]);
        j--;
    }

    strcpy(arr[j+1],str_key);
 }

}

int Compare(char* str1, char* str2){
    int flag=0, i=0;
    int str_len_1=0;
     int str_len_2=0;
    int check=0;
  while(str1[i]!='\0'&&str2[i]!='\0'){
       if(str1[i]==str2[i]){
        i++;
        continue;
       }
       if(str1[i]!=str2[i]){
            check=1;
                if(str1[i]>str2[i])
                     flag=1;
                else
                   flag=2;
            i++;
            break;
       }
 }
     
  if(check!=1){
      for(int i=0;str1[i]!='\0';i++){
              str_len_1++;
      }
      for(int i=0; str1[i]!='\0';i++){
            str_len_2++;
      }

      if(str_len_1>str_len_2)
            flag=2;
       else 
            flag= 1;
  }
  return flag;
}

int Sum_ASCII(char* str){
    int sum=0;
 for(int i=0;str[i]!='\0';i++){
  int a=str[i];
  sum=sum+a;
}
return sum;
}

int main(){
    int N;
    scanf("%d",&N);
    char P[50][10];

   for(int i=0;i<N;i++){    
     scanf("%s",&P[i]); //scan in the string to p;
   }

   /*for(int i=0;i<N;i++) 
	 printf("%s ",P[i]);

     printf("\n");*/
   
    char(*a1)[10]=P[0];
     insertion_Sort_Lex(a1,N);

    for(int i=0;i<N;i++) {
	 printf("%s ",P[i]);
     }

    printf("\n");

    int check_1=0;
    for(int i=0;i<N;i++){
    //printf("entered");
     int ez;
      ez=Sum_ASCII(P[i]);
      //printf("%d ",ez);
      
      if(ez%N==0){
        check_1=1;
       printf("%d ",i);
      }
    }

    if(check_1!=1)
    printf("%d",-1);



 return 0;

}