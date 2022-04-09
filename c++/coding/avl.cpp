#include<iostream>
#include<queue>
struct bst
{
     int value, height;
     bst * left, *right;
};
struct node
{
    int data;
    struct Node *left, *right;
};
bst *insert(bst *root, int value);
bst *node(int value);
int height(bst *root);
int balancefind(bst *root);
int max(int x, int y);
bst *rightrotation(bst *x);
bst *leftrotation(bst *x);
void preorder(bst *root);
void levelorder(bst *root);
int main()
{
    bst *root = NULL;
    std::cout<<"no of nodes in a bst:";
    int n;
    std::cin>>n;
    while(n--)
    {   
        std::cout<<"enter the node value:";
        int value;
        std::cin>>value;
        root=insert(root,value);
        
    }
        std::cout<<"preorder traverse:";
        preorder(root);
        std::cout<<endl;
        std::cout<<"the levelorder traversal:";
        levelorder(root);

        return 0;
}

int height(bst *root)
{
    if(root==NULL) return 0;
    return root->height;
}
int balancefind(bst *root)
{ 
    if(root==NULL) return 0;
    return height(root->left) - height(root->right);
}
int max(int x,int y)
{
    return (x>y)? x:y;
}

bst *node(int value)
{
    bst *new_node=new bst;
    new_node->value=value;
    new_node->left=new_node->right=NULL;
    new_node->height=1;
    return new_node;
}

// inserting  function
bst *insert(bst *root, int value)
{
    if(root == NULL) 
       return node(value); 


    if(value<root->value){
       root->left=insert(root->left,value);}
    else if(value>root->value){
       root->right=insert(root->right, value);}
    else 
      return root;
     
    root->height=1+max(height(root->left), height(root->right));
    std::cout<<root->height<<"the height:"<<std::endl;
    int balance=balancefind(root);
    std::cout<<"the bal:"<<balance<<std::endl;
        //ll
    if(balance > 1 && value <root->left->value)
      {
        std::cout<<"performing ll so r rotation:";
      return rightrotation(root);}
    //rr
    if(balance <-1 && value>root ->right->value){
        std::cout<<"rr so l rotation:";
      return leftrotation(root);}
    //lr
    if(balance>1 && value>root->left->value)
       {
           std::cout<<"lr :";
        root->left = leftrotation(root->left);
        return rightrotation(root); 
       }
    //rl
    if(balance<-1 && value<root->right->value)
      {
          std::cout<<"rl:";
          root->right= rightrotation(root->right);
          return leftrotation(root);
      }

    return root;
}


//left left
bst *rightrotation(bst *x)
{
    bst *y=x->left;
    bst *z=y->right;

    y->right=x;
    x->left=z;

    x->height=1+max(height(x->left), height(x->right));
    y->height=1+max(height(y->left),height(y->right));

    return y;
}

//right right
bst *leftrotation(bst *x)
{
    bst *y=x->right;
    bst *z=y->left;

    y->left=x;
    x->right=z;

    x->height=1+max(height(x->left), height(x->right));
    y->height=1+max(height(y->left),height(y->right));

    return y;
}

void preorder(bst *root)
{
    if(root==NULL) return;
    std::cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
}

void levelorder(bst *root)
  {
    std::queue < node * > q;
    q.push(root);
    while(!q.empty())
    {
      node  *first=q.front();
      std::cout<<q.front()<<" ";
      q.pop();
      if(first->left!=NULL)
      q.push(first->left);
      if(first->right!=NULL)
      q.push(first->right);
    }
  }     
