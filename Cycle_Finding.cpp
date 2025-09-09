#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m);

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges[i]={x,y,w};
    }
    int inf=1e15;
    vector<int> d(n+1,0);
    vector<int> parent(n+1, -1);

    int bad=-1;



    for(int v=1;v<=n;v++){
        bad=-1;
        for(auto& v: edges){

            int x=v[0];
            int y=v[1];
            int w=v[2];

            if( d[y]>d[x]+w){
                d[y]=d[x]+w;
                parent[y]=x;
                bad=y;
            }
        }
    }

    // one more time
   

        if(bad!=-1){
            cout<<"YES\n";

            // fin dthe cycle
            int cycleNode=bad;

        for (int i = 0; i < n; i++) {
            cycleNode = parent[cycleNode];
        }

        vector<int> cycle;
        int v = cycleNode;
        do {
            cycle.push_back(v);
            v = parent[v];
        } while (v != cycleNode && (int)cycle.size() <= n+5);

        cycle.push_back(cycleNode);
        reverse(cycle.begin(), cycle.end());

        for (int x : cycle) cout << x << " ";
        cout << "\n";

            
        }else{
            cout<<"NO\n";
        }


    
   
   
 return 0;
}