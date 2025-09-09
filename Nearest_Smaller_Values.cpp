#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }

    vector<int> pse(n+1,0);
    
    // 
    stack<int> s;
    s.push(1);

    for(int i=2;i<=n;i++){

        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
            // if elements are greater pop()

        }

        if(s.empty()){
            s.push(i);

        }else{
            pse[i]=s.top();
            s.push(i);
        }

    }


    for(int i=1;i<=n;i++){
        cout<<pse[i]<<" ";
    }

    

    
   
   
 return 0;
}