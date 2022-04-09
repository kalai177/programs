#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<queue>

using namespace std;
class graph{
    public:
    map<int,vector<int>>m;
    map<int,bool>visited;
    map<int,bool>visited_bfs;
    void addedge(int v,int u){
        m[v].push_back(u);
        m[u].push_back(v);
    }
    void print(){
       map<int,vector<int>>::iterator i;
       for( i=m.begin();i!=m.end();i++){
           int s=i->second.size();
           cout<<s<<"     ";
          for(int k=0;k<s;k++){
              cout<<i->second[k];
          }
           cout<<endl;
       }
    }
    void dfs(int s){
        visited[s]=1;
        cout<<s<<" ";
        vector<int>::iterator itr;
        for(itr=m[s].begin();itr!=m[s].end();itr++){
            if(!visited[*itr]){
                dfs(*itr);
            }
        }
    }
     
     void bfs(int s){
        queue<int>q;
        q.push(s);
        visited_bfs[s]=1;
        while(!q.empty()){
            int s=q.front();
            cout<<s<<" ";
            q.pop();
            vector<int>::iterator itr;
            for(itr=m[s].begin();itr!=m[s].end();itr++){
                if(!visited_bfs[*itr]){
                    visited_bfs[*itr]=1;
                    q.push(*itr);
                }
            }
        }
     }

}
;


int main(){
   graph g;

   g.addedge(1,2);
   g.addedge(1,3);
   g.addedge(2,3);
   g.addedge(2,4);
   g.addedge(4,3);
   g.addedge(4,5);
   g.print();
   g.bfs(1);


}