#include<bits/stdc++.h>
using namespace std;



void dfs(int node,int par,vector<vector<int>>& g,vector<vector<int>>& up,vector<int>& depth){

            for(auto child: g[node]){
                if(child==par) continue;
                up[child][0]=node;
                depth[child]=depth[node]+1;
                dfs(child,node,g,up,depth);
            }
}
   
int32_t main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int n;cin>>n;
    int q;cin>>q;
    vector<vector<int>> up(n+1,vector<int>(19,0));


    vector<vector<int>> g(n+1);
    for(int i=2;i<=n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
       // cout<<up[i][0]<<" ";
    }
   // cout<<endl;
    vector<int> depth(n+1,0);
    up[1][0]=0; 
    

    dfs(1,0,g,up,depth);

    
   // cout<<up[4][0]<<endl;

    for(int m=1;m<=18;m++){ 
        for(int i=1;i<=n;i++){
            //if(up[i][m-1]!=0){
               up[i][m]=up[up[i][m-1]][m-1];
            //}
        }
    }
    // cout<<up[5][1]<<endl;;
    // cout<<up[4][1]<<endl;;
    //cout<<up[4][0]<<endl;

    // 
    // 
    

    auto lca=[&](int x,int y)->int{
            if(depth[x]>depth[y]){
                swap(x,y);
            }
            //cout<<depth[x]<<" "<<depth[y]<<endl;

            // y is a lower than x;
            int diff=depth[y]-depth[x];

            for(int i=18;i>=0;i--){
                if(diff&(1<<i)){
                    y=up[y][i];
                }
            }

            //cout<<y<<" "<<x<<endl;

            if(y==x){
                return y;
            }

            for(int i=18;i>=0;i--){
                if(up[x][i]!=up[y][i]){
                    x=up[x][i];
                    y=up[y][i];
                }
            }
            //cout<<x<<" "<<y<<endl;
            //cout<<up[x][0]<<endl;

            return up[x][0];
    };

    while(q--){
        int x,y;
        cin>>x>>y;
        
        int lc=lca(x,y);
       // cout<<x<<" "<<y<<" "<<lc<<" ";
        cout<<depth[x]+depth[y]-2*depth[lc]<<endl;
    }


    
    
   
   
 return 0;
}