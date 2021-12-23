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

struct tree* combine1(struct tree* tree_1, int k, struct tree* tree_2){
     struct node_bst* newnode;
     newnode=(struct node_bst*)malloc(sizeof(struct node_bst));
     newnode=create_node(k);
     newnode->leftchild=tree_1->root;
     newnode->rightchild=tree_2->root;
     struct tree* tree_node;
     tree_node=(struct tree*)malloc(sizeof(struct tree));
     tree_node->root=newnode;
     tree_1->root=NULL;
     tree_2->root=NULL;
     return tree_node;
}
void inorder(struct node_bst* node){
   if(node!=NULL)
   {inorder(node->leftchild);
   printf("%d ",node->key);
   inorder(node->rightchild);
   }
 
}

int main(){
    int array_t1[10000];
    int array_t2[10000];
   

     struct tree* tree_1;
     tree_1=(struct tree*)malloc(sizeof(struct tree));
     struct tree* tree_2;
     tree_2=(struct tree*)malloc(sizeof(struct tree));

     tree_1->root=NULL;
     tree_2->root=NULL;
     
     struct node_bst* temp;
     temp=(struct node_bst*)malloc(sizeof(struct node_bst));
     int entered=0;
     for(int i=0;array_t1[i]!=-99999;i++){
          temp=create_node(array_t1[i]);
          insert_func(temp,tree_1);
     }
     
     for(int i=0;array_t2[i]!=-99999;i++){
          temp=create_node(array_t2[i]);
          insert_func(temp,tree_2);
     }

     int key_imp;
     scanf("%d",&key_imp);
     struct tree* tree_3;
     tree_3=(struct tree*)malloc(sizeof(struct tree));

     tree_3=combine1(tree_1,key_imp,tree_2);

     inorder(tree_3->root);


   return 0;
}