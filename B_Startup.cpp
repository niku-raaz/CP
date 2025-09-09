#include<bits/stdc++.h>
using namespace std;
   
   
int main(){

    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> mp(n+1,0);

        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;

            mp[a]+=b;
        }

        sort(mp.rbegin(),mp.rend());

        int ans=0;

        for(int i=0;i<min(n,k);i++){
            ans+=mp[i];
        }

        cout<<ans<<"\n";




    }
    
   
   
 return 0;
}