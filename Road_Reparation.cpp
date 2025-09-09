#include<bits/stdc++.h>
using namespace std;
#define int long long


class DSU{
      vector<int> par;
      vector<int> rank;

      public:

      DSU(int n){
        par.reserve(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i]=0;
        }
      }

      int findPar(int node){
        if(par[node]==node) return node;
        return par[node]=findPar(par[node]);
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
        // rootx is small
        par[rootx]=rooty;
        if(rank[rootx]==rank[rooty]){
            rank[rooty]++;
        }
        
      }

      bool isSame(int x,int y){
        int parx=findPar(x);
        int pary=findPar(y);
        if(parx==pary){
            return 1;
        }
        return 0;
      }

};
   
   
int32_t main(){

    int n;cin>>n;
    int m;cin>>m;

    vector<vector<int>> edges(m);

    for(int i=0;i<m;i++){
         int x,y,w;
         cin>>x>>y>>w;
         edges[i]={w,x,y};
    }

    // int ans=0;


    sort(edges.begin(),edges.end());

    DSU d(n);

    int ct=0;
    int ans=0;

    for(int i=0;i<m;i++){

        int w=edges[i][0];
        int x=edges[i][1];
        int y=edges[i][2];

        if(!d.isSame(x,y)){
            d.unite(x,y);
            ct++;
            ans+=w;
        }

        if(ct==n-1){
            break;
        }

    }

    if(ct<n-1){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<ans;
    }

    
   
   
 return 0;
}