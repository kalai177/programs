#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int num;
    cout<<"Enter the num:";
    cin>>num;
    string res="";
    int val[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string symbol[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    while(num>0){
        int div=num/val[i];
        while(div!=0){
            res+=symbol[i];
            div--;
        }
        num=num%val[i];
        i--;
        
    }
    cout<<res;
    return 0;
}
