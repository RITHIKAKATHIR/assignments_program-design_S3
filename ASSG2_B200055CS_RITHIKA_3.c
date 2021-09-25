#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){
  char str_arr[10000];
  char str_sub_arr[10000];


    
    scanf("%[^\n]", &str_arr);

  
 
    scanf("%[^\n]", &str_sub_arr);
  
  
  
 
  
  int str_len=0, str_len_1=0;
  
  for(int i=0;str_sub_arr[i]!='\0';i++){
      str_len++;
  }
 
   for(int i=0;str_arr[i]!='\0';i++){
      str_len_1++;
  }

  


  int sub=0;
  char ext_sub[10000];
  int ext_sub_sub=0;
  

  int index[10000];
  

  for(int i=0;str_arr[i]!='\0';i++)
  { 
      if(str_sub_arr[0]==str_arr[i])
      {  
         for(int j=i;j<(i+str_len);j++){
          ext_sub[ext_sub_sub++]=str_arr[j];
         }
       
         if(strcmpi(str_sub_arr,ext_sub)==0){
          index[sub]=i;
          sub++;
    
         }

      }

      for(int k=0;k<ext_sub_sub;k++){
       ext_sub[k]='0';
       ext_sub_sub=0;
      }
     
            
  } 
 
  



  char arr_to_print[100];
  int disp_num=0;
  int found=0;
  int check_1=0;

  int check=0;
  int d;

 for(int i=0;str_arr[i]!='\0';i++){
 
  for(d=0;d<sub;d++){
      if(i==index[d]){
        found=1;
        break;
      }
    }
      
      if(found!=1 && found==0){
        arr_to_print[disp_num++]=str_arr[i];
      }

      if(found==1){
         int j=d;
        if(sub>1)
        {
              
              if((j+1)<sub)
              {
                 if(index[j+1]-index[j]<str_len)
                    check=1;
              }
        }
            
        

         if((j+1)<sub && check==1)
         {
            //check_1=index[j+1]-index[j];
            i=index[j+1]-1;
          }

         if(check==0) 
         i=i+(str_len-1);
        }
    
    
    found=0;
    check=0;
 }
 

  arr_to_print[disp_num]='\0';


   printf("%s",arr_to_print);

   return 0;
}