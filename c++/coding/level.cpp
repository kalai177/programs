#include<iostream>
#include<queue>
#include<bits/stdc++.h>
struct bst
{
  int value;
  bst *right, *left;
};
bst *insert(bst *root, int value); 
bst *node(int value);
void inorder(bst *root);
bool search(bst *root,int value);
void preorder(bst *root);
void postorder(bst *root);
void levelorder(bst *root);
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
std::cout<<"the inorder traversal:";
inorder(root);
std::cout<<"the preorder traversal:";
preorder(root);
std::cout<<"the postorder traversal:";
postorder(root);
std::cout<<"the levelorder traversal:";
levelorder(root);


 if(search(root,8)==true) std::cout<<"elemnet is present";
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
    
    bool search(bst *root, int value)
    {
      if(root==NULL) return false;
      else if(root->value==value) return true;
     
      else if(value<=root->value) return  search(root->left, value);
      else return  search(root->right,value);
    }
    
    void inorder(bst *root)
    {
      if(root==NULL) return ;
      
      inorder(root->left);
      std::cout<<root->value;
      inorder(root->right);
      
    }
    
   void preorder(bst *root)
   {
     if(root==NULL) return;
     std::cout<<root->value;
     preorder(root->left);
     preorder(root->right);
   }
   
   void postorder(bst *root)
   {
     if(root==NULL) return ;
     postorder(root->left);
     preorder(root->right);
     std::cout<<root->value;
   }
     
void levelorder(bst *root)
{
    if (root == NULL)  return;
    std::queue < struct bst *> q;
    q.push(root);
 
    while (q.empty() == false)
    {
        bst  *node = q.front();
        std::cout << node->value << " ";
        q.pop();
 
        
        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }


}