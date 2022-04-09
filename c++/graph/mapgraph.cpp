#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<iterator>
using namespace std;
map<int, list<int>>m;
map<int,bool>visited;
map<int,bool>vi;
queue<int>q;
void add(int u, int v){
 m[u].push_back(v);
 m[v].push_back(u);
}
void dfs(int s){
    visited[s]=true;
    cout<<s;
    list<int>::iterator itr;
    for(itr=m[s].begin();itr!=m[s].end();itr++){
        if(!visited[*itr]) dfs(*itr);
    }
}
void bfs(int s){
    q.push(s);
    vi[s]=true;
    while(!q.empty()){
        int k=q.front();
        q.pop(); 
        cout<<k;
        list<int>::iterator itr;
        for(itr=m[k].begin();itr!=m[k].end();itr++){
            if(!vi[*itr]){
                vi[*itr]=true;
                q.push(*itr);

            }
        }
    }
    }


int main(){
add(1,2);
add(1,4);
add(2,3);
add(2,8);
add(3,4);
add(3,2);
add(3,7);
add(4,5);
add(4,9);
add(5,6);
add(5,10);
cout<<"the dfs is:";
//dfs(1);
cout<<endl;
bfs(1);
cout<<endl;
cout<<"done";
return(0);
}