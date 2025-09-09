#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string g[1000];
   
   
int32_t main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>g[i];
    }

    // write a BFS solution

    queue<pair<int,int>> q;

    pair<int,int> start,end;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='A'){
                start={i,j};
            }
            if(g[i][j]=='B'){
                end={i,j};
            }
        }
    }

    vector<vector<char>> vis(n,vector<char>(m,'O'));

    // O not visited
    vis[start.first][start.second]='E';
    g[end.first][end.second]='.';

    
    q.push(start);

    while(!q.empty()){
        auto node=q.front();
        int nx=q.front().first;
        int ny=q.front().second;

        q.pop();

        if(node==end){
           break;
        }

        // up
        int negx=nx;
        int negy=ny;
        if(nx-1>=0){
            negx=nx-1;

            if(vis[negx][negy]=='O' && g[negx][negy]=='.'){
                // 
                vis[negx][negy]='U';
                q.push({negx,negy});
            }
            
        }

        // down

        negx=nx+1;
        if(negx<n){

            if(vis[negx][negy]=='O' && g[negx][negy]=='.'){
                // 
                vis[negx][negy]='D';
                q.push({negx,negy});
            }

        }
        negx=nx;


        // left
        negy=ny-1;
        if(negy>=0){
            if(vis[negx][negy]=='O' && g[negx][negy]=='.'){
                // 
                vis[negx][negy]='L';
                q.push({negx,negy});
            }

        }
        negy=ny;


        // right
        negy=ny+1;

        if(negy<m){
            if(vis[negx][negy]=='O' && g[negx][negy]=='.'){
                // 
                vis[negx][negy]='R';
                q.push({negx,negy});
            }
        }

    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<vis[i][j];
    //     }
    //     cout<<endl;
    // }

    

    


    string s="";

    int currx=end.first;
    int curry=end.second;
    if(vis[currx][curry]=='O'){
        cout<<"NO";
        return 0;
    }

    while(vis[currx][curry]!='E'){
          char x=vis[currx][curry];
          s.push_back(x);
          
          //cout<<x;

          if(x=='R'){
            curry-=1;

          }else if(x=='L'){
            curry+=1;

          }else if(x=='D'){
            currx-=1;

          }else if(x=='U'){
            currx+=1;
          }
    }
  //  cout<<endl;

    cout<<"YES"<<endl;

    cout<<s.size()<<endl;
    reverse(s.begin(),s.end());

    for(auto& x: s){
        cout<<x;
    }





    
   
   
 return 0;
}