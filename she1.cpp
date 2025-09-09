#include<bits/stdc++.h>
using namespace std;


void bfs(int start,int n,int k, vector<vector<int>>& g,vector<int>& safe,vector<int> vis){

    


    queue<pair<int,int>> q;
   

    q.push({start,0});
    vis[start]=1;

    while(!q.empty()){

        int node=q.front().first;
        int dis=q.front().second;

        q.pop();

        

        

        
        if(safe[node]==1 && node!=start){
            vis[node]=1;
            continue;
        }

        vis[node]=1;

        
        

        
        if(dis>k){
         
            break;

        }
        

        

        if(safe[node]!=1){
            safe[node]=2;

        }


        
        

        

        for(auto neg: g[node]){
            if(safe[neg]==1){
                continue;
            }
            if(vis[neg]){
                continue;
            }
            q.push({neg,dis+1});
        }




    }

    // for(int i=0;i<n;i++){
    //     cout<<safe[i]<<" ";
    // }
    // cout<<endl;




}

int solve(int n,vector<vector<int>>& g,vector<int>& theives,int t, int k, int start,int end){

    // 0 base index


    

    vector<int> safe(n,0),vis(n,0);
    // 0 means safe
    // 1 means direct unsafe
    // 2 means indirect unsafe

    for(auto c: theives){
        safe[c]=1;
       
    }

    // for(int i=0;i<n;i++){
    //     cout<<safe[i]<<" ";
    // }
    // cout<<endl;


    for(auto c: theives){
        bfs(c,n,k,g,safe,vis);
    }


    // for(int i=0;i<n;i++){
    //     cout<<safe[i]<<" ";
    // }

    // now we need last bfs


    queue<pair<int,int>> q;

    if(safe[start]!=0){
       // cout<<" hell";
        return -1;
    }

    q.push({start,0});

    vector<int> v(n,0);

    vector<int> d(n,-1);
    vis[start]=1;

    while(!q.empty()){
        int node=q.front().first;
        int did=q.front().second;
        q.pop();

        vis[node]=1;

        d[node]=did;

        for(auto neg: g[node]){
            if(vis[neg]==0 && safe[neg]==0){
                q.push({neg,did+1});

            }
        }

        
    }




   return d[end];

    



}
   
   
int main(){
    int n=9;

    vector<int> th={3,7};
    int t=2;
    int start=0;
    int end=8;

    int k=1;

    vector<vector<int>> g(n);

    g[0]={1,2};
    g[1]={0,3,4};
    g[2]={0,5,6};
    g[4]={1,7};
    g[3]={1};
    g[5]={2,7,8};
    g[6]={2,8};
    g[7]={4,5};
    g[8]={5,6};

    cout<<solve(n,g,th,t,k,start,end);




    
   
   
 return 0;
}