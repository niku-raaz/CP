#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;

    int g[n+1][n+1];
    int inf=1e18;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=inf;
        }
    }

    for(int i=1;i<=n;i++){
        g[i][i]=0;
    }


    // 
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==y) continue;
        g[x][y]=min(g[x][y],z);
        g[y][x]=min(g[y][x],z);
    }

    // Now Relax everything

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k]<inf && g[k][j]<inf){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;

        int ans=g[x][y];
        if(ans==inf){
            ans=-1;
        }
        cout<<ans<<endl;
    }
    
   
   
 return 0;
}