#include<iostream>
#include<vector>
using namespace std;

int findrowcol(int n){
    if(n==1){
        return 1;
      
    }
      return 2+findrowcol(n-1);
}
int main(){
        int n;
        cout<<"Enter the size:";
        cin>>n;
        if(n==1) cout<<"1";
        int rowcol=findrowcol(n);
        

        vector<vector<int>>v(rowcol,vector<int>(rowcol));

        int tl=0,tr=rowcol-1,bl=0,br=rowcol-1;

        while(n>=1){
              for(int i=tl;i<=tr;i++){
                  v[tl][i]=n;
              } 
              tl++;
              for(int i=tl;i<=br;i++){
                  v[i][tr]=n;
              }    
              tr--;
              for(int i=tr;i>=bl;i--){
                
                  v[br][i]=n;
              }
              br--;
              for(int i=br;i>=tl;i--){
                  v[i][bl]=n;
              }
              bl++;
              n--;
        }

        for(int i=0;i<rowcol;i++){
            for(int j=0;j<rowcol;j++){\
          
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
}