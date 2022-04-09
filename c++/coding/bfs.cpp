#include<iostream>
#include<vector>
#include<queue>
using namespace std;
std::vector<int>adj;
int V=5;
void edge(std::vector<int>adj[],int x,int y);
void bfs(std::vector<int>adj[],int s, int V);
int main()
{
    int V;
    std::cout<<"enter no of vertices:";
    std::cin>>V;
    std::vector<int>adj[V];
    edge(adj,0,1);
    edge(adj,0,2);
    edge(adj,0,3);
    edge(adj,1,2);
    edge(adj,1,4);
    edge(adj,2,4);
    edge(adj,3,4);
     
std::cout<<"breadth first search:";
  bfs(adj,4,V);
}

void edge(std::vector<int>adj[],int x, int y)
{
   adj[x].push_back(y);
   adj[y].push_back(x);
}

void bfs(std::vector<int>adj[],int s,int V)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    std::queue<int>box;
    visited[s]=true;
    box.push(s);
    std::vector<int>::iterator ir;
    while(!box.empty())
    {
        s=box.front();
        std::cout<<s<<" ";
        box.pop();
        for(ir=adj[s].begin();ir!= adj[s].end();ir++)
        {
            if(!visited[*ir])
            {
             visited[*ir]=true;
            box.push(*ir);
            }
        }
    }


}