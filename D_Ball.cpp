#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;

    vector<vector<int>> A(n,vector<int>(3,0));

    for(int i=0;i<n;i++){
        int x;cin>>x;
        A[i][0]=x;
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        A[i][1]=x;
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        A[i][2]=x;
    }

    // for(int i=0;i<n;i++){
    //     cout<<A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]<<endl;
    // }



    sort(A.begin(),A.end(),[&](vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    });


    for(int i=0;i<n;i++){
        cout<<A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]<<endl;
    }


    // sort it out

    vector<int> ind(n,-1);
    // previous smaller element

    stack<int> s;

    for(int i=0;i<n;i++){
        while(!s.empty() && (A[s.top()][1]>=A[i][1] || A[s.top()][2]>=A[i][2])){
            s.pop();
        }

        if(!s.empty()){
            ind[i]=s.top();
        }
        s.push(i);

        cout<<ind[i]<<" ";
    }

    cout<<endl;

    int ans=0;

    for(int i=0;i<n;i++){
        if(ind[i]!=-1){
            ans++;
        }
    }

    cout<<ans;
    
   
   
 return 0;
}