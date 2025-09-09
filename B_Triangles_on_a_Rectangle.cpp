#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define dl double
#define ra0 ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define take(n) int n; cin>>n;
#define arr(a,n)  int a[n]; for(int ii=0; ii<n; ii++) cin>>a[ii];
#define vector(v,n)  vector<int>v(n); for(int ii=0; ii<n; ii++) cin>>v[ii];
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;
#define py cout<<"Yes"<<endl;
#define pn cout<<"No"<<endl;
#define ff(i,a,n) for(int i = a;i<n;i++)
#define fl(i,a,n) for(int i = n-1;i>=a;i--)
void solve(){
    take(n);take(m);
    take(i);vector(u,i);
    take(j);vector(v,j);
    take(k);vector(w,k);
    take(l);vector(x,l);

    int ans1 = max((u[i-1]-u[0])*m,(v[j-1]-v[0])*m);
    int ans2 = max((w[k-1]-u[0])*n,(x[l-1]-x[0])*n);

    cout<<max(ans1,ans2)<<endl;
 
}
int32_t main(){
ra0
take(t)
while(t--){
solve();
}
return 0;
}