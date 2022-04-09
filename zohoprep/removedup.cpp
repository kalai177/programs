#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int find(vector<int>v,int max){
    int count=0;
    for(int i=0;i<v.size();i++){

        if(v[i]==max){
            break;
        }
        count+=1;
    }
    return count;
}
void printarray(vector<int>v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    vector<int>v;
    int n;
    cout<<"Enter size";
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }

    int max=v[n-1]+10;
  
    for(int i=0;i<n;i++){
        if(v[i]==v[i+1]){
            v[i]=max;
        }
    }
    
     sort(v.begin(),v.end());
     int num= find(v,max);
     cout<<endl;
     cout<<num<<endl;
     printarray(v,n);
     return 0;
}