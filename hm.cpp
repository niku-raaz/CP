// Write your code here
#include<bits/stdc++.h>
using namespace std;

#define int long long

class DSU{
    public:
    vector<int> par;
    vector<int> rank;

    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            rank[i]=1;
            par[i]=i;
        }
    }

    // 
    int findPar(int x){
        if(par[x]==x) return x;

        return par[x]=findPar(par[x]);
    }

    void unite(int x,int y){
        int rootx=findPar(x);
        int rooty=findPar(y);

        if(rootx==rooty){
            return ;
        }

        // 
        if(rank[rootx]<rank[rooty]){
            swap(rootx,rooty);
        }

        // rank of rootx is larger

        // add rooty to rootx

        //if(rank[rootx]==rank[rooty]){
          rank[rootx]+=rank[rooty];
        //}

        par[rooty]=rootx;
    }

};

int count(vector<int> s1,vector<int> s2){
     int n=s1.size();

     if(n==0){
        return 0;
     }

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    int ans=0;
    int i=0;
    int j=0;
   

    while(i<n && j<n){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }else{
            if(s1[i]>s2[j]){
                ans++;
                j++;
            }else{
                ans++;
                i++;
            }
        }
    }

    ans+=(n-i);
    ans+=(n-j);

    return ans;


}

int32_t main(){
    
    int n;cin>>n;int m;cin>>m;
    vector<int> a(n+1),b(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }
    for(int i=0;i<n;i++){
        cin>>b[i+1];
    }

    int ans=0;
    // 
    // we can use DSUs

    DSU dsu(n);

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;

        dsu.unite(x,y);
    }

    vector<vector<int>> v1(n+1);
    vector<vector<int>> v2(n+1);

    for(int i=1;i<=n;i++){
        int pari=dsu.findPar(i);
        v1[pari].push_back(a[i]);
        v2[pari].push_back(b[i]);

    }


    for(int i=1;i<=n;i++){
        ans+=count(v1[i],v2[i]);
    }

    cout<<ans<<endl;


    


    // first find without any operation

    // 

    return 0;
}