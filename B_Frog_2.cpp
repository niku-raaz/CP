#include<bits/stdc++.h>
using namespace std;

#define ll long long
   
   
int main(){
    int n,k;
    cin>>n>>k;
      vector<int> a(n);
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
    
    vector<int> v(k);
    v[0]=0;
    for(int i=1;i<k;i++){
        v[i]=abs(a[i]-a[0]);
    }

    

    
   
   
 return 0;
}