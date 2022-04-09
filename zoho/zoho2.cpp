#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<array>
using namespace std;

void find(vector<char>&v,vector<vector<char>>alphabet,int n,string s){
    int size=s.size();
    int count=0;
    for(int i=n;i<size;i++){
        
        if(s[i]=='_'){
            count=0;
            continue;
        }

        if(s[i]==s[i+1]){
            count+=1;
        }
        else{
            v.push_back(alphabet[s[i]-48][count]);
            count=0;
        }
    }



}

void print(vector<char>v){
    int s=v.size();
    for(int i=0;i<s;i++){
        cout<<v[i];
    }
}


int main(){

  vector<vector<char>>alphabet={
                             {' '},
                             { ' '},
                             {'A','B','C'},
                             {'D','E','F'},
                             {'G','H','I'},
                             {'J','K','L'},
                             {'M','N','O'},
                             {'P','Q','R','S'},
                             {'T','U','V'},
                             {'W','X','Y','Z'},
                          };
 string s;
 cin>>s;

  vector<char>v;
  find(v,alphabet,0,s);
  print(v);

 return 0;
    
}