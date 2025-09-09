#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int n,m;

int dp[5002][5002];


int rec(int i, int j){

    if(i==n && j==m){
        return 0;
    }


    if(i==n && j<m){
        return (m-j);
    }

    if(j==m && i<n){
        return (n-i);;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans=1e9;
     int xx=rec(i+1,j+1);

    if(s1[i]==s2[j]){

        ans=xx;
    }else{

            // rrplce

   
    ans=min(ans,xx+1);

        // remove

    ans=min(ans,rec(i+1,j)+1);

        // add

    ans=min(ans,rec(i,j+1)+1);




    }

    


    return dp[i][j]=ans;



}

   
   
int main(){
    
    cin>>s1>>s2;

    memset(dp,-1,sizeof(dp));

     n=s1.size();

     m=s2.size();

    // rem
    // add
    // replace

    int i=0;int j=0;

    cout<<rec(i,j);








    
   
   
 return 0;
}