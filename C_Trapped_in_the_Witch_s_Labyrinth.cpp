 
  
// JITNA BHI DEKHU, DIL BHAR NA PAAYE 
// KAISA SAMAA HAI, HUM TUM YAHA HAI
// JAAHIR KARU KYA HAI JO, MERE IRAADAY
   
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
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
   
   
class SGTree {
    vector<int> seg;
public:
  SGTree(int n) {
       seg.resize(4 * n + 1);
   }

   void build(int ind, int low, int high, int arr[]) {
      if (low == high) {
           seg[ind] = arr[low];
           return;
       }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
    // no overlap
    // l r low high or low high l r
    if (r < low || high < l) return INT_MAX;

    // complete overlap
    // [l low high r]
    if (low >= l && high <= r) return seg[ind];

    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return min(left, right);
   }
   void update(int ind, int low, int high, int i, int val) {
    if (low == high) {
       seg[ind] = val;
       return;
    }

    int mid = (low + high) >> 1;
    if (i <= mid) update(2 * ind + 1, low, mid, i, val);
    else update(2 * ind + 2, mid + 1, high, i, val);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
bool isPrime(int n){
      if(n<=1){
      return false;
      }
   for(int i = 2;i*i<=n;i++){
     if(n%i==0){
     return false;
       }
    }
  return true;
    }
   
   
   
bool sbs(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
   }
   
long long binpow(long long a, long long b, long long m) {
   a %= m;
   long long res = 1;
   while (b > 0) {
        if (b & 1)
          res = res * a % m;
        a = a * a % m;
        b >>= 1;
   }
  return res;
}  
   
   
// think of binary search,prefix sum , DP, graph duplication, think in rreverse,    
 // add +M int mod questions  
// think properly   
   
   
// in DP check its subarray / subsequence / subset  
  // then check if its counting problem / optimising problem 
 // then decides the states of DP and transitions and write recurrsion  
   
   
   
 // DP Forms  
 //  Form 1: level wise take/not take  
 //  Form 2: Answer ending here (0...level)  
 //  Form 3: Multisequence eg. LIS, LCS  
 //  Form 4: DP(L,R)=> DP(L,P)*DP(P,R), break in between  
 // Form 5: Game DP  (may have some pattern)  
   
int n,m;

bool issafe(int i,int j){

    if(i<n && j<m && i>=0 && j>=0){
        return 1;
    }
    return 0;
}
   
void solve(){
    cin>>n>>m;

   

    vector<vector<char>> mat(n,vector<char>(m));
    vector<vector<bool>> safe(n,vector<bool>(m,0));


   queue<pair<int,int>> q;
   vector<vector<bool>> vis(n,vector<bool>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    for(int j=0;j<m;j++){
        if(mat[0][j]=='U'){
            safe[0][j]=1;

            if(1){
                vis[0][j]=1;
                q.push({0,j});

            }
            

            
        }

        

        if(mat[n-1][j]=='D'){
            safe[n-1][j]=1;

            if(1){
                vis[n-1][j]=1;
                q.push({n-1,j});

            }
        }
    }

    for(int i=0;i<n;i++){
        if(mat[i][0]=='L'){
            safe[i][0]=1;
            if(1){
                vis[i][0]=1;
                q.push({i,0});

            }
        }

        if(mat[i][m-1]=='R'){
            safe[i][m-1]=1;

            if(1){
                vis[i][m-1]=1;
                q.push({i,m-1});

            }
        }
    }



    int dirx[4]={0,0,-1,1};
    int diry[4]={-1,1,0,0};

    // while(!q.empty()){
    //     cout<<q.front().first<<" "<<q.front().second<<"   ";
    //     q.pop();
    // }
    // pl;


    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;

        vis[cx][cy]=1;
        q.pop();


        if(mat[cx][cy]=='R'){
 
                        if(issafe(cx,cy+1)){
 
                            if(safe[cx][cy+1]){
                                safe[cx][cy]=1;
                            }
 
 
 
                        }
 
 
 
        }else if(mat[cx][cy]=='L'){
 
                        if(issafe(cx,cy-1)){
 
                            if(safe[cx][cy-1]){
                                safe[cx][cy]=1;
                            }
 
 
 
                        }
 
 
 
 
 
        }else if(mat[cx][cy]=='U'){
 
 
                        if(issafe(cx-1,cy)){
 
                            if(safe[cx-1][cy]){
                                safe[cx][cy]=1;
                            }
 
 
 
                        }
 
 
        }else if(mat[cx][cy]=='D'){
 
                        if(issafe(cx+1,cy)){
 
                            if(safe[cx+1][cy]){
                                safe[cx][cy]=1;
                            }
 
 
 
                        }
 
 
 
        }
 
        
 
 
 
        for(int k=0;k<4;k++){
 
            int lef=cx+dirx[k];
            int rr=cy+diry[k];  
 
            if(issafe(lef,rr)){
                          //  cout<<lef<<" "<<rr<<"   ";pl;
 
 
                if(!vis[lef][rr]  && mat[lef][rr]!='?'){
                    q.push({lef,rr});
 
                }
 
 
            }
 
                        
 
        }




    }

    









   

    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(mat[i][j]=='?'){

                bool flag=0;


                for(int k=0;k<4;k++){

                        int lef=i+dirx[k];
                        int rr=j+diry[k];

                        if(issafe(lef,rr)){

                            if(!safe[lef][rr]){
                                flag=1;
                            }



                        }

            

                        

                }

                if(flag){
                    safe[i][j]=0;
                }else{
                    safe[i][j]=1;
                }




            }




        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){

    //         cout<<safe[i][j]<<" ";

    //     }pl;
    // }

    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(!safe[i][j]){
                ans++;
            }

        }
    }

    cout<<ans;pl;



        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }