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

int findmin(vector<int>&v,int &index){

  




}


int main(){
    int n;
    vector<int>v1;
    vector<int>v2;
    arrayelements(v1,n);
    arrayelements(v2,n);
    int minindexv1=0;
    int minofv1=findmin(v1,minindexv1)

}