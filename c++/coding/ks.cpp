#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    string y="Case #1: YES";
    string n="Case #2: NO";
    for (int i = 0; i < T; i++) {
        int N, D, C, M;
        string s;
        cin >> N >> D >> C >> M;
        cin>>s;
        int c = count(s.begin(), s.end(), 'D');
        for (int j = 0; j < s.size(); j++) {
          
            if (s[j]=='C') {
                if (C >0)
                    C--;
                else if (C ==0 && M > 0)
                    M--;
                else{
                    
                    break;
                    }
            }
            if (s[j]=='D'){
            
                if (D > 0  && M==0) {
                    D--;
                    c--;
                } 
                
                else if(D>0 && M > 0)
                {
                    D--;
                    M++;
                    c--;
                    cout<<c;
                }
                else
                    break;
            }
        }
        if(c==0) cout<<y;
        else 
        cout<<n;
    }
    return 0;
}
