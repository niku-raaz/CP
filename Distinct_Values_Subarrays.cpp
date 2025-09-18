#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    // stack ? queue?

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;

    map<int,int> mp;
    int l=0;

    for(int r=0;r<n;r++){

        while(l<r && (mp.find(a[r])!=mp.end())){
            mp[a[l]]--;
            if(mp[a[l]]==0){
                mp.erase(mp.find(a[l]));
            }
            l++;
        }
        mp[a[r]]++;

        ans+=(r-l+1);
    }

    cout<<ans;
    
   
   
 return 0;
}