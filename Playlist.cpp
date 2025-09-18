#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;

    map<int,int> mp;// stroes ind

    int ans=0;
    int last=0;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(mp.find(x)==mp.end()){
            mp[x]=i;
            ans=max(ans,i-last+1);
        }else{
            // already exist
            last=max(last,mp[x]+1);
            mp[x]=i;
            ans=max(ans,i-last+1);

        }
       // cout<<last<<" "<<i<<endl;
    }

    cout<<ans;
    
   
   
 return 0;
}