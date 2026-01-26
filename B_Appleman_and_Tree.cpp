#include<bits/stdc++.h>
using namespace std;
#define int long long
int N=100005;
vector<vector<int>> g(N);
int n;
vector<int> col(N);
int mod=1e9+7;

int dfs(int node,int par,int have){
    int res=1;
    if(col[node]==0){
        res=0;
    }

    for(auto child: g[node]){
        if(child==par)continue;

        int ans=0;
        // two choices
        // Cut
        // if already have black and child is back then must cut
        // if already have black and child is white -> can cut
        // 4 case
        // nich se upar aa rhe hain
        int b=(col[child]==1);
        if(have && b){
            // B/B
            // cut
            ans+=dfs(child,node,1);

        }else if(have && !b){
            // B W
            ans+=dfs(child,node,1);// noc ut
        }else if(!have && b){
            // W B
            ans+=dfs(child,node,1);
            ans+=dfs(child,node,0);
        }else{
            // W W -> no cut
            ans+=dfs(child,node,0);
        }
        if(col[node]==0){
            
            res+=ans;
        }else{
            res*=ans;
        }
        //res*=ans;

    }
    
    return res;

}
   
   
int32_t main(){
    cin>>n;

    for(int i=1;i<n;i++){
        int p;cin>>p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    for(int i=0;i<n;i++){
        cin>>col[i];
    }

    cout<<dfs(0,-1,col[0]==1);
    
    
   
   
 return 0;
}