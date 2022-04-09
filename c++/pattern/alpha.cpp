#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            char a=65+ (j*(n-2))+i;
            cout<<a<<" ";

        }
        cout<<endl;
    }
    
    return 0;
}