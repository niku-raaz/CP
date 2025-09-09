#include<bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
      vector<int> par;
      vector<int> size;
      int Comp;
      int MaxComp;

      public:

      DSU(int n){
        par.resize(n+1);
        size.resize(n+1);
        Comp=n;
        MaxComp=1;

        for(int i=1;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
      }

      int numComp(){
        return Comp;
      }
      int maxSize(){
        return MaxComp;
      }

      int findPar(int node){
        if(par[node]==node) return node;
        return par[node]=findPar(par[node]);
      }

      void unite(int x,int y){
        int rootx=findPar(x);
        int rooty=findPar(y);

        if(rootx==rooty){
            return ;
        }

        if(size[rootx]>size[rooty]){
            swap(rootx,rooty);
        }

        // rootx is small componenet

        par[rootx]=rooty;
        size[rooty]+=size[rootx];

        if(size[rooty]>MaxComp){
            MaxComp=size[rooty];
        }
        Comp--;
      }
};
   
   
int32_t main(){
    int n,m;
    cin>>n>>m;

    DSU d(n);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        d.unite(x,y);

        cout<<d.numComp()<<" "<<d.maxSize()<<endl;
    }


    
   
   
 return 0;
}