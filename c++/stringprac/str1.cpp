#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iterator>
#include<array>
using namespace std;
int main(){



 int n;
cout<<n;
  map<int,bool>visited;
  int arr[]={1,2,3,4,5,6};
  for(int i=0;i<6;i++){
    visited[arr[i]]=true;
  }
 visited[6]=false;
 cout<<visited[6]<<"visited"<<endl;
 map<int,bool>::iterator itr;

 for(auto itr=visited.begin();itr!=visited.end();itr++){
     cout<<itr->first<<itr->second<<endl;
 }
return 0;
}