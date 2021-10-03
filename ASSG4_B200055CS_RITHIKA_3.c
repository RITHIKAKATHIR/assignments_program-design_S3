#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
 struct amoeba{
    char amoeba_name[25];
    int amoeba_size;
  };

 void combine(struct amoeba* array, int n);
  
  int Compare(char* str1, char* str2){
    int flag=0, i=0;
    //int str_len_1=0;
     //int str_len_2=0;
    int check=0;

  while(str1[i]!='\0'&&str2[i]!='\0'){
       if(str1[i]==str2[i]){
        i++;
        continue;
       }
       if(str1[i]!=str2[i]){
            check=1;
                if(str1[i]>str2[i])
                     flag=1;   //return 1 if A[l].amoeba_name is lexographically before A[i]
                else 
                   flag=2;  //otherwise 2
            i++;
            break;
       }
 }
     
 /* if(check!=1){
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
  }*/
  return flag;
}

 void max_heapify(struct amoeba* A,int i,int n){
 int l,r;
 int lex_check=0;
 int lex_check1=0;
 int smallest=i;
 l=(2*i)+1;
 r=(2*i)+2;
 int f=0;
 if(l<=n && A[l].amoeba_size>A[i].amoeba_size) 
   {f=1;
   smallest=l;

   }
 if(r<=n && A[r].amoeba_size>A[smallest].amoeba_size)  
   {f=1;
    smallest=r;
   }
   
  if(f!=1){
   if(l<=n && A[l].amoeba_size==A[i].amoeba_size)
   {  
       lex_check=Compare(A[l].amoeba_name, A[i].amoeba_name);
       if(lex_check==1){
           smallest=l;
       }
   }
   if(r<=n && A[r].amoeba_size==A[smallest].amoeba_size)
   {
      lex_check1=Compare(A[r].amoeba_name, A[smallest].amoeba_name);
      if(lex_check1==1){
          smallest=1;
      }
   }
   } 

  struct amoeba temp;

  if(smallest!=i){
    temp=A[i];
    A[i]=A[smallest];
    A[smallest]=temp;
    max_heapify(A,smallest,n);
    }

}
 
 void build_heap(struct amoeba*A,int n)
 {
  for(int i=(n/2);i>=0;i--)
  {
      max_heapify(A,i,n);
  }
 }
 
 void heap_sort(struct amoeba*A, int n){
     int n1=n;
     int heapsize=n;
     build_heap(A,n);
       /*printf("buildheap");
       for(int k=0;k<=n;k++){
        printf("%s ", A[k].amoeba_name);
        printf("%d\n",A[k].amoeba_size);
       }*/
     struct amoeba temp;
     int j;
     for(j=n1;j>=1;j--)
     {//printf("heap");
      temp=A[j];
      A[j]=A[0];
      A[0]=temp;
      heapsize--;
      max_heapify(A,0,heapsize);
    }

      /* for(int k=0;k<=n;k++){
        printf("%s ", A[k].amoeba_name);
        printf("%d\n",A[k].amoeba_size);
    }*/
 }

 void insert(struct amoeba* array,int count){
    heap_sort(array,count);
    
 }

 void read(struct amoeba* array,int count){
     for(int i=0;i<=count;i++)
     {
          scanf("%s",(array+i)->amoeba_name);
          scanf("%d",&(array+i)->amoeba_size);
          //printf("entered");
     }

    insert(array,count);
 }

 /*const char* name_func(char A[25], char B[25])
 {
  printf("name_func");
  char A_1[25];
  int i=0;
  while(A[i]!=' ' && A[i]!='\0'){
   A_1[i]=A[i];
   i++;
  }
  A_1[i++]=' ';
  int j=0;
  while(B[j]!=' ' && B[j]!='\0'){
      A_1[i]=B[j];
      i++;
      j++;
  }
   printf(" in name_func %s ",A_1);
  return A_1;
 }*/

 void combine(struct amoeba* array, int n)
 {  
    //struct amoeba* array_1;
    int n_1=n;
    /*array_1=(struct amoeba*)malloc((n+1)*sizeof(struct amoeba));
    for(int i=0;i<=n;i++){
        strcpy((array_1+i)->amoeba_name,(array+i)->amoeba_name);
        (array+i)->amoeba_size=(array+i)->amoeba_size;
    }*/

    int j=0;        
     //char* A1;
     //char name_com[25];
     
     for(j=0;j<n;j++)
     {  
        //A1=name_func(array[0].amoeba_name,array[1].amoeba_name);
        char A_1[25];
        int i=0;
         while(array[0].amoeba_name[i]!=' ' && array[0].amoeba_name[i]!='\0')
         {
         A_1[i]=array[0].amoeba_name[i];
         i++;
         }
         A_1[i++]=' ';
         int j=0;
         while(array[1].amoeba_name[j]!=' ' && array[1].amoeba_name[j]!='\0')
         {
          A_1[i]=array[1].amoeba_name[j];
          i++;
          j++;
         }

         //printf(" in name_func %s ",A_1);
         /*for(int i=0;*(A1+i)!='\0';i++)
         {  printf("eneterrrr");
          name_com[i]=*(A1+i);
         }*/
         //printf(" name_com is %s ",name_com);
      
         strcpy(array[0].amoeba_name,A_1);
      
         array[0].amoeba_size=array[0].amoeba_size+array[1].amoeba_size;

         for(int i=1;i<n_1;i++)
        {   
           strcpy(array[i].amoeba_name,array[i+1].amoeba_name);
           array[i].amoeba_size=array[i+1].amoeba_size;
        }

       n_1=n_1-1;

       int disp=0;
       printf("\n");
       printf("%s",array[disp].amoeba_name);
       printf(" %d",array[disp].amoeba_size);

       insert(array,n_1);
     }

     if(j==n)
     { printf("\n");
      for(int h=0;array[0].amoeba_name[h]!='\0' && array[0].amoeba_name[h]!=' ';h++)
      {
        printf("%c",array[0].amoeba_name[h]);
      }
      printf(" %d",array[0].amoeba_size);
     }
 }

 int main()
 {
	int n;
    scanf("%d",&n);
    struct amoeba* Array_of_amoeba;
    Array_of_amoeba = (struct amoeba*)malloc(n * sizeof(struct amoeba));
	  read(Array_of_amoeba,n-1);
    combine(Array_of_amoeba,n-1);
    return 0;
 }

