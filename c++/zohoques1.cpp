#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<bool>visited(26,0);
    string s;
    cout<<"enter the string:"<<endl;
    cin>>s;
    int size=s.size();
    cout<<"String after removing of duplicates:"<<endl;
    for(int i=0;i<size;i++){
        int j=s[i]-97;
        if(!visited[j]){
            cout<<s[i];
            visited[j]=1;
        }
    }
    return 0;
}