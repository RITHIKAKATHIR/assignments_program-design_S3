#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node_colour{
  int num;
  int colour;
};
int elementofarray(int* array, int size, int to_be_searched){
   for(int i=0;i<size;i++)
   {
   if(array[i]==to_be_searched)
     return 1;
   }
  
  return 0;
}
int func_nominus(int* array,int size)
{ for(int i=0;i<size;i++)
   {
   if(array[i]==-1)
     return 1;
   }
  
  return 0;
}

int main(){
    int A[10000][2];
    int vertices;
    scanf("%d",&vertices);
    int edges;
    scanf("%d",&edges);
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<2;j++)
        scanf("%d",&A[i][j]);
    }

    
    int neighbours[1000];
   int array_size=0;
   int matrix[vertices][1000];
   int k;
    for(k=0;k<vertices;k++)  
  {
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<2;j++)
        {if(A[i][j]==k)
        {
         if(j==1)
         {
           neighbours[array_size++]=A[i][0];
           continue;
         }
         if(j==0)
         {
             neighbours[array_size++]=A[i][1];
             continue;
         }         
          
        }
      }
    } 
   neighbours[array_size++]=-1;
   for(int j=0;j<array_size;j++)
   matrix[k][j]=neighbours[j];

    array_size=0;


 }
/*printf("\nmatrix\n");
for(int i=0;i<vertices;i++)
   {
     for(int j=0;j<25;j++)
     {
       if(matrix[i][j]!=-1)
        {
          printf("%d ",matrix[i][j]);
        }
        else break;
      }
     printf("\n");
  }
  printf("\nmatrix\n");*/

  int j;
  struct node_colour node[vertices][10000];
  for(int i=0;i<vertices;i++)
   {
     for(j=0;matrix[i][j]!=-1;j++)
      node[i][j].num=matrix[i][j];

      node[i][j].num=matrix[i][j];   
  }
 /* printf("\nstruct\n");
  for(int i=0;i<vertices;i++)
   {
     for(int j=0;;j++)
     {
       if(node[i][j].num!=-1)
        {
          printf("%d ",node[i][j].num);
        }
        else break;
    
     }
     printf("\n");
   }
  printf("\nstruct\n");*/

   int* colour;
   colour=(int*)malloc(vertices*sizeof(int));

   for(int k=0;k<vertices;k++)
   colour[k]=-1;
   int p=0;
   colour[p]=0;
  
     for(int j=0;;j++)
     {
       if(node[0][j].num!=-1)
        {
          node[0][j].colour=1;
          colour[node[0][j].num]=1;
        }
        else break;
    
     }

     int main_check=-1;
     int check_2=-1;
     for(int i=1;i<vertices;i++)
     {
        if(colour[i]!=-1)
        {
         for(int j=0;node[i][j].num!=-1;j++)
         {   if(colour[i]==1){
             if(node[i][j].colour!=1 && node[i][j].num!=-1) 
             node[i][j].colour=0;

             if(colour[node[i][j].num]==1)
             {
                 main_check=i;
                 check_2=j;
                 break;
             }
             else colour[node[i][j].num]=0;
            }
             else
             {
                 if(node[i][j].num!=-1)
                 node[i][j].colour=1;
                 if(colour[node[i][j].num]==0)
                 {
                 main_check=i;
                 check_2=j;
                 break;
                 }
                else  
                 colour[node[i][j].num]=1;
             }
             
         }
       }
     }
   /* printf("\ncolour\n");
     for(int i=0;i<vertices;i++){
       printf("%d   ",colour[i]);
     }
    printf("enddd"); */

    int ll=-1; 
 while(func_nominus(colour,vertices)==1 && ll!=-2)
 {
   int arrayonemin[100];
   int j1;
   int count_oneminus=0;
   int onemin=-1;
   int oneminusele[10000];
   int u0=0;
   int l=0;
   int chk=-1;
   int po=0;
   int k12;
     for(j1=0;j1<vertices;j1++)
     {
        if(colour[j1]==-1)
        { chk=-30;
          oneminusele[count_oneminus++]=j1;
           
           while(node[j1][l].num!=-1)
           {
            arrayonemin[po]=node[j1][l].num;
            po++;  
            l++;
           }
           
           arrayonemin[po++]=-1;
        }
        l=0;
             
     }

    /* for(int luu=0;luu<count_oneminus;luu++)
       printf("%d ",oneminusele[luu]);
       printf("\n");
       for(int g=0;g<po;g++)
       printf("%d  ",arrayonemin[g]);*/
      int kop=0;


  if(chk==-30)
  {
    for(int u0=0;u0<count_oneminus;u0++)
    { 
      
        for(k12=kop;arrayonemin[k12]!=-1;k12++)
           {
             if(arrayonemin[k12]!=-1)
              {
                if(colour[arrayonemin[k12]]==0)
                  { if(colour[oneminusele[u0]]!=0)
                    colour[oneminusele[u0]]=1;
                    else{ main_check=oneminusele[u0];
                          ll=-2;
                           break;}
                   }
                  else if(colour[arrayonemin[k12]]==1) 
                  {
                    if(colour[oneminusele[u0]]!=1) 
                    colour[oneminusele[u0]]=0;
                    else {main_check=oneminusele[u0]; ll=-2;  break;}
                  }
                  
               }
              
            }
            kop=k12+1;
          }
      

    }
   
   /*printf("\ncolour\n");
     for(int i=0;i<vertices;i++){
       printf("%d   ",colour[i]);
     }
      printf("\ncolour\n");*/


   }
  

    /*printf("\ncolour\n");
     for(int i=0;i<vertices;i++){
       printf("%d   ",colour[i]);
     }
      printf("\ncolour\n");

     printf("\n%d",main_check);
     printf(" %d ",check_2);*/
      if(main_check==-1 && check_2==-1 && ll==-1){
      
     int set_u[vertices];
     int set_v[vertices];
     int i_1=0;
     int i_2=0;
      for(int i=0;i<vertices;i++){
      if(colour[i]==0)
      set_u[i_1++]=i;
      else
      set_v[i_2++]=i;
      }
      for(int u=0;u<i_1;u++)
      printf("%d ",set_u[u]);
      printf("\n");
      for(int v=0;v<i_2;v++)
      printf("%d ",set_v[v]);
    }
    else
     {
        int main_check_array[1000];
        int check_2_array[1000];
        int main_check_count=0;
        int check_2_count=0;
        int i;
    for(i=0;node[main_check][i].num!=-1;i++){
      main_check_array[main_check_count++]=node[main_check][i].num;
    }
    main_check_array[main_check_count++]=node[main_check][i].num;
     
   int h;
   h=node[main_check][check_2].num;
   int i_1;
   //printf("h: %d\n",h);
   for(i_1=0;node[h][i_1].num!=-1;i_1++){
      check_2_array[check_2_count++]=node[h][i_1].num;
     }
     check_2_array[check_2_count++]=node[h][i_1].num;
     
    int j;
    int wanted=-99;
    for(int j=0;j<check_2_count;j++)
    {
     for(int i=0;i<main_check_count;i++)
     {
      if(main_check_array[i]==check_2_array[j] && main_check_array[i]!=-1)
            {wanted=check_2_array[j];
            break;
            }
     }
   }
   if(wanted!=-99){
   printf("%d %d %d",main_check,wanted,h);
   } 
   else
   {
     int chel=-1;
     int array_ss[10000];
     int ss=0;
    //printf("no odd cycle of length 3");
     int searc;
     for(int i=0;i<edges;i++)
     {
      if(colour[A[i][0]]==colour[A[i][1]])
      {  array_ss[ss++]=A[i][0];
         array_ss[ss++]=A[i][1];
        searc=A[i][1];
         break;
       }
      }
    // printf("searc is: %d",searc);
     int hp[100000];
     int hp_1=0;
      for(int k=0;k<edges;k++)
      {
        if(A[k][1]==searc || A[k][0]==searc)
         { 
           if(A[k][0]==searc)  hp[hp_1++]=A[k][1];
           else hp[hp_1++]=A[k][0];
           if(A[k][0]==searc && A[k][1]!=h && elementofarray(array_ss,ss,A[k][1])==0)
           {
          
           array_ss[ss++]=A[k][1];
           searc=A[k][1];
           k=-1;
           }
           else if(A[k][1]==searc && A[k][0]!=h && elementofarray(array_ss,ss,A[k][0])==0)
           {
            
            array_ss[ss++]=A[k][0];  
            searc=A[k][0];
            k=-1;
           }
           else{
           if(k<edges) continue;
           else break;
           }
        }
      
      hp_1=0;
    
      }
      
     // printf("\ncycle is: ");
      for(int h=0;h<ss;h++)
      printf("%d ",array_ss[h]);

   }
}

return 0;
}