#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    int ans=0;

    vector<vector<int>> prod(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            prod[i][j]=a[i]*a[j];
            if(i!=j){
                ans=max(ans,prod[i][j]);

            }
            
            cout<<prod[i][j]<<" ";
        }
        cout<<endl;
    }
    // 





    cout<<ans;


    
   
   
 return 0;
}