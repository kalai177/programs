#include<iostream>
struct bst
{
  int value;
  bst *right, *left;
};

bst *insert(bst *root, int value); 
bst *node(int value);
void preorder(bst *root);
bst  *rotationll(bst *root);

int main()
{
  bst *root=NULL;
  std::cout<<"enter no of elements in a BST:";
  int n;
  std::cin>>n;

  while(n--)
  {
    int value;
    std::cout<<"enter the node value:";
    std::cin>>value;
    root=insert(root,value);
  }
    std::cout<<"the preorder traversal:";
    preorder(root);
    std::cout<<"preorder after rotation";
    preorder(root);
   return(0);  
}

bst *insert(bst *root, int value)
 {
   if(root==NULL)
    root=node(value);
   else if(value<=root->value)
   {
     root->left=insert(root->left,value);
   }
   else 
   {
   root->right=insert(root->right,value);
   }
   return root;
}

 bst *node(int value)
   {
    bst *new_node=new bst;
    new_node->value=value;
    new_node->right=NULL;
    new_node->left=NULL;
    return new_node;
    }


    void preorder(bst *root)
   {
     if(root==NULL) return;
     std::cout<<root->value;
     preorder(root->left);
     preorder(root->right);
   }

   bst *rotationll(bst *root)
   {
       bst *x;
       bst *y;
       x=root;
       y=root->left;
       x->left=y->right;
       y->right=x;
       return y;
   }