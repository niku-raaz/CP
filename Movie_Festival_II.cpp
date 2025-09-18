#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;

        v[i]={y,x};
    }

    sort(v.begin(),v.end());
    int ans=0;
    set<pair<int,int>> s;

    for(int i=1;i<=k;i++){
        s.insert({0,i});
    }

    for(int i=0;i<n;i++){
        int st=v[i].second;
        int end=v[i].first;

        // find just before end hua <=st

        auto lo=s.upper_bound({st,1e10});
        // just greater
        if(lo==s.begin()){
            continue;
        }
        ans++;
        lo--;
        // now just smaller
        pair<int,int> p=*lo;
        s.erase(lo);
        s.insert({end,p.second});

    }
    cout<<ans;
    
   
   
 return 0;
}