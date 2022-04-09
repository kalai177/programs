#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int k;
        cout<<"Enter the element:";
        cin>>k;
        v.push_back(k);
    }

    int minimum=INT_MAX;
    int maximum=INT_MIN;
    
    for(int i=0;i<n;i++){
        minimum=min(minimum,v[i]);
        maximum=max(maximum,v[i]);
    }
    cout<<"Minimum value is:"<<minimum;
    cout<<"Maximum value is:"<<maximum;
    return 0;
}