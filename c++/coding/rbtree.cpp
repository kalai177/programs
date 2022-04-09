#include<iostream>
#include<queue>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct bst
{
    int value;
    char colour;
    bst *left, *right,*parent;
};
void levelorder(bst *root);
bst *noderoot(int value);
bst *node(int value);
bst *insert(bst *root, int value,bst *head);
bst *leftrotation(bst *root);
bst *rightrotation(bst *root);
bst *fixviolation(bst *root,int value,bst *head);
int main()
{
    bst *root;
    bst *head;
    root=head;
    std::cout<<"enter no of nodes in this rb tree";
    int n,i;
    std::cin>>n;
    i=n;
    while(n--)
    {
        if(i==n)
        {
          std::cout<<"enter the node value";
          int value;
          std::cin>>value;  
          head=noderoot(value);
        }
       else{
       std::cout<<"enter the node value";
       int value;
       std::cin>>value;
       root=insert(root,value,head);
       }
    }
    std::cout<<"the level order traversal is:";
    levelorder(root);
}

// level order

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

bst *node(int value)
{
    bst *new_node=new bst;
    new_node->value=value;
    new_node->left=new_node->right=new_node->parent=NULL;
    new_node->colour='R';
    return new_node;
}

bst *noderoot(int value)
{
     bst *new_node=new bst;
     new_node->value=value;
     new_node->left=new_node->right=new_node->parent=NULL;
     new_node->colour='B';
     return new_node;
}

bst *insert(bst *root, int value,bst * head)
{
    
    if(root==NULL)
    return(node(value));
    
    if(value<root->value)
    {
    root->left=insert(root->left,value,head);
    root->left->parent=root;

    std::cout<<root->value<<std::endl;
    }
    else if(value>root->value)
    {
        root->right=insert(root->right, value,head);
        root->right->parent=root;
        std::cout<<root->value<<std::endl;
    }
    else 
    return root;
    if(root!=head)
    fixviolation(root,value,head);}
    root->colour='B';
    return root;


}

bst *fixviolation(bst *root,int value,bst *head)
{
    bst *uncle,*grandp;
     grandp=root->parent;
if(root->colour=='R')
{
    if(root==root->parent->left)
    {
      uncle=root->parent->right;
       if(uncle != NULL && uncle->colour=='R')
       {
               root->colour='B';
               uncle->colour='B';
               grandp->colour='R';
           
       }
       else
       {
          if(value<root->value)
          {
              //ll rotation:
              std::cout<<"ll so doing left rotation:";
              root=rightrotation(root);
            
          } 

          else
          {
              //lr 
              std::cout<<"lr so doing right for left side:";
              root->right=leftrotation(root->right);
              root=rightrotation(root);
              }
            
          }
       }
    }
    
    if(root==root->parent->right)
    {
      uncle=root->parent->left;
       if(uncle != NULL && uncle->colour=='R')
       {
               root->colour='B';
               uncle->colour='B';
               grandp->colour='R';
           
       }
       else
       {
          if(value>root->value)
          {
              //rr rotation:
              std::cout<<"rr so doing right rotation:";
              root=leftrotation(root);
              

          } 

          else
          {
              //rl 
              std::cout<<"rlso doing left for right side:";
             
              root->left=rightrotation(root->left);
              std::cout<<"doing left rotation:";
              root=leftrotation(root);
             }
          }
       }
    }
}
return root;
}

bst *leftrotation(bst *root)
{
    bst *x=root;
    bst *y=root->parent;
    x->left=y;
    y->right=x->left;
    std::swap(x->colour,y->colour);
    return x;
}

bst *rightrotation(bst *root)
{
    bst *x=root;
    bst *y=root->parent;
    x->right=y;
    y->left=x->right;
    std:swap(x->colour,y->colour);
    return x;

}