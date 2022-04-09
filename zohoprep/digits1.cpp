#include<iostream>
#include<vector>
using namespace std;
void printarray(vector<int>v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    vector<int>v;
    int n;
    cout<<"Enter the size";
    cin>>n;
    for(int i=0;i<n;i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
   
    int value=v[n-1]+1;
    int rem=value%10;
    int quo=value/10;
    v[n-1]=rem;
    v[n-2]=v[n-2]+quo;
    printarray(v,n);
    return 0;
   
}