#include<bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
      vector<int> par;
      vector<int> size;
      int ans;

      public:

      DSU(int n){
        par.resize(n+1);
        size.resize(n+1);
        ans=0;

        for(int i=1;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
      }

      int findPar(int x){
        if(par[x]==x) return x;
        return par[x]=findPar(par[x]);
      }

      void unite(int x,int y){
        int rootx=findPar(x);
        int rooty=findPar(y);

        if(rootx==rooty){
            return;
        }

        // unite
        if(size[rootx]>size[rooty]){
            swap(rootx,rooty);
        }

        // now rootx is smaller

        par[rootx]=rooty;
        ans+=(size[rootx]*size[rooty]);
        size[rooty]+=size[rootx];

      }

      int findRes(){
        return ans;
      }



};
   
   
int32_t main(){
    int n;cin>>n;
    int q;cin>>q;

    vector<vector<int>> E(n-1);

    for(int i=0;i<n-1;i++){
        int x,y,w;
        cin>>x>>y>>w;

        E[i]={w,x,y};
    }
    vector<pair<int,int>> queries(q);
    for(int i=0;i<q;i++){
        int x;cin>>x;
        queries[i]={x,i};
    }

    sort(E.begin(),E.end());

    sort(queries.begin(),queries.end());


    DSU d(n);

    
    int i=0;// for edge
    //j for query

    for(int j=0;j<q;j++){
        int qq=queries[j].first;

        while(i<n-1 && E[i][0]<=qq){
            d.unite(E[i][1],E[i][2]);
            i++;
        }

        int ans=d.findRes();

        queries[j].first=ans;
    }

    sort(queries.begin(),queries.end(),[&](pair<int,int>& a,pair<int,int>& b){
        return a.second<b.second;
    });

    for(int i=0;i<q;i++){
        cout<<queries[i].first<<" ";
    }



    

    
   
   
 return 0;
}