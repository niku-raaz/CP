#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000000;
vector<int> D(N+1,0);
void pre(){
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            D[j]+=1;
        }
    } 
}
vector<int> g[N];
vector<int> a(N);

// for all its child D(i)*F(i)*F(i);
vector<int> ans(N);
unordered_map<int,int> dfs(int node,int par){
    unordered_map<int,int> mp;
    mp[a[node]]=1;
    for(auto child: g[node]){
        if(child==par)continue;
        unordered_map<int,int> cmp=dfs(child,node);
        if(mp.size()<cmp.size()){
            swap(mp,cmp);
        }
        for(auto it: cmp){
            mp[it.first]+=it.second;
        }
    }
    int sum=0;
    for(auto it: mp){
        int num=it.first;
        int fq=it.second;
        sum+=(D[num]*fq*fq);
    }
    ans[node]=sum;
    return mp;
}
   
int32_t main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pre();
    dfs(0,-1);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }


   
   
 return 0;
}