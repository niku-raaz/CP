#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    // minimum will be 1 or 3
    // if 1 is possible then ok
    // else 3 

    // max we need to fin dout
    // 1 2 4 8 ... store the x for 2**x



    int n;cin>>n;
    vector<vector<int>> g(n+1);

    vector<int> val(n+1,0);
    // root should be one of the leaf

    vector<int> deg(n+1,0);


    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    // If u are srudying this code.
    // Listen this Full story
    // Initially my dream Company was Adobe bcs I wanted
    // free subscription for Adobe Creative Cloud apps

    // But I coudnt get into it, but I got Zepto SDE (even better pay)
    // didnt get PPO, 
    // for placements
    // my Dream companies were few
    // Google, GS, InMobi, Zomato, Meesho 

    // Got Meesho (even better pay than Google)

    //But Still I dream of switching to Google
    // or companies like Rippling, Squarepoint, Stripe.


    // Done.
    // Now focus on code


    int mn=1;// by default

    int root=0;

    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            root=i;
            break;
        }
    }

    // 
    // put value at root =0;

    val[root]=0;
    // try to make every edge =1
    // then pass on to the neighbour

    auto dfs=[&](int node,int par,auto && dfs)->void{

        for(auto child: g[node]){
            if(child==par)continue;

            int prev=val[node];
            val[child]=(1^prev);
            if(deg[child]==1 && val[child]!=0){
                mn=3;
            }
            dfs(child,node,dfs);
        }
    };

    dfs(root,0,dfs);
    cout<<mn<<" ";

    // The minimum part is done
    // now try doing it for maximum

    // 
    

    // all leafs should be 0

    int ans=n-1;

    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            val[i]=0;
            ans--;
        }
    }

    // e-l+m
    // m is no of non-leaf vertices having of negbour as leaf


    for(int i=1;i<=n;i++){
        if(deg[i]!=1){
            for(auto child: g[i]){
                if(deg[child]==1){
                    ans++;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;



    
   
   
 return 0;
}