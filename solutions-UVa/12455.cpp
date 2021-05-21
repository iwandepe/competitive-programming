#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int tc, jml,nilai,sum;
    bool cek;
    cin>>tc;
    
    while(tc--){
        cin>>nilai;
        cin>>jml;
        int bars[jml];
        cek=false;
        
        for(int i=0;i<jml;i++) cin>>bars[i];
        
        // x << y
        // x * 2^y

        for(int i=0;i< (1<<jml); i++){ 
            sum=0;
            for(int j=0;j<jml;j++){
                if(i & (1<<j)){
                    sum += bars[j];
                }
            }
            if(sum==nilai) {
                cout<<"YES"<<endl;
                cek=true;
                break;
            }
        }
        if(cek==false) cout<<"NO"<<endl;
    }
}