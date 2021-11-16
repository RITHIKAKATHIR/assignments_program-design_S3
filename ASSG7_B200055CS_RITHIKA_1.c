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
    if(node!=NULL)
    printf("%d\n",node->key);
    else printf("-1\n");
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
struct node_bst* search(struct node_bst* tree,int k){
   if(tree==NULL || k==tree->key)
    return tree;

    struct node_bst* temp;
    temp=(struct node_bst*)malloc(sizeof(struct node_bst));
    temp=tree;
    if(k<temp->key)
     return search(temp->leftchild,k);
    else return search(temp->rightchild,k);
}
void sucessor(struct node_bst* x)
{
 struct node_bst* y;
 y=(struct node_bst*)malloc(sizeof(struct node_bst));
 y=NULL;
 if(x->rightchild!=NULL) 
 { 
  y=tree_min(x->rightchild);
  
 }
 else{
 y=x->parent;
 while(y!=NULL && x==(y->rightchild))
  {   x=y;
      y=y->parent;
  }
 }
 if(y!=NULL)
printf("%d",y->key);
else printf("%d",-1);

printf("\n");

}

struct node_bst* maximum(struct node_bst* node_test){
  struct node_bst* max;
  max=(struct node_bst*)malloc(sizeof(struct node_bst));
  max=node_test;
  while(max->rightchild!=NULL)
    max=max->rightchild;

 return max;
}

void predeccessor(struct node_bst* tree,struct node_bst* y)
{
  struct node_bst* pre;
  pre=(struct node_bst*)malloc(sizeof(struct node_bst));
  pre=NULL;
  struct node_bst* current;
  current=(struct node_bst*)malloc(sizeof(struct node_bst));
  current=y;
  /*if(y->key<current->key) current=current->leftchild;
  if(y->key>current->key){
      pre=current;
      current=current->rightchild;
  }
  if(y->key==current->key && y->leftchild!=NULL){
      pre=maximum(current->leftchild);
  }*/
  
 if(current->leftchild!=NULL){
     pre=maximum(current->leftchild);
     }
 else{
    pre=current->parent;
    while(pre!=NULL && current==pre->leftchild){
    current=pre;
    pre=pre->parent;
   }
 }
 if(pre!=NULL)
  printf("%d",pre->key);
  else printf("%d",-1);

  printf("\n");
  
}

void inorder(struct node_bst* node){
   if(node!=NULL)
   {inorder(node->leftchild);
   printf("%d ",node->key);
   inorder(node->rightchild);
   }
 
}

void preorder(struct node_bst* node){
    if(node!=NULL){
   printf("%d ",node->key); 
   preorder(node->leftchild);
   preorder(node->rightchild);
    }
   
}

void postorder(struct node_bst* node)
{
    if(node!=NULL)
    {
   postorder(node->leftchild);
   postorder(node->rightchild);
   printf("%d ",node->key);
    }
   
}

int main()
{
    char ch;
    struct node_bst* node_bst;
    struct tree* tree_node;
    node_bst=(struct node_bst*)malloc(sizeof(struct node_bst));
    if(node_bst==NULL) exit(0);
    tree_node=(struct tree*)malloc(sizeof(struct tree));
    if(tree_node==NULL) exit(0);
    int n;
    tree_node->root=NULL;
    while (1)
	{
		scanf("%c",&ch);

		switch (ch)
		{
			case 'a':	scanf(" %d",&n);
			            node_bst=create_node(n);
                        insert_func(node_bst,tree_node);
						break;

			case 'd':	scanf(" %d",&n);
                        node_bst=search(tree_node->root,n);
                        delete(tree_node,node_bst);
                        break;

			case 's':	 scanf(" %d",&n);
                         node_bst=search(tree_node->root,n);
                         if(node_bst==NULL) printf("-1");
                         else printf("%d",1);
                         printf("\n");
                         break;

			case 'c':	scanf(" %d",&n);
                        node_bst=search(tree_node->root,n);
                        //printf("\nnode_bst:%d",node_bst->key);
                        if(node_bst==NULL) printf("-1\n");
                        else sucessor(node_bst);
						break;

			case 'r':	scanf(" %d",&n);
                        node_bst=search(tree_node->root,n);
                        if(node_bst==NULL) printf("-1\n");
                        else predeccessor(tree_node->root,node_bst);
                        break;

			case 'i': 	inorder(tree_node->root);
                        printf("\n");
                        break;

            case 'p':   preorder(tree_node->root);
                        printf("\n");
                        break;

            case 't':   postorder(tree_node->root);
                        printf("\n");
                        break;

            case 'e': 	return 1;
		}
	}

	return 0;
}







