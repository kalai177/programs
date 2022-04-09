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
    std::cout<<root->value;
 }

std::cout<<"the preorder traversal:";
std::cout<<root->value<<std::endl;
root=rotationll(root);
std::cout<<root->value<<std::endl;
preorder(root);
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
      struct  bst *x;
      struct bst *y;
       x=root;
       if(x->left!=NULL)
       {
         y=x->left;
        if(y->right != NULL)
        {
         x->left=y->right;   
        }
        y->right=x;
        return y;
       }
       else
       std::cout<<"cant do by ll";
       return x;
   }
   
   