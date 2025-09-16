#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    vector<vector<int>> v(n);
    
    for(int i=0;i<n;i++){
        int a,b,h;
        cin>>a>>b>>h;

        v[i]={b,a,h};
    }

    sort(v.begin(),v.end(),[&](const vector<int>& a,const vector<int>& b){
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    });

    // first compress everything

    vector<vector<int>> A;
    A.push_back({10000000000LL,0LL,0LL});
    int currB=v[0][0];
    int currA=v[0][1];
    int currH=v[0][2];

    for(int i=1;i<n;i++){
        if(v[i][0]!=currB){
            A.push_back({currB,currA,currH});

            currB=v[i][0];
            currA=v[i][1];
            currH=v[i][2];
        }else{
            //
            currA=min(currA,v[i][1]);
            currH+=v[i][2];
        }
    }
    A.push_back({currB,currA,currH});

    n=A.size();
    // for(int i=0;i<n;i++){
    //     cout<<A[i][0]<<" "<<A[i][1]<<"  "<<A[i][2]<<endl;

    // }


    // compression is done

    // for each i I want the index of 
    // maximum j, st a[j]<a[i];
    // then only I can extend 
    // previous smaller element


    // so I need to build a array to store index
    
    vector<int> ind(n,0); // 

    stack<int> s;

    for(int i=0;i<n;i++){

        while(!s.empty() && A[s.top()][1]>=A[i][0]){
            s.pop();
        }
        if(!s.empty()){
           ind[i]=s.top();
        }
        s.push(i);
    }
    

    // for(int i=0;i<n;i++){
    //     cout<<ind[i]<<" ";
    // } cout<<endl;


    vector<int> dp(n,0);

    // dp[0]=0; we know
    // dp[i]= max if we end at i
    int ans=0;

    for(int i=1;i<n;i++){
        int prev=ind[i];

        dp[i]=dp[prev]+A[i][2];
        ans=max(ans,dp[i]);
    }

    cout<<ans;
    






    
    
   
   
 return 0;
}