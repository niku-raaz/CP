#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
int cnt[N+2];
   
int main(){
    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    


    for(int i=0;i<n;i++){

        for(int m=1;m*m<=a[i];m++){
            if(a[i]%m==0){

                cnt[m]++;

                if(m*m!=a[i]){
                    cnt[a[i]/m]++;
                }
            }
        }
    }


    for(int i=N;i>=1;i--){
        if(cnt[i]>=2){
            cout<<i;
            break;
        }
    }


    
    
   
   
 return 0;
}