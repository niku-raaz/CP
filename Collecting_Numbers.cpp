#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    vector<int> a(n);
    vector<int> mp(n+1);

    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }


    // we have map vector
    int ans=1;

    for(int i=2;i<=n;i++){
        if(mp[i]<mp[i-1]){
            ans++;
        }
    }

    cout<<ans;
    
   
   
 return 0;
}