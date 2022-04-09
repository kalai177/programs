#include<iostream>
#include<vector>
using namespace std;
void arrayelements(vector<int>&v1,int n){
    for(int i=0;i<n;i++){
        int k;
        cout<<"enter num :";
        cin>>k;
        v1.push_back(k);
    }
}


int findsum(vector<int>v,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    return sum;
}

void find(vector<int>v,int n){
     int sum=findsum(v,n);
     int ls=0;
     bool c=0;
     for(int i=0;i<n;i++){
         int rs=sum-v[i]-ls;
         if(ls==rs){
            
             cout<<"YES"<<endl;
             c=1;
             break;
         }
         ls+=v[i];
     }
     if(c==0){
       cout<<"NO";
     }
}


int main(){
    int testcases;
    cout<<"Enter number of testcases:";
    cin>>testcases;
    for(int i=0;i<testcases;i++){
        int n;
        vector<int>v;
        cout<<"enter the size";
        cin>>n;
        arrayelements(v,n);
        find(v,n);
    }
    return 0;
}