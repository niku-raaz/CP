#include <bits/stdc++.h>
using namespace std;

struct {
    int par[100005];
    int rank[100005];


    void init(){

        for(int i=1;i<=100000;i++){
            par[i]=i;
            rank[i]=0;
        }

    }

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]); // this is so clever
        
    }

    int unite(int x, int y){
        int rootx=find(x);
        int rooty=find(y);

        if(rank[rootx],rank[rooty]){
            swap(rootx,rooty);
        }

        if(rank[rootx]==rank[rooty]) rank[rootx]++;
        par[rooty]=rootx;
    }
};

int main()
{

    return 0;
}