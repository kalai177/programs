#include<iostream>
#include<string>
const int alpha_size=26;
struct trie
{
    trie *child[alpha_size];
    bool tail;
};
trie *node(void);
void insert(trie *root, std::string key);
bool search(trie *root, std::string key);
int main()
{  
    int n;
    std::cout<<"enter no of keys:";
    std::cin>>n;
   std::string key[n];
   for(int i=0;i<n;i++)
   {
       std::cout<<"enter the key:";
       std::cin>>key[i];
   }
   trie *root=node();

    for(int j=0;j<n;j++)
    {
        std::cout<<key[j]<<std::endl;
        insert(root,key[j]);
    }
    search(root, "the")? std::cout << "Yes\n" :
						std::cout << "No\n";
	search(root, "thew")? std::cout << "Yes\n" :
						std::cout << "No\n";
   std::cout<<"done!!";
}


trie *node()
{
  trie *new_node=new trie;
  new_node->tail=false;
  for(int i=0;i<alpha_size;i++)
  {
      new_node->child[i]=NULL;
  }
  return new_node;

}
void insert(trie *root, std::string key)
{
    trie *head= root;
    for(int i=0;i<key.length();i++)
    {
        int length=key[i] - 97;
        if(!head->child[length])
        {
            head->child[length]=node();
            head=head->child[length];
        }
        
    }
    head->tail=true;
}

bool search(trie *root, std::string key)
{
    trie * head=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-97;
        if(!head->child[index])
          return false;

        head=head->child[index];
    }
    return(head->tail);
}