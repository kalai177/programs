#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<char>>&v,int i,int j){
 if(i<0 || j<0 || i>=v.size() || j >=v[i].size() || v[i][j]=='#') return;
    v[i][j]='#';
    dfs(v,i-1,j);
    dfs(v,i+1,j);
    dfs(v,i,j-1);
    dfs(v,i,j+1);
}
int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>v(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            v[i][j]=c;
            
        }
       
    }
   
     int c=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(v[i][j]=='.'){
                
                dfs(v,i,j);
                c++;
                
            }
        }
    }
    cout<<c<<endl;
    return 0;

}