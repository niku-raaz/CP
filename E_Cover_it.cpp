#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node,int par,vector<vector<int>>& g,vector<int>& col){

    if(par==0){
        col[node]=1; 
    }else{
        col[node]=3-col[par];
    }

    for(auto& child: g[node]){
        if(child==par)continue;
        if(!col[child]){
            dfs(child,node,g,col);
        }
    }

}


   
   
int32_t main(){
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;

        int m;cin>>m;

        vector<vector<int>> g(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> col(n+1,0);
        // 0 means unvisted
        // 1 means take
        // 2 means not-take
        dfs(1,0,g,col);

        vector<int> v1,v2;

        for(int i=1;i<=n;i++){
            if(col[i]==1){
                v1.push_back(i);
            }else{
                v2.push_back(i);
            }
        }

        if(v1.size()<v2.size()){
            cout<<v1.size()<<endl;
           for(auto& x: v1){
            cout<<x<<" ";
           }
        }else{
            cout<<v2.size()<<endl;
            for(auto& x: v2){
            cout<<x<<" ";
           }

        }

        cout<<endl;
    }
    
   
   
 return 0;
}