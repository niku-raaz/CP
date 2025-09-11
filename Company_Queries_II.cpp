#include<bits/stdc++.h>
using namespace std;
#define int long long


   
   
int32_t main(){
    int n;cin>>n;
    int q;cin>>q;
    vector<vector<int>> up(n+1,vector<int>(20,0));


    vector<vector<int>> g(n+1);
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        g[p].push_back(i);
        up[i][0]=p;
       // cout<<up[i][0]<<" ";
    }
   // cout<<endl;

    up[1][0]=0; 
   // cout<<up[4][0]<<endl;

    for(int m=1;m<=19;m++){ 
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
    vector<int> depth(n+1,0);
    auto dfs=[&](int node,auto &&dfs)->void{
            for(auto child: g[node]){
                depth[child]=depth[node]+1;
                dfs(child,dfs);
            }
    };

    dfs(1,dfs);

    auto lca=[&](int x,int y)->int{
            if(depth[x]>depth[y]){
                swap(x,y);
            }
            //cout<<depth[x]<<" "<<depth[y]<<endl;

            // y is a lower than x;
            int diff=depth[y]-depth[x];

            for(int i=19;i>=0;i--){
                if(diff&(1<<i)){
                    y=up[y][i];
                }
            }

            //cout<<y<<" "<<x<<endl;

            if(y==x){
                return y;
            }

            for(int i=19;i>=0;i--){
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
        cout<<lca(x,y)<<endl;
    }


    
    
   
   
 return 0;
}