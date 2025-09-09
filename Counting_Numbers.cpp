#include<bits/stdc++.h>
using namespace std;
#define int long long

string low,high;

int dp[20][2][12][20];

// starting zeors are creating problem

int dfs(int ind,int tight,int last,int lead,string& s){     
    if(ind==(int)s.size()){
        return 1;
    }
    if(dp[ind][tight][last][lead]!=-1) return dp[ind][tight][last][lead];
    char l='0';
    char h='9';
    if(tight){
        h=s[ind];
    }
    int ans=0;


    for(char ch=l;ch<=h;ch++){
        
        
        if((ch-'0')==last && ch!='0') continue; // pkka prolematic
        if((ch-'0')==last && ch=='0' && lead==0) continue; // nonleading zeors
        ans+=dfs(ind+1,tight&(ch==s[ind]),(ch-'0'),lead&(ch=='0'),s);        
    }

    return dp[ind][tight][last][lead]=ans;

    

}
   
   
int32_t main(){
    cin>>low>>high;
    memset(dp,-1,sizeof(dp));

    int ans1=dfs(0,1,10,1,high);
    memset(dp,-1,sizeof(dp));
    int ans2=dfs(0,1,10,1,low);
    //cout<<ans1<<" "<<ans2<<endl;

    int ans=ans1-ans2+1;

    for(int i=1;i<(int)low.size();i++){
        if(low[i]==low[i-1]){
            ans-=1;
            break;
        }
    }

    cout<<ans;

   

    // 
    // dp[ind][tight][lastdigit]


    
   
   
 return 0;
}