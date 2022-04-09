#include<iostream>
#include<map>
#include<vector>
#include<iterator>
using namespace std;
class graph{
    public:
    map<int,vector<int>>m;
    map<int,bool>visited;
    void edge(int x, int y){
        m[x].push_back(y);
        m[y].push_back(x);
        
    }

    void dfs(int s){
        visited[s]=true;
        cout<<s<<" ";
        vector<int>::iterator itr;
        for(itr=m[s].begin();itr !=m[s].end();itr++){
            if(!visited[s]){
                cout<<'i';
                dfs(*itr);
            }
        }
        
    }

};

int main(){
    graph g;
    g.edge(0,1);
    g.edge(0,2);
    g.edge(0,3);
    g.edge(0,4);
    g.edge(0,5);
    g.edge(2,4);
    g.edge(2,3);
    g.edge(2,6);
    g.edge(3,5);
    g.edge(3,6);
    g.edge(3,2);
    g.edge(4,8);
    g.edge(4,6);
    g.edge(5,1);
    g.edge(5,8);
    g.dfs(2);
    cout<<"done";

    return 0;

}