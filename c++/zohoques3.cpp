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

void printarray(vector<int>v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
}
int main(){
    int n;
    cout<<"enter array size:";
    cin>>n;
    vector<int>v1;
    arrayelements(v1,n);
    printarray(v1,n);
    cout<<endl;
  
    for(int i=0;i<n;i++){
        if(v1[i]==0){
            for(int j=i;j<n-1;j++){
                v1[j]=v1[j+1];
            }
           v1[n-1]=0;
        }
    }
    cout<<"array after shifted zero: ";
    printarray(v1,n);
    cout<<endl;

    


}