 
// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI
   
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   

#define int long long 
#define ll long long 
#define nl cout<<endl; 

#define pb push_back
#define pl cout<<endl;
#define ps cout<<" ";
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;


void solve(){
    string p,s;
    cin>>p>>s;

    if(s==p){
        pY;
        return;
    }

     
    if(s[0]!=p[0]){
        pN; return;
    }

    vector<int> a,b;


    int ct=1;

    for(int i=1;i<p.size();i++){
        if(p[i]==p[i-1]){
            ct++;
        }else{
            //
            a.pb(ct);
            ct=1;
        }

    }
    a.pb(ct);

    ct=1;

    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            ct++;
        }else{
            //
            b.pb(ct);
            ct=1;
        }

    }
    b.pb(ct);
    int n=a.size();

    if(b.size()!=n){
        pN;
        return;
    }

    for(int i=0;i<n;i++){
        if(b[i]<a[i] || b[i]>2*a[i]){
            pN;
            return;
        }
    }

    pY;

        
}
   
   
   
int32_t main(){
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }