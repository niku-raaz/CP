 
// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI
   
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
#define int long long 
#define ll long long 
#define nl cout<<endl; 
#define raaz ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define take(n) int n; cin>>n;
#define takearr(a,n)  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define takevec(a,n)  vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];
#define sortv(v) sort(v.begin(),v.end());
#define sortarr(arr,n) sort(arr,arr+n);
#define show(ds) for(auto it: ds) cout<<it<<" ";cout<<endl;
#define pb push_back
#define pl cout<<endl;
#define ps cout<<" ";
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;
#define py cout<<"Yes"<<endl;
#define pn cout<<"No"<<endl;
#define ff(i,a,n) for(int i = a;i<n;i++)
#define fl(i,a,n) for(int i = n-1;i>=a;i--)


// write Fenwick // 1 based indexing

class BIT{
    vector<int> p;
    public:
    BIT(int n){
        p.resize(n+5,0);
    }
    void update(int ind,int val){
        // foward
        for(ind;ind<p.size();ind+=(ind&(-ind))){
            p[ind]+=val;
        }
    }
    int query(int ind){
        int ans=0;
        for(ind; ind>0;ind-=(ind&(-ind))){
            ans+=p[ind];
        }
        return ans;
    }
};


void solve(){
    // 
    take(n);

    //(1) First make the graph
    //then 
    //(2) transfer the edge weights to
    //the child node 
    //(3) write LCA
    //(4) then flatten the tree
    //(5) then use Fenwick (not segment (as it is time taking))

    vector<vector<pair<int,int>>> g(n+1);
    // always consider 1 as root

    vector<pair<int,int>> E(n);

    for(int i=1;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        E[i]={x,y};
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }

    // do a dfs to find the parent of each node 
    // and also // try transfering the edges withs to child

    vector<int> par(n+1,1);
    vector<int> depth(n+1,0);
    vector<int> a(n+1);
    vector<vector<int>> up(n+1,vector<int>(20));

    auto dfs1=[&](int node,int p,auto&& dfs1)->void{
              par[node]=p;
              up[node][0]=p;
              for(auto childp: g[node]){
                int child=childp.first;
                int wt=childp.second;
                if(child!=p){
                    depth[child]=depth[node]+1;
                    a[child]=wt;
                    dfs1(child,node,dfs1);
                }
              }
    };

    dfs1(1,1,dfs1);

    // show(par);
    // show(a);

    // correctly done till here

    // lets write LCA

    // 
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }

    // write code for LCA

    auto lca=[&](int x,int y)->int{
         
        // 
        // need depth;
        if(depth[x]>depth[y]){
            swap(x,y);
        }

        // depth of x is smaller
        // y is lower
        // bring y to the depth of x
        int diff=depth[y]-depth[x];

        for(int bit=19;bit>=0;bit--){
            if((diff>>bit)&1){
                //
                y=up[y][bit];
            }
        }

        // now both are at same level

        if(x==y){
            return x;
        }


        // bring both of them together

        for(int b=19;b>=0;b--){
            if(up[x][b]!=up[y][b]){
                x=up[x][b];
                y=up[y][b];
            }
        }


        return up[x][0];
    };

    //cout<<up[5][0]<<" "<<up[5][1];
    // hopefully correct till here

    // now time to flatten the tree

    vector<int> in(n+1),out(n+1);
    int tick=1;

    auto dfs=[&](int node,int p,auto&& dfs)->void{
        in[node]=tick;
        for(auto chp: g[node]){
            int child=chp.first;
            if(child!=p){
                tick++;
                dfs(child,node,dfs);
            }
        }
        out[node]=tick;
    };

    dfs(1,1,dfs);

    // show(in);
    // show(out);

    // i wanna build Fenwich tree over this
    // Hopefully BIT code is correct

    // build the BIt
    BIT b(n);

    for(int i=1;i<=n;i++){
        b.update(in[i],a[i]);
        b.update(out[i]+1,-a[i]);
    }

    // 
    // lest query

    take(q);
    while(q--){
        take(tt);
        if(tt==1){
            // update
            take(i); take(val);
            int x=E[i].first;
            int y=E[i].second;
            int c,p;
            if(par[x]==y){
                c=x;
                p=y;
            }else{
                c=y;
                p=x;
            }



            // update the child
            int diff=val-a[c];
            b.update(in[c],diff);
            b.update(out[c]+1,-diff);

            a[c]=val;
            
        }else{
            take(x); take(y);

            // find lca
            if(x==y){
                cout<<0<<endl;
                continue;
            }

            int mid=lca(x,y);


            int ans=0;

            ans+=b.query(in[x]);
            ans+=b.query(in[y]);
            ans-=(2*b.query(in[mid]));

            

            cout<<ans;pl;

            

        }
    }









   




    
    
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
       // cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }