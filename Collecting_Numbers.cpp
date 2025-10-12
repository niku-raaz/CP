#include<bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
    vector<int> par;
    public:
    DSU(int n){
        par.resize(n+1,0);

        for(int i=1;i<=n;i++){
            par[i]=i;
        }
    }

    int findPar(int x){
        if(par[x]==x) return x;
        return par[x]=findPar(par[x]);
    }

    void unite(int x,int y){
        int rx=findPar(x);
        int ry=findPar(y);
        par[rx]=ry;
    }

    void res(int n){
        set<int> s;
        for(int i=1;i<=n;i++){
            s.insert(findPar(i));
        }
        cout<<s.size();
    }
    

};
   
   
int32_t main(){
    int n;cin>>n;    
    // DSU
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<int,int> mp;
    int ans=0;

    for(int i=n-1;i>=0;i--){
        int need=a[i]+1;
        if(mp.find(need)==mp.end()){
           ans++;
        }
        mp[a[i]]++;
    }
    
    cout<<ans;




 return 0;
}