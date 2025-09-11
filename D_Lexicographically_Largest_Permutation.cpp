#include<bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
      vector<int> par;
      vector<int> rank;
      public:
      DSU(int n){
        par.resize(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i]=0;
        }
      }

      int findPar(int x){
        if(par[x]==x)return x;
        return par[x]=findPar(par[x]);
      }

      void unite(int x,int y){
        int rootx=findPar(x);
        int rooty=findPar(y);

        if(rootx==rooty){
            return;
        }
        if(rank[rootx]>rank[rooty]){
            swap(rootx,rooty);
        }

        // rootx has smaller rank
        par[rootx]=rooty;

        if(rank[rootx]==rank[rooty]){
            rank[rooty]+=1;
        }


      }

      

};
   
   
int32_t main(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n+1);
    //vector<int> ind(n+1); //index
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }


    // int ans=0

    DSU d(n);

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        d.unite(x,y);
       // cout<<x<<" "<<y<<endl;
    }

    vector<vector<pair<int,int>>> v(n+1);

    for(int i=1;i<=n;i++){
        int pp=d.findPar(i);
        v[pp].push_back({a[i],i});
       // cout<<pp<<" "<<i<<endl;
    }


    // sort every one decresing

    // make a new array

    vector<int> ans(n+1,0);

    for(int i=1;i<=n;i++){

        // ith group mein 
        // 
        vector<int> tmp;
        vector<int> idx;
        for(auto& it: v[i]){
            tmp.push_back(it.first);
            idx.push_back(it.second);
        }

        // sort
        sort(idx.begin(),idx.end());
        sort(tmp.rbegin(),tmp.rend());


        for(int j=0;j<tmp.size();j++){
            ans[idx[j]]=tmp[j];
        }
 
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    
   
   
 return 0;
}