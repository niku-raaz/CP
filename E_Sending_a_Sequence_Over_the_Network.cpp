 
  
// JITNA BHI DEKHU, DIL BHAR NA PAAYE 
// KAISA SAMAA HAI, HUM TUM YAHA HAI
// JAAHIR KARU KYA HAI JO, MERE IRAADAY
   
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   

#define raaz ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define take(n) int n; cin>>n;
#define takearr(a,n)  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define takevec(a,n)  vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];

#define pb push_back
#define pl cout<<endl;
#define ps cout<<" ";
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;

   
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
   
bool rec(int i, int ct,vector<int>& b, vector<map<int,bool>>& dp){

        if(i==b.size() && ct==0){
            return true;
        }

        if(i>=b.size()){
            return false;
        }


        if(dp[i].find(ct)!=dp[i].end()){
            return dp[i][ct];
        }

        
       

        bool ans=false;

         if(ct==0){
            // this maybe size
           ans|= rec(i+b[i]+1,0,b,dp);
         }

         if(ct==b[i]){
            ans|=rec(i+1,0,b,dp);
         }

         ans|=rec(i+1,ct+1,b,dp);

         return  dp[i][ct]=ans;

}
   
void solve(){
    take(n);
    int b[n+1];
    for(int i=0;i<n;i++){
        cin>>b[i+1];
    }


    vector<int> dp(n+1,0);

    dp[0]=1;

    for(int i=1;i<=n;i++){
        if(dp[i-1]==1 && i+b[i]<=n){
            dp[i+b[i]]=1;
        }

        if(i-b[i]-1>=0 && dp[i-b[i]-1]){
            dp[i]=1;
        }
    }

    bool f=dp[n];

//     bool tmp=1;
//     for(int i=0;i<n;i++){
//         if(b[i]!=1){
//             tmp=0;
//         }
//     }

//     if(tmp){
//         // saare 1

//         if(n&1){
//             pN;
//         }else{
//             pY;
//         }

//         return;
//     }


//    // map<pair<int,int>,bool> dp;

//     vector<map<int,bool>> dp(n);

//     //

//     bool f=rec(0,0,b,dp);

    if(f){
        pY;
    }
    else{
        pN;
    }




        
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