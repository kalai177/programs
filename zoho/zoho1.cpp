#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void arrayelements(vector<int>&v, int n){
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
}
bool findprime(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count+=1;
        }
    }
    if(count==2) return 1;
    else return 0;
}
void ans(vector<int>v,vector<int>&result, int n){
   for(int i=0;i<n;i++){
       bool prime=findprime(v[i]);
       if(prime){
          
           if(i==n-1) {
               result.push_back(v[i]);
               break;
           }
           int greater=0;
           for(int j=i;j<n;j++){
           
               if(v[i]<v[j]){
                   greater=1;
                   break;
               }
              
           }
           if(greater==0) {
               
               result.push_back(v[i]);
           }
           
          
       }
   }
}
void printarray(vector<int>v){
    int s=v.size();
    for(int i=0;i<s;i++){
        cout<<v[i]<<",";
    }
    if(s==0) {
        cout<<"No leaders";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector<int>v;
    arrayelements(v,n);
    vector<int>result;
    ans(v,result,n);
    printarray(result);

   return 0;


}