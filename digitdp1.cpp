#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;

string s;
// 123
// 012

int dp[20][2][100];

int dfs(int ind, bool tight,int currsum){

    if(ind==s.size()){
        if(currsum==9){
            return 1;
        }
        return 0;
    }

    if(dp[ind][tight][currsum]!=-1){
        return dp[ind][tight][currsum];
    }

    char bound=(tight==1 ? s[ind]:'9');
    int ans=0;

    for(char x='0';x<=bound;x++){ 
        int newsum=currsum+(x-'0');
        ans+=dfs(ind+1,(tight==1)&&(s[ind]==x),newsum);
    }

    return dp[ind][tight][currsum]=ans;

}
   
   
int32_t main(){

  //  cin>>n;
   // cout<<n<<endl;;

   cin>>s;

   memset(dp,-1,sizeof(dp));

   cout<< dfs(0,1,0);


   
    
    
   
   
 return 0;
}