#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct bst{
    int data;
    struct bst* left;
    struct bst* right;
    struct bst* parent;
};
struct bst* createNode(int data){
    struct bst* tocreate_node;
    tocreate_node=(struct bst*)malloc(sizeof(struct bst));
    tocreate_node->data=data;
    tocreate_node->left=NULL;
    tocreate_node->right=NULL;
    tocreate_node->parent=NULL;
    return tocreate_node;
}
void insertnode(struct bst** root,int value)
{
    if(*root==NULL)
    {
        *root=createNode(value);
        return;
    }
    struct bst* temp;
    temp=(struct bst*)malloc(sizeof(struct bst));
    temp=*root;
    while(temp!=NULL){
        if(value<temp->data){
            if(temp->left==NULL){
                temp->left=createNode(value);
                temp->left->parent=temp;
                return;
            }
            temp=temp->left;
        }
        else{
            if(temp->right==NULL){
                temp->right=createNode(value);
                temp->right->parent=temp;
                return;
            }
            temp=temp->right;
        }
    }
}
struct bst* search(struct bst** root,int value){
    if(*root==NULL){
        return NULL;
    }
    struct bst* temp=*root;
    while(temp!=NULL){
        if(value<temp->data){
            temp=temp->left;
        }
        else if(value>temp->data){
            temp=temp->right;
        }
        else{
            return temp;
        }
    }
    return NULL;
}
void transplant(struct bst** root,struct bst* u,struct bst* v){
    if(u->parent==NULL){
            *root=v;
    }
    else if(u==u->parent->left){
          u->parent->left=v;
    }
    else{
        u->parent->right=v;
    }
    if(v!=NULL){
        v->parent=u->parent;
    }
}
struct bst* minimum(struct bst* root){
    struct bst* atnode=(struct bst*)malloc(sizeof(struct bst));
    atnode=root;
    while(atnode->left!=NULL){
        atnode=atnode->left;
    }
    return atnode;
}
struct bst* maximum(struct bst* root){
    struct bst* atnode=(struct bst*)malloc(sizeof(struct bst));
    atnode=root;
    while(atnode->right!=NULL){
        atnode=atnode->right;
    }
    return atnode;
}
void treeDelete(struct bst** root,int value){
    struct bst* current__Node=(struct bst*)malloc(sizeof(struct bst));
    current__Node=search(root,value);
    if(current__Node==NULL){
        printf("-1\n");
    } 
    else printf("%d\n",current__Node->data);
 if(current__Node!=NULL){
    struct bst* y=(struct bst*)malloc(sizeof(struct bst));
    struct bst* y1=(struct bst*)malloc(sizeof(struct bst));
    y1=*root;
   if(y1->left==NULL){
    transplant(root,current__Node,current__Node->right);
   }
 else if(current__Node->right==NULL){
     transplant(root,current__Node,current__Node->left);
 }
 else{
     y=minimum(current__Node->right);
     if(y->parent!=current__Node){
         transplant(root,y,y->right);
         y->right=current__Node->right;
         y->right->parent=y;
     }
     transplant(root,current__Node,y);
     y->left=current__Node->left;
     y->left->parent=y;
  }
}
}
struct bst* successor_func(struct bst** root,int x)
{   
    struct bst* successorNode=(struct bst*)malloc(sizeof(struct bst));
    successorNode=search(root,x);
    struct bst* y=(struct bst*)malloc(sizeof(struct bst));
    y=NULL;
    if(successorNode->right!=NULL){
        return minimum(successorNode->right);
    
    }
    y=successorNode->parent;
    while(y!=NULL && successorNode==y->right){
        successorNode=y;
        y=y->parent;
    }
 
    return y;
}
struct bst* predecessor(struct bst** root, int y){
    struct bst* predecessorNode=(struct bst*)malloc(sizeof(struct bst));
    predecessorNode=search(root,y);
    struct bst* x=(struct bst*)malloc(sizeof(struct bst));
    if(predecessorNode->left!=NULL){
        return maximum(predecessorNode->left);
        
    }
    x=predecessorNode->parent;
    while(x!=NULL && predecessorNode==x->left){
        predecessorNode=x;
        x=x->parent;
    }
    return x;
}
void preorder(struct bst** root){
    if(*root==NULL){
        return;
    }
    printf("%d ",(*root)->data);
    preorder(&(*root)->left);
    preorder(&(*root)->right);
}
void inorder(struct bst** root){
    if(*root==NULL){
        return;
    }
    inorder(&(*root)->left);
    printf("%d ",(*root)->data);
    inorder(&(*root)->right);
}
void postorder(struct bst** root){
    if(*root==NULL){
        return;
    }
    postorder(&(*root)->left);
    postorder(&(*root)->right);
    printf("%d ",(*root)->data);
}
int main(){
    struct bst** root;
    root=(struct bst**)malloc(sizeof(struct bst*));
    *root=NULL;
    char ch;
    int value;
    int value1;
    int search1;
    int successor1;
    int prede1;
    //struct bst* disp=(struct bst*)malloc(sizeof(struct bst));
    struct bst* successor_23=(struct bst*)malloc(sizeof(struct bst));
    struct bst* before_23=(struct bst*)malloc(sizeof(struct bst));
    struct bst* found=(struct bst*)malloc(sizeof(struct bst));
    while(1){
        scanf("%c",&ch);
        switch (ch)
        {
        case 'a': scanf(" %d",&value);
                  insertnode(root,value);
                  break;
        case 'i': inorder(root);
                  printf("\n");
                  break;
        case 'p': preorder(root);
                  printf("\n");
                  break;
        case 't': postorder(root);
                  printf("\n");
                  break;
        case 'd': scanf(" %d",&value1);
                  treeDelete(root,value1);
                  break;
        case 's': scanf(" %d",&search1);
                  found=search(root,search1);
                  if(found==NULL){
                      printf("-1\n");
                  }
                  else{
                      printf("1\n");
                  }
                  break;
        case 'c': scanf(" %d",&successor1);
                  successor_23=successor_func(root,successor1);
                  if(successor_23!=NULL) printf("%d\n",successor_23->data);
                  else printf("-1\n");
                  break;
        case 'r': scanf(" %d",&prede1);
                  before_23=predecessor(root,prede1);
                  if(before_23!=NULL) printf("%d\n",before_23->data);
                  else printf("-1\n");
                  break;
        case 'e': return 1;
        
       
        }
    }

}