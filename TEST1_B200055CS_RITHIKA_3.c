#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct student{
char reg_no [10];
int time_req;
int ad_no;
};

void read_details(struct student* s1, int n){
    for(int i=0;i<n;i++){
       // scanf("%s",reg);
        scanf("%s",(s1+i)->reg_no);
         scanf("%d",&(s1+i)->time_req);
          scanf("%d",&(s1+i)->ad_no);  
    }
}

void print_students(struct student* s1, int n){
    for(int i=0;i<n;i++){
        printf("%s ",(s1+i)->reg_no);
        printf("%d ",(s1+i)->time_req);
        printf("%d ",(s1+i)->ad_no);  
        printf("\n");
    }
}


int main(){
    struct student array[10000];
    char ch;
    int n;
    while(1){
        scanf("%c",&ch);

        switch(ch){
             case 'r': scanf("%d",&n);
                
                       read_details(array,n);
                       break;

              case 'p': print_students(array,n);
                        break;

        

             case 't': return 1;

        }
    }

    return 0;
}
