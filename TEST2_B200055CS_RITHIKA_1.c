#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct slip{
    char letter;
    int number;
};

void min_heapify(struct slip* arraystruct,int i,int n){

 int l,r;
 int smallest=i;
 l=(2*i)+1;
 r=(2*i)+2;
 if(l<=n && arraystruct[l].number<arraystruct[i].number)
   {//printf("ggg");
   smallest=l;
   }
 if(r<=n && arraystruct[r].number<arraystruct[smallest].number)
   {//printf("knknskn");
    smallest=r;
   }
 
  struct slip temp;
  if(smallest!=i){
    temp=arraystruct[i];
    arraystruct[i]=arraystruct[smallest];
    arraystruct[smallest]=temp;
    min_heapify(arraystruct,smallest,n);
    }

    
}

void heap_insert(struct slip* arraystruct,int n){
    
    for(int i=(n-1)/2;i>=0;i--){
        min_heapify(arraystruct,i,n);
    }
    for(int i=0;i<=n;i++)
    {
        printf("%c ",(arraystruct+i)->letter);
    }
}



void insert(struct slip* arraystruct, struct slip* slip, int i){
    //printf("enteredd");
 (arraystruct+i)->letter=slip->letter;
 (arraystruct+i)->number=slip->number;
  heap_insert(arraystruct,i);
}

/*void dequeue(struct slip* arraystruct, char* location, int i,int j){
    location[j++]=(arraystruct+i)->letter;
     for(int i=0;i<=i;i++)
    {   
        printf("%c ",(arraystruct+i)->letter);
    }
}*/



int main(){
    char ch;
    struct slip* slip;
    slip=(struct slip*)malloc(sizeof(struct slip));
    struct slip* arraystruct;
    arraystruct=(struct slip*)malloc(10000*sizeof(struct slip));
    char location[1000000];
    char l;
    int n;
    int i=0;
    int j;
    while(1){
        scanf("%c ",&ch);

        switch(ch){
            case 's': scanf("%c %d",&l,&n);
                      slip->letter=l;
                      slip->number=n;
                      if(n!=0){
                          //printf("%d",i);
                          //printf("heyy");
                          insert(arraystruct,slip,i); 
                          i++;
                      } 
                      break;

            /*case 'r':   dequeue(arraystruct,location,i,j);
                        break;*/

            case 't':
                        return 1;
                                     
        }
    }

    return 0;
}