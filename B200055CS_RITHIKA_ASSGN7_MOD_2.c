#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node_bst{
    int key;
    struct node_bst* leftchild;
    struct node_bst* rightchild;
    struct node_bst* parent;
};
struct tree{
     struct node_bst* root;
};

struct node_bst* create_node(int k){
    struct node_bst* newnode;
    newnode=(struct node_bst*)malloc(sizeof(struct node_bst));
    if(newnode==NULL)
    exit(0);

    newnode->key=k;
    newnode->leftchild= NULL;
    newnode->rightchild=NULL;
    newnode->parent=NULL;

   return newnode;
}
 void insert_func(struct node_bst* newnode,struct tree* tree){
    struct node_bst* y;
    struct node_bst* x;
    y=(struct node_bst*)malloc(sizeof(struct node_bst));
    x=(struct node_bst*)malloc(sizeof(struct node_bst));
    y=NULL;
    x=tree->root;
    while(x!=NULL){
        y=x;
        if(newnode->key<x->key)
            x=x->leftchild;
        else x=x->rightchild;
    }
    newnode->parent=y;
    if(y==NULL) tree->root=newnode;
    else if (newnode->key<y->key) y->leftchild=newnode;
    else y->rightchild=newnode;
    
}

struct node_bst* maximum(struct node_bst* node_test){
  struct node_bst* max;
  max=(struct node_bst*)malloc(sizeof(struct node_bst));
  max=node_test;
  while(max->rightchild!=NULL)
    max=max->rightchild;

 return max;
}

void transplant(struct tree* tree,struct node_bst* u,struct node_bst* v){
    struct node_bst* temp;
    temp=(struct node_bst*)malloc(sizeof(struct node_bst));
    temp=u->parent;
    if(temp==NULL) tree->root=v;
    else if(u==temp->leftchild) temp->leftchild=v;
    else temp->rightchild=v;
        
     if(v!=NULL) v->parent=temp;
}

struct node_bst* tree_min(struct node_bst* node){
    struct node_bst* y;
     y=(struct node_bst*)malloc(sizeof(struct node_bst));
      y=node;
    while(y->leftchild!=NULL)
       y=y->leftchild;
   
    return y;
}
void delete(struct tree* tree,struct node_bst* node){
   /* if(node!=NULL)
    printf("%d\n",node->key);
    else printf("-1\n");*/
    if(node!=NULL){
   struct node_bst* y;
    y=(struct node_bst*)malloc(sizeof(struct node_bst));
    if(node->leftchild==NULL) transplant(tree,node,node->rightchild);
    else if(node->rightchild==NULL) transplant(tree,node,node->leftchild); 
    else{ y=tree_min(node->rightchild); 

    if(y->parent!=node){
           transplant(tree,y,y->rightchild);
           y->rightchild=node->rightchild;
           y->rightchild->parent=y;
    }
    transplant(tree,node,y);
    y->leftchild=node->leftchild;
    y->leftchild->parent=y;
    }
    }
}
struct tree* combine1(struct tree* tree_1, int k, struct tree* tree_2){
     struct node_bst* newnode;
     newnode=(struct node_bst*)malloc(sizeof(struct node_bst));
     struct tree* tree_node;
     tree_node=(struct tree*)malloc(sizeof(struct tree));
     if(k!=-9999 && k!=-8888 && k!=-7777){
     newnode=create_node(k);
     newnode->leftchild=tree_1->root;
     newnode->rightchild=tree_2->root;
     tree_node->root=newnode;
     tree_1->root=NULL;
     tree_2->root=NULL;
     
     }
     else if(k==-9999){
         newnode->key=-9999;
         newnode->leftchild=NULL;
         newnode->rightchild=NULL;
         newnode->parent=NULL;
         tree_node->root=newnode;
         tree_1->root=NULL;
         tree_2->root=NULL;
         
     }
     else if(k==-8888){
         newnode->key=-9999;
         newnode->leftchild=tree_1->root;
         newnode->rightchild=NULL;
          newnode->parent=NULL;
         tree_node->root=newnode;
         tree_1->root=NULL;
         tree_2->root=NULL;
     }
     else if(k==-7777){
         newnode->key=-9999;
         newnode->leftchild=NULL;
         newnode->rightchild=tree_2->root;
          newnode->parent=NULL;
         tree_node->root=newnode;
         tree_1->root=NULL;
         tree_2->root=NULL;
     }

     return tree_node;
}


struct tree* combine2(struct tree* t1, struct tree* t2){
    struct node_bst* newnode;
    int hh=0;
    newnode=(struct node_bst*)malloc(sizeof(struct node_bst));
    if(t1->root!=NULL && t2->root!=NULL){
    newnode=maximum(t1->root);
    delete(t1,newnode);
    }
    else hh=-9;
    struct tree* tree_to;
    tree_to=(struct tree*)malloc(sizeof(struct tree));
    if(hh!=-9){
    tree_to=combine1(t1,newnode->key,t2);
    }
    else{
        if(t2->root==NULL && t1->root==NULL){
            tree_to=combine1(t1,-9999,t2);
        }
        else if(t2->root==NULL && t1->root!=NULL){
            
             tree_to=combine1(t1,-8888,t2);
        }
        else if(t1->root==NULL && t2->root!=NULL){
            
             tree_to=combine1(t1,-7777,t2);
        }
    }
    t1->root=NULL;
    t2->root=NULL;
    return tree_to;
}

void inorder(struct node_bst* node){
   if(node!=NULL)
   {printf("hello mf");
    inorder(node->leftchild);
    if(node->key!=-9999) printf("%d ",node->key);
    inorder(node->rightchild);
   }
 
}

int main(){
    char array_t1[10000];
    char array_t2[10000];

    
    fgets(array_t1,10000,stdin);
    fgets(array_t2,10000,stdin);
    //printf("%s",array_t1);
    //printf("%s",array_t2);
   int array_11[1000];
   int array_12[1000];
   int l_t1=0;
   int k_t2=0;
   int dino[1000];
   int digit=0;
   int lop=0;
   int check=9;
   int ko_no=0;
   int digit_1=0;
   //printf("no seggu");
   
   for(int i=0;array_t1[i]!='\0';i++)
   {   check=9;
       if(array_t1[i]==' ') continue;
       else if(array_t1[i]>=48 && array_t1[i]<=57)
       {  lop=i;
           while(array_t1[lop+1]>=48 && array_t1[lop+1]<=57)
           {
             dino[digit]=array_t1[lop]-48;
             digit++;
             lop++;
             check=-1;
           }
           dino[digit]=array_t1[lop]-48;
          /* if(check==-1)
           {
             for(int ii=0;ii<=digit;ii++) 
              printf("%d ",dino[ii]);
           printf("this is dino\n");
           }
           printf("digit: %d",digit);*/
           if(check==-1)
           {
              digit_1=digit;
              for(int w=0;w<=digit;w++)
              {
                  ko_no=ko_no+(dino[w]*pow(10,digit_1));
                  digit_1--;
              }
            // printf("kono: %d  koo",ko_no);
              array_11[l_t1++]=ko_no;
              i=lop;
              digit=0;
              lop=0;
              ko_no=0;
           }
          else array_11[l_t1++]=array_t1[i]-48;

       }
       check=9;
       digit=0;
       lop=0;
       ko_no=0;
       digit_1=0;
   }
   int null_chk1=0;
   int null_chk2=0;

   if(l_t1==0){
       null_chk1=1;
   }

    /*for(int p=0;p<l_t1;p++)
    printf("%d ",array_11[p]);*/
   
   
    check=9;
    digit=0;
    lop=0;
    ko_no=0;
    digit_1=0;
    lop=0;

      for(int i=0;array_t2[i]!='\0';i++)
   {   check=9;
       if(array_t2[i]==' ') continue;
       else if(array_t2[i]>=48 && array_t2[i]<=57)
       {  lop=i;
           while(array_t2[lop+1]>=48 && array_t2[lop+1]<=57)
           {
             dino[digit]=array_t2[lop]-48;
             digit++;
             lop++;
             check=-1;
           }
           dino[digit]=array_t2[lop]-48;
          /* if(check==-1)
           {
             for(int ii=0;ii<=digit;ii++) 
              printf("%d ",dino[ii]);
           printf("this is dino\n");
           }
           printf("digit: %d",digit);*/
           if(check==-1)
           {
              digit_1=digit;
              for(int w=0;w<=digit;w++)
              {
                  ko_no=ko_no+(dino[w]*pow(10,digit_1));
                  digit_1--;
              }
            // printf("kono: %d  koo",ko_no);
              array_12[k_t2++]=ko_no;
              i=lop;
              digit=0;
              lop=0;
              ko_no=0;
           }
          else array_12[k_t2++]=array_t2[i]-48;

       }
       check=9;
       digit=0;
       lop=0;
       ko_no=0;
       digit_1=0;
   }

    if(k_t2==0){
        null_chk2=1;
   }

    
    /*for(int p=0;p<k_t2;p++)
    printf("%d ",array_12[p]);*/
    
 
    struct tree* tree_1;
     tree_1=(struct tree*)malloc(sizeof(struct tree));
     struct tree* tree_2;
     tree_2=(struct tree*)malloc(sizeof(struct tree));

     tree_1->root=NULL;
     tree_2->root=NULL;
     
     
     struct node_bst* temp;
     temp=(struct node_bst*)malloc(sizeof(struct node_bst));
     
     if(null_chk1!=1){
     for(int i=0;i<l_t1;i++){
          temp=create_node(array_11[i]);
          insert_func(temp,tree_1);
     }
    }
     
     if(null_chk2!=1){
     for(int i=0;i<k_t2;i++){
          temp=create_node(array_12[i]);
          insert_func(temp,tree_2);
     }
     }
    
     

     struct tree* tree_to_print;
     tree_to_print=(struct tree*)malloc(sizeof(struct tree));
     tree_to_print=combine2(tree_1,tree_2);

     inorder(tree_to_print->root);
      return 0;

}