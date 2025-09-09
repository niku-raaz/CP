#include<bits/stdc++.h>
using namespace std;
#define int long long


class dsu{
    private:
         vector<int> par;
         vector<int> rank;
         vector<int> numBlack;
         vector<int> col;
    public:

       dsu(int n){
        par.resize(n+1);
        rank.resize(n+1);
        numBlack.resize(n+1);
        col.resize(n+1);


        for(int i=1;i<=n;i++){
            numBlack[i]=0;
            par[i]=i;
            rank[i]=0;
            col[i]=0; // white //1 black
        }

       }

        int findPar(int x){
           if(par[x]==x){
            return x;
           }
           return par[x]= findPar(par[x]); 
        }
  
        void toggle(int x){
            int root=findPar(x);

            if(col[x]==0){
                col[x]=1;
                numBlack[root]++;
            }else{
                col[x]=0;
                numBlack[root]--;
            }
        }

        void unite(int x, int y){
            int rootx=findPar(x);
            int rooty=findPar(y);
            if(rootx==rooty) return;

            if(rank[rootx]<rank[rooty]){
                swap(rootx,rooty);
            }

            // rootx>=rooty;
            if(rank[rootx]==rank[rooty]){
                rank[rootx]++;
            }
            par[rooty]=rootx;
            numBlack[rootx]+=numBlack[rooty];
        }

        bool bata(int x){
            int rootx=findPar(x);
            if(numBlack[rootx]>0){
                return 1;
            }
            return 0;
        }
     

};
   
   
int32_t main(){
    int n,q;
    cin>>n>>q;

    

    dsu D(n);

    while(q--){
        int tt;cin>>tt;
      //  cout<<"ku \n";
        if(tt==1){
            int a,b;cin>>a>>b;
            D.unite(a,b);

        }else if(tt==2){
            int x;cin>>x;

            D.toggle(x);
        }else{
            int x;
            cin>>x;

            if(D.bata(x)){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }

        }
    }
    
   
   
 return 0;
}