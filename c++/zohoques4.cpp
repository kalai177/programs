#include<iostream>
using namespace std;
int findmodulo(int n){
  return n%6;
}
int main(){
    int n;
    cout<<"Enter seat number:";
    cin>>n;
    if(n>=1 && n<=108){
        int modulovalue=findmodulo(n);
        if(modulovalue==0 || modulovalue%6==1){
            cout<<"WS";
        }
        else if(modulovalue%6==2 || modulovalue%6==5) {
             cout<<"MS";
        }
        else
         cout<<"AS";
    }
    else {
        cout<<"Available seat numbers are from 1 to 103";
    }
    return 0;
}