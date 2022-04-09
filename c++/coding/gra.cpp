#include<iostream>
#include<list>
#include<map>
#include<iterator>
using namespace std;
class graph
{
  public:
   map<int, bool> visited;
   map<int,std::list<int>>adj;
  void edge(int x,int y)
  {
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  void dfs(int s)
  {
      visited[s]=true;
      std::cout<< s<<" ";
      std::list<int>::iterator ir;
      for(ir=adj[s].begin();ir!=adj[s].end();ir++)
      {
          if(!visited[*ir])
          {
              dfs(*ir);
          }
      }
      
  }
};
int main()
{
  graph g;
  g.edge(0,1);
  g.edge(0,2);
  g.edge(0,3);
  g.edge(1,2);
  g.edge(1,4);
  g.edge(2,4);
  g.edge(3,4);

  std::cout<<"the depth first search is:"<<std::endl;
  g.dfs(1);
}