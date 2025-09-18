#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    // at most 
    // k distinct

    // <=k 
    int n;cin>>n;
    int k;cin>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans=0;
    map<int,int> mp;
    int l=0;

    for(int r=0;r<n;r++){
        mp[a[r]]++;
        while(l<r && mp.size()>k){
            mp[a[l]]--;
            if(mp[a[l]]==0){
                mp.erase(a[l]);
            }
            l++;
        }
        ans+=(r-l+1);

    }

    cout<<ans;
    
   
   
 return 0;
}