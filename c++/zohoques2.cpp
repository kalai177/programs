#include<iostream>
#include<vector>
using namespace std;
 void arrayelements(vector<int>&v,int n){
     cout<<"array";
     for(int i=0;i<n;i++){
         int k;
         cout<<"enter num";
         cin>>k;
         v.push_back(k);
     }
 }
int main(){
    int n1;
    int n2;
    vector<int>v1;
    vector<int>v2;
    cout<<"size of array1"<<endl;
    cin>>n1;
    cout<<"size of array2"<<endl;
    cin>>n2;

    arrayelements(v1,n1);
    arrayelements(v2,n2);
    vector<int>v3;

   int i=0;
   int j=0;

    while(i!=n1 || j!=n2){
        if(i<n1)
        {
          v3.push_back(v1[i]);
          i++;
        }
        if(j<n2)
        {
          v3.push_back(v2[j]);
          j++;
        }
    }


    int size=v3.size();
    for(int i=0;i<size;i++){
        cout<<v3[i]<<" ";
    }
    return 0;
}