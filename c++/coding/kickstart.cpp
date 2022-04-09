#include<iostream>
#include<string>
#include<vector>
using namespace std;
string recFunc(string str,string dummy){
    string d1=dummy;
    string imp="imposible";
    for(int i=0;i<str.size()-1;i++){
        swap(d1[i],d1[i+1]);
    }
    if(d1==str) return "";
    for(int i=0;i<d1.size();i++){
        if(d1[i]==str[i]) return recFunc(str,d1);
    }
    return d1;
}
int main(){
    int n;
    cin>>n;
    vector<string>vect;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        vect.push_back(str);
    }
   for(int i=0;i<n;i++){
       string dummy=vect[i];
       string sf=recFunc(vect[i],dummy);
       if(sf.size()==0) sf="IMPOSSIBLE";
       cout<<"Case #"<<i+1<<": ";
       cout<<sf<<endl;
   }
}
