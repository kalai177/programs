#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string:";
    cin>>s;
    
    int size=s.length();
    stack<char>st;

    for(int i=0;i<size;i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            st.push(s[i]);
        }
        else{
                if(!st.empty()){
                       if(s[i]=='}' && st.top()=='{'){
                           st.pop();
                       }
                       else if(s[i]==')' && st.top()=='('){
                           st.pop();
                       }
                       else if(s[i]==']' && st.top()=='['){
                           st.pop();
                       }
                       else {
                           st.push(s[i]);
                       }
                }
                else{
                    st.push(s[i]);
                }
        }
    }
   cout<<endl;
    if(st.size()>0) {
        cout<<"FALSE";
    }
    else{
        cout<<"TRUE";
    }
    return 0;
}