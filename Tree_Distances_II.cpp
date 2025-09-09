#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;
    cin>>n;

    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // 
    // 
    //
    vector<int> sub(n+1,0);

    auto dfs=[&](int node,int par,auto &&dfs)->void{
             int ans=1;

             for(auto child: g[node]){
                if(child==par) continue;
                dfs(child,node,dfs);
                ans+=sub[child];
             }
             sub[node]=ans;
    };
    dfs(1,-1,dfs);
   // cout<<sub[1]<<endl;;

    // 
    // Now considering root==1 
    // Calculate sun of its ditances from root
    int res=0;
    auto cal1=[&](int node,int par,int curr,auto &&cal1)->void{
            res+=curr;  
            for(auto child: g[node]){
                if(child==par)continue;
                cal1(child,node,curr+1,cal1);
            }
    };

    cal1(1,-1,0,cal1);
   // cout<<res;

    // Now Do rereRoot to calculate answer for all

    vector<int> ans(n+1,0);

    ans[1]=res;

    auto reRoot=[&](int node,int par,auto &&reRoot)->void{
         
        for(auto child: g[node]){
            if(child==par)continue;

            // jisme jaunga
            // utno mein -1 hoga
            int pres=res;
            res-=sub[child];
            int rem=n-sub[child];
            res+=rem;
            ans[child]=res;
            // subtree ko bhi change kro
            // child root banne wala hai
            int prev=sub[child];
            int val=n-sub[child];
            sub[child]=n;
            sub[node]=val;
            reRoot(child,node,reRoot);
            sub[child]=prev;
            sub[node]=n;

            // res ko rollback kro
            res=pres;
        }
    };

    reRoot(1,-1,reRoot);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }





    
   
   
 return 0;
}