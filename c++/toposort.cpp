#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<queue>
using namespace std;
class Graph{
    public:
    int V;
    list<int>*adj;
    

    Graph(int v){
       this->V=v;
       adj=new list<int>[V];
   }

   void addEdge(int u,int v){
       adj[u].push_back(v);
   }
   void topologicalsort(){
       vector<int> indegree(V,0);
       for(int i=0;i<V;i++){
           list<int>::iterator itr;
           for(itr=adj[i].begin();itr!=adj[i].end();itr++){
               indegree[*itr]++;
           }
       }
       queue<int>q;
       for(int i=0;i<V;i++){
                if(indegree[i]==0) {
                    q.push(i);
                    cout<<i;
                }
           }
       
        int count=0;
        vector<int>result;
       while(!q.empty()){
           cout<<"while called";
           int s=q.front();
            q.pop();
            result.push_back(s);
            list<int>::iterator it;
            for(it=adj[s].begin();it!=adj[s].end();it++){
                if(--indegree[*it]==0){
                    cout<<*it;
                    q.push(*it);
                }
            }
            count+=1;
       }

      

       for(int i=0;i<result.size();i++){
           cout<<result[i];
       }
   }

  void dfsc(int i,vector<bool>&visited,vector<int>&connections){
     visited[i]=1;
     connections.push_back(i);
    list<int>::iterator itr;
    for(itr=adj[i].begin();itr!=adj[i].end();itr++){
        if(!visited[*itr]){
          
            dfsc(*itr,visited,connections);
        }
    }
}


  void findconnectors(){
     vector<bool>visited(V,0);
     vector<int>connections;
     for(int i=0;i<V;i++){
         if(!visited[i]){
             connections.clear();
            
             dfsc(i,visited,connections);
             for(int i=0;i<connections.size();i++){
                 cout<<connections[i];
             }
             cout<<endl;
         }
     }




  }








void 















   
}

;


int main(){
    
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
   
    g.findconnectors();
}