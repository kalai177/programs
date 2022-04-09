#include<iostream>
struct bst
{
  int value;
  bst *right, *left;
};
bst  *insert(bst *root, int value); 
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
    insert(root,value);
 }
std::cout<<"the inorder traversal:";
inorder(root);
std::cout<<endl;
std::cout<<"the preorder traversal:";
preorder(root);
std::cout<<endl;
std::cout<<"the postorder traversal:";
postorder(root);
std::cout<<endl;
std::cout<<"the level order traversal:";
levelorder(root);


 if(search(root,8)==true) std::cout<<"elemnet is present";
 }
 
void insert(bst *root, int value)
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
   }
   
   bst *node(int value)
   {
    bst *new_node=new bst;
    new_node->value=value;
    new_node->right=NULL;
    new_node->left=NULL;
    return new_node;
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
    queue<bst *>q;
    q.push(root);
    while(!q.empty())
    {
      bst *first=q.front();
      std::cout<<q.front()<<" ";
      q.pop();
      if(first->left!=NULL)
      q.push(first->left);
      if(first->right!=NULL)
      q.push(first->right);
    }
  }     
