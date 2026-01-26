#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int n,m;
    cin>>n>>m;

    int ans=1;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n>m){
       cout<<0;
       return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans*=abs(a[j]-a[i]);
            ans%=m;
            if(ans==0){
                cout<<0;
                return 0;
            }
        }
    }

    cout<<ans;
                



    

    
   
   
 return 0;
}