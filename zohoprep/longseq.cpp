#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string:";
    cin>>s;
    int size=s.length();
    string result;
    int start,end;
    start=0;
    int startposition=0;
    while(start<size){
        end=start+1;
        map<char,bool>visited;
        visited[s[start]]=true;
        while(end<size && visited[s[end]]==false){
               visited[s[end]]=true;
               end++;
        }

       string curr;
       for(int i=start;i<end;i++){
           curr.push_back(s[i]);
       }

        //string curr=s.substr(start,end-start);
        if(result.length()<curr.length()){
            result=curr;
            startposition=start;
        }

        start=end;
    }
    cout<<"The length is:"<<result.length()<<endl;
    cout<<"The string :"<<result <<" "<<"Starting position"<<startposition<<endl;
   cout<<endl;

return 0;

}