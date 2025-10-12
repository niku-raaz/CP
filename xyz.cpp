#include<bits/stdc++.h>
using namespace std;
int lift[200005][15];
int arr[200005];
int dept[200005];
vector<int>adj[200005];
struct da{
    int pre;
    int tot;
    int suf;
};
da res[200005][15];
void dfs(int node,int par){
    for(auto it:adj[node]){
        if(par!=it){
            dept[it]+=dept[node];
            lift[it][0] = node;
            res[it][0].pre = max(arr[it],arr[it]+arr[node]);
            res[it][0].suf = max(arr[node],arr[node]+arr[it]);
            res[it][0].tot = (arr[node]+arr[it]);
            dfs(it,node);
        }
    }
}
int lca(int u,int v){
  if(dept[u]<dept[v])swap(u,v);
  for(int i = 15;i>=0;i--){
    if(dept[v]+(1ll<<i)<=dept[u]){
        u = lift[u][i];
    }
  }
  if(u == v)return u;
  for(int i = 15;i>=0;i--){
    if(lift[u][i]!=lift[v][i]){
        u = lift[u][i];
        v = lift[v][i];
    }
  }
  return lift[u][0];
}
void solve(){
    int n;cin>>n;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dept,1,sizeof(dept));
    dfs(1,0);
    for(int i = 1;i<=15;i++){
        for(int j = 1;j<=n;j++){
            int nn = lift[j][i-1];
            int mid = arr[nn];
            lift[j][i] = lift[nn][i-1];
            res[j][i].tot = res[j][i-1].tot+res[nn][i-1].tot-mid;
            res[j][i].pre = max(res[j][i-1].pre,res[j][i-1].tot-mid+res[nn][i-1].pre);
            res[j][i].suf = max(res[nn][i-1].suf,res[nn][i-1].tot-mid+res[j][i-1].suf);
        }
    }
    
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        int l = lca(a,b);
        da patha = {arr[a],arr[a],arr[a]};
        int cura = a;
        for(int i = 15;i>=0;i--){
            if(lift[cura][i]!=0 and dept[lift[cura][i]]>=dept[l]){
                da block = res[cura][i];
                int to = patha.tot+block.tot-arr[cura];
                int pr = max(patha.pre,patha.tot-arr[cura]+block.pre);
                int su = max(block.suf,block.tot-arr[cura]+patha.suf);
                patha = {pr,to,su};
                cura = lift[cura][i];
            }
        }
        da pathb = {arr[b],arr[b],arr[b]};
        int curb = b;
        for(int i = 15;i>=0;i--){
            if(lift[curb][i]!=0 and dept[lift[curb][i]]>=dept[l]){
                da block = res[curb][i];
                int to = pathb.tot+block.tot-arr[curb];
                int pr = max(pathb.pre,pathb.tot-arr[curb]+block.pre);
                int su = max(block.suf,block.tot-arr[curb]+pathb.suf);
                pathb = {pr,to,su};
                curb = lift[curb][i];
            }
        }
        int ans1 = patha.pre;
        int ans2 = patha.tot+pathb.suf-arr[l];
        cout<<max(ans1,ans2)<<endl;
    }
}

int main(){
    solve();
    return 0;
}