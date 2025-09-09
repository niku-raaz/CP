 
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
#define int long long 
#define ll long long 
#define nl cout<<endl; 
#define raaz ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define take(n) int n; cin>>n;
#define takearr(a,n)  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define takevec(a,n)  vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];
#define sortv(v) sort(v.begin(),v.end());
#define sortarr(arr,n) sort(arr,arr+n);
#define show(ds) for(auto it: ds) cout<<it<<" ";cout<<endl;
#define pb push_back
#define pl cout<<endl;
#define ps cout<<" ";
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;
#define py cout<<"Yes"<<endl;
#define pn cout<<"No"<<endl;
#define ff(i,a,n) for(int i = a;i<n;i++)
#define fl(i,a,n) for(int i = n-1;i>=a;i--)
   

   
void solve(){
    take(n);
    take(m);

    vector<string> g(n);
    ff(i,0,n){
        cin>>g[i];
    }

    vector<vector<bool>> vis(n,vector<bool>(m,0));

    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        if(g[i][0]=='O'){
            q.push({i,0});
          //  vis[i][0]=1;
        }
        if(g[i][m-1]=='O'){
            q.push({i,m-1});
          //  vis[i][m-1]=1;

        }
    }

    for(int j=0;j<m;j++){
        if(g[0][j]=='O'){
            q.push({0,j});
          //  vis[0][j]=1;
        }

        if(g[n-1][j]=='O'){
            q.push({n-1,j});
          //  vis[n-1][j]=1;
        }
    }


    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};


    while(!q.empty()){

        int x=q.front().first;
        int y=q.front().second;

        q.pop();


        vis[x][y]=1;

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m){

                if(g[nx][ny]=='O' && vis[nx][ny]==0){
                    q.push({nx,ny});
                }


            }



        }



    }


    int ans=0;

    ff(i,0,n){
        ff(j,0,m){
           // cout<<vis[i][j];
            if(vis[i][j]){
                ans++;
            }
        }
      //  pl;
    }

    cout<<ans;
        
}

int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); 

             if(xyz<test_case){
                cout<<endl;
             }
            
            };        
   return 0;
   }