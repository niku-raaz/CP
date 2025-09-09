#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    // Find a positive cycle
    // then -1

    int n,m;
    cin>>n>>m;
    int inf=-1e15;
    
    vector<int> d(n+1,inf);

    /// Max score to reach i from 1 is d[i]
    // 
    d[1]=0;

    vector<vector<int>> edges(m);

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges[i]={x,y,w};
    }

    // Relax n-1 time

    for(int v=1;v<n;v++){

        for(auto& v: edges){
            int x=v[0];
            int y=v[1];
            int w=v[2];
            if( d[x]>inf && d[y]<d[x]+w){
                d[y]=d[x]+w;
            }
        }
    }
    int ans=d[n];
    bool cycle=0;
    vector<int> bad;
         for(auto& v: edges){
            int x=v[0];
            int y=v[1];
            int w=v[2];
            if( d[x]>inf &&   d[y]<d[x]+w){
               cycle=1;
               d[y]=d[x]+w;
               bad.push_back(y);
            }
        }



    vector<vector<int>> g(n+1);
    for(auto v: edges){
        g[v[0]].push_back(v[1]);
    }
    
    vector<int> vis(n+1,0);
    queue<int> q;
    for(auto x: bad){
        q.push(x);
    }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=1;

        if(x==n){
            cout<<-1;
            return 0; 
        }

        for(auto& child: g[x]){
            if(!vis[child]){
                q.push(child);
            }
        }
    }






    


    cout<<ans;




    



    
   
   
 return 0;
}