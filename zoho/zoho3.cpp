#include<iostream>
#include<vector>
using namespace std;


int main(){
    int size;
    cin>>size;
    int v[size][size];
    int tl=0;
    int tr=size-1;
    int bl=0;
    int br=size-1;
    int n=1;
    while(tl<=tr && bl<=br){
           
        for(int j=tl;j<=tr;j++){
            v[tl][j]=n;
           
            n+=1;
        }
        tl++;
        
        for(int k=tl;k<=br;k++){
                v[k][tr]=n;
               
                n+=1;
        }

        tr--;
        for(int k=tr;k>=bl;k--){
            
            v[br][k]=n;
            
            n+=1;
        }
        br--;
        for(int k=br;k>=tl;k--){
            v[k][bl]=n;
            
            n+=1;
        }
        bl++;
        

    }
    n=size;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ 
          cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}