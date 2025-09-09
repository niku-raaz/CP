#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k;

vector<int> v;

pair<int,int> pp;
int d[100005];


bool dfs(int node,int par,vector<vector<int>>& g,vector<int>& vis){
     vis[node]=1;

     v.push_back(node);
     d[node]=d[par]+1;
     bool ff=0;

     for(auto& child: g[node]){
        if(child==par) continue;
        if(ff){
            break;
        }
        if(vis[child]==0){
            // good
           ff|= dfs(child,node,g,vis);
        }else if(vis[child]==1){


            int diff=abs(d[node]-d[child]);
            if(diff>=k){
                // good
                pp.first=child;
                pp.second=node;

                ff=1;
                return 1;
                
            }else{
                // not good
                //try more
                // skip
            }
        }


     }

     return ff;
     

}
   
int32_t main(){
    cin>>n>>m>>k;

    vector<vector<int>> g(n+1);

    vector<int> isF(n+1,0);

    for(int i=0;i<m;i++){
        int x;int y;
        cin>>x>>y;

        if(x>y){
            swap(x,y);
        }
        if(x==1){
            isF[y]=1;
        }
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> vis(n+1,0);

    dfs(1,-1,g,vis);

    vector<int> tmp;
    d[0]=-1;

    bool start=0;


    for(int i=0;i<v.size();i++){
        if(v[i]==pp.first){
            start=1;
        }

        if(start){
            tmp.push_back(v[i]);
        }
        if(v[i]==pp.second){
            break;
        }

    }


    cout<<tmp.size()<<endl;
    for(auto& x: tmp){
        cout<<x<<" ";
    }
    cout<<endl;

    

    

    // 
    
   
   
 return 0;
}