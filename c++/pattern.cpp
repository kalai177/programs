#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;
    if(a>b) return gcd(a-b,b);
    return gcd(a,b-a);
}
int main(){
    int n=5;
    int count=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            std::cout<<count++<<" ";
        }
        std::cout<<std::endl;
    }

   int a=gcd(4,8);
   if(a==1) cout<<"co-prime";
   else cout<<"not co prime";
    return 0;
}
